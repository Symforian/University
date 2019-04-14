#include "rational.h"

// Complete these methods:

////#ifndef RATIONAL_ARITHM
//#//define RATIONAL_ARITHM

int rational::gcd( int n1, int n2 )
{
    int buff;
    if(n1>=n2) {}
    else
    {
        buff=n1;
        n1=n2;
        n2=buff;
    }
    while(n2!=0)
    {
        buff=n1;
        n1=n2;
        n2=buff%n2;
    }
    return n1;
}



void rational::normalize( )
{
    if(denum==0)
    {
        throw std::runtime_error( "division by zero");
    }
    int sign;
    int buff_gcd;
    if((num<0 && denum>0) || (num>0 && denum<0))
    {
        sign=-1;
        if(num<0)
            num=-num;
        else if(denum<0)
            denum=-denum;

    }
    else if(denum>0 && num>=0)
        sign=1;


        buff_gcd=gcd(num,denum);
        num/=buff_gcd;
        denum/=buff_gcd;

        if(sign==-1)
        num=-num;



}

rational operator - ( rational r )
{
    r.num=- r.num;
    return r;
}

rational operator + ( const rational& r1, const rational& r2 )
{
    rational add_rational(r1.num*r2.denum+r1.denum*r2.num,r1.denum*r2.denum);
    add_rational.normalize();
    return add_rational;
}

rational operator - ( const rational& r1, const rational& r2 )
{
    rational sub_rational(r1.num*r2.denum-r2.num*r1.denum,r1.denum*r2.denum);
    sub_rational.normalize();
    return sub_rational;
}

rational operator * ( const rational& r1, const rational& r2 )
{
    rational mult_rational(r1.num*r2.num,r1.denum*r2.denum);
    mult_rational.normalize();
    return mult_rational;
}

rational operator / ( const rational& r1, const rational& r2 )
{
    rational div_rational(r1.num*r2.denum,r2.num*r1.denum);
    div_rational.normalize();
    return div_rational;
}

bool operator == ( const rational& r1, const rational& r2 )
{

    if(r1.num==r2.num && r1.denum==r2.denum)
    return true;
    else return false;
}
bool operator != ( const rational& r1, const rational& r2 )
{

if(r1.num==r2.num && r1.denum==r2.denum)
    return false;
    else
    return true;

}

std::ostream& operator << ( std::ostream& stream, const rational& r )
{
 stream<<r.num<<"/"<<r.denum;
 return stream;
}

//#endif

