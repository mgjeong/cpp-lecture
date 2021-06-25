/**
 *  @file       Functor01.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;


bool foo( int a )
{
    return a % 2 == 0;
}

struct IsEven
{
    inline bool operator( )( int a ) { return a % 2 == 0; }
};


int main( int argc, char* argv[] )
{
    int x[ 10 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int* p = find( x, x+10, 3 );
    cout << *p << endl;

    int* p2 = find_if( x, x+10, foo );
    cout << *p2 << endl;

    // using inlining with functor.
    IsEven even;
    int* p3 = find_if( x, x+10, even );
    cout << *p3 << endl;

    return 0;
}

