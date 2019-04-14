#ifndef STRING_INCLUDED 
#define STRING_INCLUDED 1

#include <stdexcept>
#include <iostream> 
#include <cstring>

class string
{
   size_t len;
   char *p; 

public: 
   string( )
      : len{0},
        p{ nullptr }   // Works, see the slides. 
   { }

   string( const char* s )
      : len{ strlen(s) },
        p{ new char[ len ] }
   {
      for( size_t i = 0; i < len; ++ i )
         p[i] = s[i]; 
   }

   string( const string& s )
      : len{ s. len },
        p{ new char[ len ] }
   {
      for( size_t i = 0; i < len; ++ i )
         p[i] = s.p[i]; 
   }
   string( const char& c)
      : len{ 1 },
        p{ new char[1] }
   {
      p[0] = c;
   }

   void operator = ( const string& s )
   { 
      if( len != s.len )
      {
         delete[] p; 
         len = s. len;
         p = new char[ len ];
      }

      for( size_t i = 0; i < len; ++ i )
         p[i] = s.p[i];
   }

   size_t size( ) const { return len; }

   ~string( )
   {
      delete[] p;
   }

   char operator [] ( size_t i ) const
   {
      if( i >= len ) throw std::runtime_error("Index out of range");
      return p[i];
   }

   char& operator [] ( size_t i )
   {
      if( i >= len ) throw std::runtime_error("Index out of range");
      return p[i];
   }

   /*void operator += ( char c ) // Append character at the end.
   {
      string new_c = c;
      return (*this)+=new_c;
      char *temp_p = new char[ len +1 ];
      
      for( size_t i = 0; i < len; ++ i )
         temp_p[i] = p[i];
      
      temp_p[ len ] = c;
      len++;
      
      delete[] p;
      p = temp_p;
   }*/

   void operator += ( const string& s )
   {
      char *temp_p = new char[ len + s.len ];
      
      size_t i = 0;
      for(; i < len; ++ i )
         temp_p[i] = p[i];
      
      for(size_t j = 0; j < s.len; ++ j )
         temp_p[j+i] = s.p[j];

      len += s.len;
      delete[] p;
      p = temp_p;
   }

   friend string operator + ( const string& s1, const string& s2 );

   using iterator = char* ;
   using const_iterator = const char* ;
   const_iterator begin( ) const { return p; }
   const_iterator end( ) const { return p + len; }
   iterator begin( ) { return p; }
   iterator end( ) { return p + len; }

};

std::ostream& operator << ( std::ostream& out, const string& s );
bool operator == ( const string& s1, const string& s2 );
bool operator != ( const string& s1, const string& s2 );
bool operator < ( const string& s1, const string& s2 );
bool operator > ( const string& s1, const string& s2 );
bool operator <= ( const string& s1, const string& s2 );
bool operator >= ( const string& s1, const string& s2 );

#endif
