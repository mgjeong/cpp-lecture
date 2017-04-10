/**
 *  @file       Inline04.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;

void foo( int a ) { cout << "foo( " << a << " )" << endl; }
inline void goo( int a ) { cout << "goo( " << a << " )" << endl; }


int main( int argc, char* argv[] )
{
    foo( 1 );
    goo( 1 );

    void ( *f )( int );
    int n = 0;
    cout << "input...";
    cin >> n;
    if( n == 0 ) 
        f = &goo;
    else
        f = &foo;

    f(1);

    return 0;
}

