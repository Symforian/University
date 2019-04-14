
#include "string.h"
#include <iostream>

#include <stdexcept>
#include <vector>

// From the lecture. Not needed for the task:

void fail_often( )
{
   srand( time( NULL ));
   if( rand( ) & 1 )
      throw std::runtime_error( "i failed" );
}

void f( )
{
   string s = "this is a string";
   
   std::vector< string > vect = { "these", "are", "also", "string" };
   string more [] = {"these", "are", "even", "more", "string" };

   // fail_often( );
}

int main( int argc, char* argv [ ] )
{
   // Add more tests by yourself. Untested code = unwritten code. 

   string s;
   string s2 = "hello";
const string s4 = s2;

   s = s2;  // Assignment, not initialization.
   s = s;
   string s3="  world";
   s2+=s2;

    std::cout << "s = " << s << "\n";
    std::cout << "s2 = " << s2 << "\n";
    std::cout << s2.size()<<std::endl;
	std::cout << "Operator tests\n";
	std::cout << "s2 equal to s2\t"<<(s2==s2)<<"\n";
	std::cout << "s2 equal to s3\t"<<(s2==s3)<<"\n";
	std::cout << "s2 not equal to s2\t"<<(s2!=s2)<<"\n";
	std::cout << "s2 not equal to s3\t"<<(s2!=s3)<<"\n";
	std::cout << "s2 > s2\t"<<(s2>s2)<<"\n";
	std::cout << "s2 > s3\t"<<(s2>s3)<<"\n";
	std::cout << "s2 < s2\t"<<(s2<s2)<<"\n";
	std::cout << "s2 < s3\t"<<(s2<s3)<<"\n";
	std::cout << "s2 >= s2\t"<<(s2>=s2)<<"\n";
	std::cout << "s2 >= s3\t"<<(s2>=s3)<<"\n";
	std::cout << "s2 <= s2\t"<<(s2<=s2)<<"\n";
	std::cout << "s2 <= s3\t"<<(s2<=s3)<<"\n";
	std::cout << "s3 + s4\t"<<(s3+s4)<<"\n";
	
	

s = "this is a string";
std::cout << s << "\n";
for( char& c : s )
c = toupper(c);
std::cout << s << "\n";
}


