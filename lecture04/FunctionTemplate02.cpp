/**
 *  @file       FunctionTemplate02.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
#include <typeinfo>
using namespace std;

template< typename T >
void foo( const T a, const T b )
{
    cout << a << " + " << b << endl;
}

template< typename T >
void goo( const T& a, const T& b )
{
    cout << a << " + " << b << endl;
}

void hoo( const char* s1, const char* s2 )
{
    cout << s1 << " + " << s2 << endl;
}

void moo( const char s1[ ], const char s2[ ] )
{
    cout << s1 << " + " << s2 << endl;
}


int main( int argc, char* argv[] )
{
    foo( "orange", "kiwi" );
    goo( "orange", "kiwi" ); // error
    hoo( "orange", "kiwi" );
    moo( "orange", "kiwi" );

    return 0;
}

