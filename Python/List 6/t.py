from html.parser import HTMLParser
import urllib.request
import socket
from urllib import parse
import re


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
    def __init__(self, url, depth):
        self.url = url[:-1] if url.endswith('/') else url
        self.visited = set()
        self.to_visit = [[]]
        self.ranking = {}
        self.depth = depth
        self.index_site(self.url, 0)

    def parse_site(self, url):
        self.parser = MyHTMLParser(url)
        fp = urllib.request.urlopen(url, timeout=10)
        mybytes = fp.read()
        mystr = mybytes.decode("utf-8")
        fp.close()
        self.parser.feed(mystr)

    def index_site(self, url, depth):
        if len(self.to_visit) <= depth:
            self.to_visit.append([])
        if url not in self.visited:
            parsable = True
            # print(url+" "+str(depth))
            if depth <= self.depth:
                try:
                    self.parse_site(url)
                except UnicodeDecodeError:
                    print("Couldn't parse: "+url)
                    parsable = False
                except urllib.error.URLError:
                    print("Timeout: "+url)
                    parsable = False
                except socket.timeout:
                    parsable = False
                    print("Timeout socket: "+url)
                except socket.error:
                    parsable = False
                    print("Error socket: "+url)
                except Exception as e:
                    parsable = False
                    print("Exception: "+str(e)+"\n\r"+url)
                finally:
                    self.visited.add(url)
                if parsable:
                    words = self.parser.get_page_words()
                    for word in words:
                        val = self.ranking.get(word)
                        if val is None:
                            self.ranking.update({word: {url: 1}})
                        else:
                            val = self.ranking.get(word).get(url)
                            if val is None:
                                self.ranking[word].update({url: 1})
                            else:
                                self.ranking[word].update({url: val+1})
                    if depth < self.depth:
                        subpages = self.parser.get_subpages()
                        self.to_visit[depth].append(subpages)
                        for sites in self.to_visit[depth]:
                            for site in sites:
                                new_ranking = self.index_site(site, depth+1)
                                if new_ranking is not None:
                                    self.ranking = new_ranking.ranking

    def get_ranking(self):
        for word, urls in self.ranking.items():
            sites = self.ranking[word]
            sites = sorted(sites.items(), key=lambda x: x[1], reverse=True)
            self.ranking[word] = list(map(lambda x: x[0], sites))
        return self.ranking


i = Indexer("http://www.ii.uni.wroc.pl/~marcinm/dyd/python/", 1)
# print(i.parser.get_page_words())
# print(i.parser.get_subpages())
# print(i.ranking.get('Python'))
print(i.get_ranking().get('rust'))
