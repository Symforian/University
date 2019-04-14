
#include "string.h"


char string:: operator [] ( size_t i ) const
   {
		return p[i];

   }
char& string:: operator [] ( size_t i )
   {
	return p[i];
   }

void string::operator += ( char c ) // Append character at the end.
{
	char* newp = new char[ size()+1];
      	for( size_t i = 0; i < size(); ++ i )
         	newp[i] = p[i];
	newp[size()]=c;
         delete[] p; 
         p = newp;
	 len= size()+1;
}
void string::operator += ( const string& s )
   {
	char* newp = new char[ this->len + s.size()];
      	for( size_t i = 0; i < this->len; ++ i )
         	newp[i] = this->p[i];
	for( size_t i = size(); i < size()+s.size(); ++i)
		newp[i] = s.p[i-size()];
         delete[] p; 
         p = newp;
	len= this->len + s.size();
	
   }


#if 1
// Remove the #if, when you have finished operator[]:

std::ostream& operator << ( std::ostream& out, const string& s )
{
  // for( size_t i = 0; i < s.size( ); ++ i )
    //  out << s[i];
for(char c: s)
	out<<c;
   return out; 
}
string operator + ( string s1, const string& s2 )
{
		string sum = string(s2);
			s1+=sum;
		return s1;
}
bool operator == ( const string& s1, const string& s2 )
{
	if(s1.size()!=s2.size())
	return false;
	else 
	for(size_t i=0; i<s1.size();i++)
		if(s1[i]!=s2[i])
		return false;
	return true;
}
bool operator != ( const string& s1, const string& s2 )
{
	return !(s1==s2);
}
bool operator < ( const string& s1, const string& s2 )
{
	if(s1==s2)
	return false;
	else 
	if(s1.size()<s2.size())
	return true;
	else if(s1.size()==s2.size())
	for(size_t i=0; i<s1.size();i++)
		if(s1[i]<s2[i])
		return true;
	return false;
	
}
bool operator > ( const string& s1, const string& s2 )
{
	if(s1==s2)
	return false;
	else 
	if(s1.size()>s2.size())
	return true;
	else if(s1.size()==s2.size())
	for(size_t i=0; i<s1.size();i++)
		if(s1[i]>s2[i])
		return true;
	return false;
}
bool operator <= ( const string& s1, const string& s2 )
{
		return (s1==s2)||(s1<s2);
}
bool operator >= ( const string& s1, const string& s2 )
{
		return (s1==s2)||(s1>s2);
}

#endif


