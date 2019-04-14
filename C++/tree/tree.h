
#ifndef TREE_INCLUDED
#define TREE_INCLUDED  1


#include <iostream>
#include <vector>
#include "string.h" 

class tree;

// struct trnode should be invisible to the user of tree. This can be 
// obtained by making it a private number of tree. 
// In this exercise, we leave it like this, because it is simpler.
// In real code, trnode should be defined inside tree.


struct trnode 
{
   string f;
   std::vector< tree > subtrees;
   
   size_t refcnt;
      // The reference counter: Counts how often this trnode is referred to.

   trnode( const string& f, const std::vector< tree > & subtrees, 
           size_t refcnt )
      : f{f},
        subtrees{ subtrees },
        refcnt{ refcnt }
   { }

   trnode( const string& f, std::vector< tree > && subtrees,
           size_t refcnt )
      : f{f},
        subtrees{ std::move( subtrees )}, 
        refcnt{ refcnt }
   { }

};


class tree
{
   trnode* pntr;

public: 
   tree( const string& f ) 
      : pntr( new trnode( f, { }, 1 ))
   { }

   tree( const string& f, const std::vector< tree > & subtrees )   
      : pntr( new trnode( f, subtrees, 1 ))
   { } 
 
   tree( const string& f, std::vector< tree > && subtrees )
      : pntr( new trnode( f, std::move( subtrees ),1 ))
   { }


   tree( const tree& t )
      : pntr{t.pntr}
   {
	t.pntr->refcnt++; 
   }
      // There is no need to write tree( tree&& t ),
      // because we cannot improve. 

   void operator = ( tree&& t )
   {
	std::swap(pntr, t.pntr);
   }
   void operator = ( const tree& t )
   {
	tree buff = tree(t);
 	*this= std::move(buff);
   }
 
   const string& functor( ) const
   {
	return pntr->f;
   }
   string& functor( )
   {
	ensure_not_shared();
	return pntr->f;
   }

   const tree& operator [ ] ( size_t i ) const
   {
//for
	return pntr->subtrees[i];
   }
   tree& operator [ ] ( size_t i )
   {
	ensure_not_shared();
	return pntr->subtrees[i];
   }
   size_t nrsubtrees( ) const
   {
	return pntr->subtrees.size();
   }
 //  size_t nrsubtrees( ) 
 //  {
//	ensure_not_shared();
//	return pntr->subtrees.size();
 //  }

   ~tree()
   {
	
	pntr->refcnt--;
	if(pntr->refcnt==0)
		delete pntr;
   }
   size_t getaddress( ) const
   {
	return reinterpret_cast< size_t > ( pntr );
   }
   void replacesubtree( size_t i, const tree& t )
   {
	if(pntr->subtrees[i].getaddress()!=t.getaddress())
	{
		if( pntr -> subtrees[i]. pntr != t. pntr )
      		{
			ensure_not_shared( );
			pntr -> subtrees[i] = t;
        	}
	}
   }
// Replace i-th subtree.
   void replacefunctor( const string& f )
   {
	if(pntr->f!=f)
	{
		ensure_not_shared();
		pntr->f=f;
	}
   }
// Replace the functor.

private: 
//public: 
   // Delete public, when the thing is tested:

   void ensure_not_shared( )
   {
	if(pntr->refcnt!=1)
	{
		pntr->refcnt--;
		pntr = new trnode( pntr->f, pntr->subtrees, 1);
	}

   }

};

std::ostream& operator << ( std::ostream& stream, const tree& t );
 
   // Doesn't need to be friend, because it uses only functor( ),
   // nrsubtrees( ) and [ ].
tree subst( const tree& t, const string& var, const tree& val );

#endif

