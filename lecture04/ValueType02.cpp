/**
 *  @file       ValueType02.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
#include <vector>
using namespace std;

template< typename T >
void print( vector< T >& v )
{
    T n = v.front( );
    cout << n << endl;
}



int main( int argc, char* argv[] )
{
    vector< int > v( 10, 3 );
    print( v );

    vector< double > dv( 10, 2.5 );
    print( dv );

    return 0;
}

