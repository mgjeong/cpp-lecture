/**
 *  @file       FunctionTemplate01.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

template< typename T >
void foo( T a )
{
    cout << typeid( a ).name( ) << endl;
}

template< typename T >
void goo( T& a )
{
    cout << typeid( a ).name( ) << endl;
}


int main( int argc, char* argv[] )
{
    int n = 10;
    int x[ 10 ];
    string  str = "string";

    cout << "foo..." << endl;
    foo( n );
    foo( x );
    foo( str );
    foo( "AAA" );
    foo( main );

    cout << "goo..." << endl;
    goo( n );
    goo( x );
    goo( str );
    goo( "AAA" );
    goo( main );


    return 0;
}

