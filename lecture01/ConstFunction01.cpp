/**
 *  @file       ConstFunction01.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;

class Point
{
public :
    Point( int a = 0, int b = 0 )
        : x( a ), y( b )
    {
    }

    void Set( int a, int b )
    {
        x = a;
        y = b;
    }

    void Print( void )
    {
        cout << "x = " << x << ", y = " << y << endl;
        x = 10;
    }

public :
    int x;
    int y;
};


int main( int argc, char* argv[] )
{
    const Point p( 1, 2 );
    // p.x = 10;         // error;
    // p.Set( 10, 20 );  // error;
    // p.Print( );       // error;

    return 0;
}

