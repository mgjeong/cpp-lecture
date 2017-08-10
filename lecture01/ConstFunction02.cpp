/**
 *  @file       ConstFunction02.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;

class Rect
{
public :
    int GetArea( ) const { return w * h; }

private :
    int x, y, w, h;
};

void foo( const Rect& r )
{
    int n = r.GetArea( );
}


int main( int argc, char* argv[] )
{
    Rect r;

    int n = r.GetArea( );

    foo( r );

    return 0;
}

