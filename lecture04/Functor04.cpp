/**
 *  @file       Functor04.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

template< typename T >
binder2nd< T > Bind2nd( T t, int n )
{
    return binder2nd< T >( t, n );
}


int main( int argc, char* argv[] )
{
    modulus< int > m;
    int x[ 10 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int* p = find_if( x, x+10, Bind2nd( m, 2 ) );
    //int* p = find_if( x, x+10, bind2nd( m, 2 ) ); // already defined in C++

    cout << *p << endl; // 1

    return 0;
}

