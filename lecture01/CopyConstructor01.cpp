/**
 *  @file       CopyConstrcutor01.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;

class Point
{
public :
    Point( ) 
        : x( 0 ), y( 0 )
    {
    }

    Point( int a, int b )
        : x( a ), y( b )
    {
    }

    Point( const Point& p )
        : x( p.x ), y( p.y )
    {
    }

public :
    int x;
    int y;
};


int main( int argc, char* argv[] )
{
    Point p1;
    Point p2( 1, 1 );
    Point p3( p2 );

    cout << "p3 = " << p3.x << ", " << p3.y << endl;

    return 0;
}

