/**
 *  @file       Overloading01.c
 *  @author     mg.jeong<myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;

int square ( int a )
{
    return a * a;
}

double square ( double d )
{
    return d * d;
}

int main( int argc, char* argv[] )
{
    int n = square ( 3 );
    double d = square ( 3.5 );

    cout << "square( 3 ) = " << n << endl;
    cout << "square( 3.5 ) = " << d << endl;

    return 0;
}

