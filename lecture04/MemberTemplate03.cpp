/**
 *  @file       MemberTemplate03.cpp
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
    
    template< typename U > Complex( const Complex< U >& u );

    template<typename> friend class Complex;
private :
    T re;
    T im;
};


template< typename T > template< typename U >
Complex< T >::Complex( const Complex< U >& u )
    : re( u.re ), im( u.im )
{
    cout << "( " << re << ", " << im << " )" << endl;
}


int main( int argc, char* argv[] )
{
    Complex< int > c1( 1, 1 );
    Complex< int > c2( c1 );

    Complex< double > c3( c1 );

    return 0;
}

