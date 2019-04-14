#pragma once

#include <unordered_map>
#include <string>
#include <vector>
#include "my_map.h"

struct case_insensitive_equality
{
	bool operator( ) ( const std::string& s1, const std::string& s2 ) const
	{
		case_insensitive c;
		return !c(s1,s2) && !c(s2,s1);
	}
};


struct case_insensitive_hash
{
	size_t operator () ( const std::string& s) const
	{
		size_t w = 0;
		
		for(size_t i = 0; i < s.size(); i++)
		{
			w = (w * 13)%1000000007 + (tolower(s[i]) - 'a' + 1);
			w %= 1000000007;
		}

		return w;
	}
};

std::unordered_map<std::string, unsigned int, case_insensitive_hash, case_insensitive_equality >  hashed_frequencytable( const std::vector<std::string > & text )
{
	std::unordered_map<std::string, unsigned int, case_insensitive_hash, case_insensitive_equality > mapa;
	for( auto i = text.begin(); i != text.end(); ++i ) mapa[*i]++;
	return mapa;
}

std::string most_often(std::unordered_map<std::string, unsigned int, case_insensitive_hash, case_insensitive_equality >  mapa)
{
		std::pair<std::string, unsigned int> max;
		for( auto i: mapa)
			if(i.second>max.second)
				max=i;
		std::cout<<max.second<<" max times \n";
		return max.first;
}	

