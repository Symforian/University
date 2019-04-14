
#include "tree.h"

#if 0 //zad 6
tree subst( const tree& t, const string& var, const tree& val )
   {
	tree answ = new tree(t);
	if(t.functor()==var && t.nrsubtrees()==1)
		answ=val;
	else
	{
		for(size_t i=0; i<t.nrsubtrees(); i++)
		{
			answ[i]=subst(t,var,val);
		}
	}

	return answ;
   }
#endif
std::ostream& operator << ( std::ostream& stream, const tree& t )
  {
	stream<<t.functor()<<" "<<t.getaddress()<<std::endl;

	for(size_t i = 0; i<t.nrsubtrees(); i++)
	{
		stream<<t[i];
	}

	return stream;
   }
tree subst( const tree& t, const string& var, const tree& val )
   {
	if(t.functor()==var)
	{
		if(t.nrsubtrees()==0) return val;
		else
		return t;}
	else
	{
		tree answ = t;
		for(size_t i=0; i<t.nrsubtrees(); i++)
		{
			answ.replacesubtree(i,subst(t[i],var,val));
		}
		return answ;
	}

	
   }
