/**
 *  @file       SmartPointer15.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

struct weakref_impl {
    int count_; // managed by sp
    int weak_;  // managed by wp
};

class RefBase
{
    weakref_impl* refs_;

public :
    RefBase( )
    {
        refs_ = new weakref_impl;
    }

    virtual ~RefBase( )
    {
    }

    void IncStrong( ) const
    {
       ++refs_->count_;
    }

    void DecStrong( ) const
    {
        if( --refs_->count_ <= 0 ) {
            delete refs_;
            delete this;
        }
    }
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

