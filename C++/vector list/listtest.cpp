
#include "listtest.h"

#include <random>
#include <chrono>
#include <algorithm>


void listtest::sort_assign( std::list< std::string >& list)
{
	for(auto p = list.begin(); p != list.end(); ++p)
	{
		for(auto q = list.begin(); q != p; ++q)
		{
			if(*q > *p)
			{
				std::string s = *q;
				*q = *p;
				*p = s;
			}
		}
	}
}

void listtest::sort_move(std::list<std::string>& list)
{
	for(auto p = list.begin(); p != list.end(); ++p)
	{
		for(auto q = list.begin(); q != p; ++q)
		{
			if(*q > *p)
            std::swap(*q, *p);
		}
	}
}
 void listtest::sort_std( std::list< std::string > & v )
 {
     v.sort();
 }
std::list<std::string> vectToList(std::vector<std::string>& vect)
 {
     std::list< std::string> retlist;
     for(auto i : vect)
          retlist.push_back(i);
     return retlist;
};
std::ostream&
operator << ( std::ostream& stream, const std::list< std::string > & list)
{
    for(auto i : list)
        stream << i << std::endl;
	return stream;
}
