/**
 *  @file       SmartPointer14.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

class RefBase
{
    mutable int count_;
public :
    RefBase( )
        : count_( 0 )
    {
    }

    virtual ~RefBase( )
    {
    }

    void IncStrong( ) const { ++count_; }
    void DecStrong( ) const { if( --count_ <= 0 ) delete this; }
};


class Point : public RefBase
{
    int x, y;
public :
    Point( int a = 0, int b = 0 )
        : x( a ), y( b )
    {
    }

    void Print( ) const
    {
        cout << "x = " << x << ", y = " << y << endl;
    }
};


int main( int argc, char* argv[] )
{
    const Point p( 1, 2 );
    p.Print( );         // ok...
    p.IncStrong( );     // Q ? Is it acceptable ???

    return 0;
}

