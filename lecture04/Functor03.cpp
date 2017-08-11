/**
 *  @file       Functor03.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;


int main( int argc, char* argv[] )
{
    modulus< int > m;
    binder2nd< modulus< int > > f( m, 2 ); // set 2nd paramete as 2 of m.

    cout << f( 3 ) << endl; // 1
    cout << f( 4 ) << endl; // 0

    int x[ 10 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int* p = find_if( x, x+10, f );
    cout << *p << endl; // 1

    return 0;
}

