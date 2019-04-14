
#include "rational.h"
#include "matrix.h"

int main( int argc, char* argv [ ] )
{
   rational r1( 1, 2 );
   rational r2( 1, 3 );
   rational r3( -2,7 );
   rational r4( 2, 8 );
   rational r5(-1,3);
   rational r6(2,7);
   rational r7(2,5);
   rational r8(-1,7);

   matrix m1 = { { r1, r2 }, { r3, r4 } };
   std::cout << m1 << "\n";

   matrix m2 = { { r5,r6 }, { r7, r8 } };
   std::cout << m2 << "\n";

   matrix m3 = { { r1, r2}, { r3, r4 }};

   std::cout << m1. determinant( ) << "\n";

   std::cout << m1. adjugate( ) << "\n";
   std::cout << m1. inverse( ) * m1 << "\n";

    std::cout<<"Does (m1.m2).m3=m1.(m2.m3)?\n";
    std::cout<<(m1*m2)*m3<<"="<<m1*(m2*m3)<<"\n";

    std::cout<<"Does ";
}

