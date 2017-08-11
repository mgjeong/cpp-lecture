/**
 *  @file       MemberTemplate02.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;


template< typename T >
class Complex
{
public :
    Complex( T a = T( ), T b = T( ) )
        : re( a ), im( b )
    {
        cout << "( " << re << ", " << im << " )" << endl;
    }

private :
    T re;
    T im;
};


int main( int argc, char* argv[] )
{
    Complex< int > c1( 1, 1 );
    Complex< double > c2;

    return 0;
}

