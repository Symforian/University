
#include <fstream>
#include <iostream>
#include <random>

#include "listtest.h"
#include "vectortest.h"
#include "timer.h"

void sortTest(std::vector< std::string> vector_s, int index)
{
	if(index==1)
	{
	timer t("Vector sort_assign",std::cout);
	vectortest::sort_assign(vector_s);
	}
	if(index==2)
	{
	timer t("Vector sort_move",std::cout);
	vectortest:: sort_move(vector_s);
	}
	if(index==3)
	{
	timer t("Vector sort_std",std::cout);
	vectortest::sort_std(vector_s);
	}
}
void sortListTest(std::list< std::string> list_s, int index)
{
	if(index==1)
	{
	timer t("List sort_assign",std::cout);
	listtest::sort_assign(list_s);
	}
	if(index==2)
	{
	timer t("List sort_move",std::cout);
	listtest:: sort_move(list_s);
	}

}
int main( int argc, char* argv [] )
{

   //std::vector< std::string > vect;

   //std::cout << vect << "\n";

   // Or use timer:

   //auto t1 = std::chrono::high_resolution_clock::now( ); 
   //vectortest::sort_move( vect );
   //auto t2 = std::chrono::high_resolution_clock::now( );

   //std::chrono::duration< double > d = ( t2 - t1 );
   std::vector< std::string> testa = vectortest::randomstrings(5555,5555);
   std::vector< std::string> testb = vectortest::randomstrings(4444,4444);
   std::vector< std::string> testc = vectortest::randomstrings(3333,3333);
   std::list<std::string> testLa = vectToList(testa);
   std::list<std::string> testLb = vectToList(testb);
   std::list<std::string> testLc = vectToList(testc);
   std::cout<<"Test A:\n";
   sortTest(testa,1);
   sortTest(testa,2);
   sortTest(testa,3);
   sortListTest(testLa,1);
   sortListTest(testLa,2);
   std::cout<<"Test B:\n";
   sortTest(testb,1);
   sortTest(testb,2);
   sortTest(testb,3);
   sortListTest(testLb,1);
   sortListTest(testLb,2);
   std::cout<<"Test C:\n";
   sortTest(testc,1);
   sortTest(testc,2);
   sortTest(testc,3);
   sortListTest(testLc,1);
   sortListTest(testLc,2);

   return 0;
}


