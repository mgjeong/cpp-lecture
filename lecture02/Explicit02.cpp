/**
 *  @file       Explicit02.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;

class Point
{
    int x, y;

public :
    Point( )
        : x( 0 ), y( 0 )
    {
    }

    Point( int a, int b )
        : x( a ), y( b )
    {
    }

    Point( int a )
        : x( a ), y( 0 )
    {
    }

    operator int( ) { return x; }

};


int main( int argc, char* argv[] )
{
    double d = 4.4;
    int n = d;
    
    Point p1;
    Point p( 2, 1 );

    int n2 = p; /// ???
    cout << "n2 = " << n2 << endl;

    p = n; // ???
    cout << "p = " << p << endl;

    return 0;
}

