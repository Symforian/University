#include "string.h"

#if 1
// Remove the #if, when you have finished operator[]:

std::ostream& operator << ( std::ostream& out, const string& s )
{
   for( const char& c : s )
         out << c;
   return out; 
}

#endif


string operator + ( const string& s1, const string& s2 ){
   string new_string;
   new_string += s1;
   new_string += s2;
   return new_string;
}

bool operator == ( const string& s1, const string& s2 )
{  
   return !(s1!=s2);
}

bool operator != ( const string& s1, const string& s2 )
{
   if( s1.size() != s2.size() ) return true;
   
   size_t i = 0;
   for( const char& c : s1 )
      if( c != s2[i++] ) return true;

   return false;
}

bool operator < ( const string& s1, const string& s2 )
{

   size_t i =0;
   for( const char& c : s1 )
   {
      if( c < s2[i] ) return true;
      if( c > s2[i++] || i==s2.size() ) return false;
   }

   return false;
}

bool operator > ( const string& s1, const string& s2 )
{
   return ( s2 < s1 );
}

bool operator <= ( const string& s1, const string& s2 )
{
   return !( s1 < s2);
}

bool operator >= ( const string& s1, const string& s2 )
{
   return !( s2 < s1 );
}
