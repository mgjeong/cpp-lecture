/**
 *  @file       MemberFunctionPointer01
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;

public :
    void set( int a, int b ) 
    {
        x = a;
        y = b;
    }

    static void foo( int a )
    {
        //x = a;
    }

};

int main( int argc, char* argv[] )
{
    Point p1;
    p1.set( 10, 20 );

    p1.foo( 20 );

    Point::foo( 10 );

    return 0;
}

