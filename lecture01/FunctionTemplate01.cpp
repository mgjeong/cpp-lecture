/**
 *  @file       FunctionTemplate01.cpp
 *  @authro     mg.jeong<mg.jeong@gmail.com>
 */


#include <iostream>
using namespace std;

int Max( int a, int b )
{
    return a < b ? b : a;
}


double Max( double a, double b )
{
    return a < b ? b : a;
}


int main( int argc, char* argv[] )
{
    int n = Max( 1, 2 );
    double d = Max( 3.1, 4.5 );
    
    cout << "Max( 1, 2 ) = " << n << endl;
    cout << "Max( 3.1, 4.5 ) = " << d << endl;

    return 0;
}


