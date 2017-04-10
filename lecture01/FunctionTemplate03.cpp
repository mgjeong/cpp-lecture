/**
 *  @file       FunctionTemplate03.cpp
 *  @authro     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;

template<typename T>
T Max( T a, T b )   { return a > b ? a : b; }


int main( int argc, char* argv[] )
{
    int n = Max( 1, 2 );
    double d = Max( 3.1, 4.5 );

    cout << "Max( 1, 2 ) = " << n << endl;
    cout << "Max( 3.1, 4.5 ) = " << d << endl;

    //===== quiz.. 
    short s1=5, s2=2;
    cout << "Max( s1, s2 ) = " << Max( s1, s2 ) << endl;

    cout << "Max<int>( s1, s2 ) = " << Max<int>( s1, s2 ) << endl;

    return 0;
}

