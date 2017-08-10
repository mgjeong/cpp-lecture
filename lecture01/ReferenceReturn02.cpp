/**
 *  @file       ReferenceReturn02.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;


struct Point {
    int x;
    int y;
};

Point p = { 1, 2 };


Point& foo( )
{
    return p;
}


int main( int argc, char* argv[] )
{
    foo().x = 10;

    cout << "p.x = " << p.x << endl;

    return 0;
}

