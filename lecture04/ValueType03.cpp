/**
 *  @file       ValueType03.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
#include <vector>
#include <list>
using namespace std;

template< typename T >
void print( T& v )
{
    typename T::value_type n = v.front( );
    cout << n << endl;
}



int main( int argc, char* argv[] )
{
    vector< int > v( 10, 3 );
    print( v );

    vector< double > dv( 10, 2.5 );
    print( dv );

    list< double > dl( 10, 2.4 );
    print( dl );

    return 0;
}

