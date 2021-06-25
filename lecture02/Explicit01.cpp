/**
 *  @file       Explicit01.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
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


};


int main( int argc, char* argv[] )
{
    double d = 4.4;
    int n = d;
    
    Point p1;
    Point p2( 2, 1 );
    
    int n2 = p1; /// ???
    p2 = n; // ???

    return 0;
}

