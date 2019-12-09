from html.parser import HTMLParser
import urllib.request
from urllib import parse
import re
from threading import Thread, Lock
import queue
from copy import deepcopy


class MyHTMLParser(HTMLParser):
    def __init__(self, url):
        self.start_url = url
        self.text = []
        self.subpages = []
        self.read = False
        self.interrupt = False
        super().__init__()

    def handle_starttag(self, tag, attrs):
        if tag == 'script' and self.read:
            self.interrupt = True
        elif tag == 'body':
            self.read = True
        elif tag == 'a':
            for (attr, val) in attrs:
                if attr == 'href':
                    url = parse.urljoin(self.start_url, val)
                    if re.match("^(?!.*pdf$)^(http|https)://", url):
                        url = url[:-1] if url.endswith('/') else url
                        self.subpages.append(url)

    def handle_endtag(self, tag):
        if tag == 'script' and self.read:
            self.interrupt = False
        elif tag == 'body':
            self.read = False

    def handle_data(self, data):
        if self.read and not self.interrupt:
            self.text.append(data)

    def get_page_words(self):
        words = re.sub(r'[^\w]', " ", ' '.join(self.text)).split()
        return [word.lower() for word in words]

    def get_subpages(self):
        return set(self.subpages)


class Indexer():
    def __init__(self, url, depth, debug=0):
        self.url = url[:-1] if url.endswith('/') else url
        self.to_visit = [set()]
        self.visited = set()
        self.debug = debug
        self.ranking = {}
        self.depth = depth
        self.lock = Lock()
        self.index_site(self.url, 0)

    def parse_site(url):
        parser = MyHTMLParser(url)
        print("Poczatek: "+url)
        fp = urllib.request.urlopen(url, timeout=15)
        mybytes = fp.read()
        mystr = mybytes.decode("utf-8")
        fp.close()
        print("Koniec: "+url)
        parser.feed(mystr)
        return (parser.get_subpages(), parser.get_page_words())

    def add_word(self, word, url, amount=1):
        self.lock.acquire()
        val = self.ranking.get(word)
        if val is None:
            self.ranking.update({word: {url: amount}})
        else:
            val = self.ranking.get(word).get(url)
            if val is None:
                self.ranking[word].update({url: amount})
            else:
                self.ranking[word].update({url: val+amount})
        self.lock.release()

    def add_words(self, words, url):
        for word in words:
            self.add_word(word, url)

    def add_dicts(self, _dict, unsafe=0):
        for word, urls in _dict.copy().items():
            for url, amount in urls.copy().items():
                if unsafe or url not in self.visited:
                    self.add_word(word, url, amount)
                    self.visited.add(url)

    def thread_result_in_que(self, q, url, depth):
        q.put(self.index_site(url, depth, 1))

    def get_thread_results(self, depth):
        que_results = queue.Queue()
        que_thread = queue.Queue()
        for site in self.to_visit[depth]:
            args = (que_results, site, depth)
            thread = Thread(target=self.thread_result_in_que, args=args)
            thread.start()
            que_thread.put(thread)
        while(not que_thread.empty()):
            que_thread.get().join()
        return que_results

    def go_deeper(self, depth):
        self.lock.acquire()
        temp = deepcopy(self.ranking.copy())
        self.lock.release()
        que_results = self.get_thread_results(depth)
        while(not que_results.empty()):
            result = que_results.get()
            if result:
                self.add_dicts(result)
        self.add_dicts(temp, 1)
        if depth < self.depth:
            self.go_deeper(depth+1)

    def use_parsed_site(self, url, depth, words, subpages, thr):
        self.add_words(words, url)
        if depth < self.depth:
            self.lock.acquire()
            temp = self.to_visit[depth+1].union(subpages)
            self.to_visit[depth+1] = temp
            self.lock.release()
            if not thr and depth < self.depth:
                self.go_deeper(depth+1)

    def index_site(self, url, depth, thr=0):
        if thr:
            self.ranking = {}
        self.lock.acquire()
        if len(self.to_visit) <= depth+1:
            self.to_visit.append(set())
        if url not in self.visited:
            self.lock.release()
            parsable = True
            if depth <= self.depth:
                try:
                    (subpages, words) = Indexer.parse_site(url)
                except Exception as e:
                    parsable = False
                    if self.debug:
                        print("Exception: "+str(e)+"\n\r"+url)
                finally:
                    if parsable:
                        self.use_parsed_site(url, depth, words, subpages, thr)
        else:
            self.lock.release()
        if thr:
            return self.ranking

    def get_ranking(self):
        for word, urls in self.ranking.items():
            sites = self.ranking[word]
            sites = sorted(sites.items(), key=lambda x: x[1], reverse=True)
            self.ranking[word] = list(map(lambda x: x[0], sites))
        return self.ranking


i = Indexer("http://www.ii.uni.wroc.pl/~marcinm/dyd/python/", 1)
# print(i.ranking.get('Python'))
ranking = i.get_ranking()
print(ranking.get('rust'))
print(ranking.get('python'))
