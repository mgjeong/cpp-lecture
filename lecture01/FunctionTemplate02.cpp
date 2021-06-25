/**
 *  @file       FunctionTemplate02.cpp
 *  @author     mg.jeong<mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

#define MAKE_MAX( T )   \
   T    Max( T a, T b ) { return a > b ? a : b; }

MAKE_MAX( int )
MAKE_MAX( double )

int main( int argc, char* argv[] )
{
    int n = Max( 1, 2 );
    double d = Max( 3.1, 4.5 );

    cout << "Max( 1, 2 ) = " << n << endl;
    cout << "Max( 3.1, 4.5 ) = " << d << endl;

    return 0;
}

