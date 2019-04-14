#pragma once
#include <string>
#include <map>
#include <vector>

struct case_insensitive 
{
	bool operator( ) ( const std::string& s1, const std::string& s2 ) const
	{
		auto p2 = s2.begin();

		for(auto p1 = s1.begin(); p1 != s1.end(); ++p1)
		{
			if(p2 == s2.end())
				return false;
			if(tolower(*p1) < tolower(*p2)) 
				return true;
			if(tolower(*p1) > tolower(*p2)) 
				return false;
			p2++;
		}

		if(p2 != s2.end()) return true;
		return false;
	}
};

std::map<std::string, unsigned int, case_insensitive> frequencytable (const std::vector<std::string> &text)
{
	std::map<std::string, unsigned int, case_insensitive > mapa;
	for( auto i = text.begin(); i != text.end(); ++i ) mapa[*i]++;
	return mapa;
}

std::string most_often(std::map<std::string, unsigned int, case_insensitive >  mapa)
{
		std::pair<std::string, unsigned int> max;
		for( auto i: mapa)
			if(i.second>max.second)
				max=i;
		std::cout<<max.second<<" max times \n";
		return max.first;
}	

std::ostream& operator << ( std::ostream& stream, const std::map< std::string, unsigned int, case_insensitive> &freq )
{
	for ( const auto &p : freq ) stream  << p.first << '\t' << p.second << "\n";
	return stream;
}

