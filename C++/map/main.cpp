#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <fstream>
#include "my_map.h"
#include "my_unordmap.h"
std::vector<std::string>  readfile( std::istream& input )
{
    std::vector<std::string> vect;
    std::string word;
    char c;

    while(input.get(c))
    {
      if(isspace(c) || ispunct(c))
      {
         if(!word.empty())
         {
             vect.push_back(std::move(word));
             word.clear();
         }
      }
      else word += static_cast<char> (c);
     }

     if(!word.empty())
        vect.push_back(std::move(word));

     return vect;
}
using namespace std;





int main(int argc, char* argv [])
{
	cout << frequencytable(vector<string> {"AA", "aA", "Aa", "this", "THIS"});
	case_insensitive c;
	cout << c("a", "A") << " " << c("a", "b") << " " << c("A", "b") << "\n";
	case_insensitive_hash h;
	cout << h("xzx") << " " << h("XXX") << "\n";
	cout << h("Abc") << " " << h("abC") << "\n";
	case_insensitive_equality e;
	std::cout << e("xxx", "XXX") << "\n";
	auto M = hashed_frequencytable(vector<string> {"Aa","aa", "bb", "Cab"} );
	cout << M["aa"] << "\n";
	ifstream inputf;
	inputf.open("conf.txt",ios::in);
	std::vector<std::string> Text = readfile(inputf);
	inputf.close();
	auto freq = frequencytable(Text);
	cout << "magnus: "<<freq["magnus"]<<"\n";
	cout << "hominum: "<<freq["hominum"]<<"\n";
	cout << "memoria: "<<freq["memoria"]<<"\n";
	cout<<most_often(freq)<<"\n";
	return 0;
}
