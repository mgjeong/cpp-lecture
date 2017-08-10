/**
 *  @file       ReferenceReturn03.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;

void foo( int n ) { ++n; }
void goo( int* p ) { ++(*p); }
void hoo( int& r ) { ++r; }

int main( int argc, char* argv[] )
{
    int x = 1, y = 1, z = 1;

    foo( x );
    goo( &y );
    hoo( z );

    cout << "x= " << x << endl;
    cout << "y= " << y << endl;
    cout << "z= " << z << endl;

    return 0;
}

