
#include "tree.h"


int main( int argc, char* argv [ ] )
{

   tree t1( string( "a" ));
   tree t70(string ("tez a"));
   tree t2( string( "b" )); 
   tree t3 = tree( string( "f" ), { t1, t2 } ); 

   std::vector< tree > arguments = { t1, t2, t3 };
   std::cout << tree( "F", std::move( arguments )) << "\n";

   t2 = t3;
   t2 = std::move(t3);
   std::cout<<t3;
   tree drzewko( string("a"),{t70});
   std::cout<<"odkreslnik\n";
   std::cout<<drzewko<<" "<<drzewko.getaddress()<<"\n";
   tree drzewko_podmianowe("podmienione");
std::cout<<drzewko_podmianowe<<" "<<drzewko_podmianowe.getaddress()<<"\n";
   subst(drzewko,"a", drzewko_podmianowe);
   std::cout<<drzewko<<" "<<drzewko.getaddress()<<"\n";
//std::cout<<drzewko_podmianowe<<" "<<drzewko_podmianowe.getaddress()<<"\n";
   
  

   tree t4(string("123"));
   tree t5(string("456"));
   tree t6(string("789"));
   tree val(string("777"));

   string var = "789";
   string var2 = "683";


   tree t7 = tree(string("Test1"), {t4, t5, t6});
   std::cout << t7;

   tree test2 = subst(t7, var, val);
   std::cout << test2;
   tree test3 = subst(t7, var2, val);
   std::cout << test3;


   tree a(string("a"));
   tree b(string("b"));
   tree g(string("g"), {a, b});
   tree f(string("f"), {g});

   tree t456(string("o"),{t4,t5,t6});
   tree t456456(string("o"),{t456});
   tree t456456456(string("o"),{t456456});
   tree s1(string("s1"),{t4,t5,t6,t456,t456456456});
   tree quad_s1(string("Qs1"),{s1,s1,s1,s1});
   std::cout << f << std::endl;
   std::cout << subst(f, "c", val) << std::endl;
   std::cout << subst(f, "b", val) << std::endl;

   
   tree galazA(string("galazA"));
   tree galazB(string("galazB"));
   tree galazC(string("galazC"));
   tree galazAA(string("galazAA"),{galazA});
   tree rozgalazA(string("rozgalazA"),{galazA,galazA});
   tree rozgalazAB(string("rozgalazAB"),{galazA,galazB});
   tree fragdrzewaA(string("fragDrzA"),{rozgalazAB,rozgalazAB,galazC,galazAA});
   tree fragdrzewaAA(string("fragDrzAA"),{fragdrzewaA,fragdrzewaA,fragdrzewaA,galazA});
   tree pojed_gal(string("poj"),{fragdrzewaAA});
   tree kolejny_stopien(string("zbior poj"),{pojed_gal,pojed_gal});
   tree siodmy_stopien(string("7"),{kolejny_stopien,kolejny_stopien,galazA});
   tree osiem(string("to juz 8"), {siodmy_stopien,fragdrzewaA,galazA});
   tree nine(string("jeszcze jedne"), {osiem,osiem,pojed_gal});
   tree drzewo_ostateczne(string("koniec"), {nine,nine,nine,galazA,kolejny_stopien});
   std::cout<<"\nTEST\n"<<drzewo_ostateczne<<"\n";
   std::cout<<"\nTEST\n"<<subst(drzewo_ostateczne,"galazG",galazC)<<"\n";
 
return 0;  
}



