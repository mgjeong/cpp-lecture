/**
 *  @file       New04.cpp
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
        cout << "Constructor" << endl;
    }

    ~Point( )
    {
        cout << "Destroyer" << endl;
    }

public :
    int x, y;
};



int main( int argc, char* argv[] )
{
    Point p( 1, 1 );
    cout << p.x << ", " << p.y << endl;

    //p.Point( 2, 2 );
    new( &p ) Point( 2, 2 );
    cout << p.x << ", " << p.y << endl;

    p.~Point( );

    Point* p2 = new Point( 3, 3 );
    cout << p2->x << ", " << p2->y << endl;

    delete p2;

    return 0;
}

