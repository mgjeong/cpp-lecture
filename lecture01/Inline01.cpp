/**
 *  @file       Inline01.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

int Add1( int a, int b )
{
    return a + b;
}

inline
int Add2( int a, int b )
{
    return a + b;
}


int main( int argc, char* argv[] )
{
    int n1 = Add1( 1, 2 );
    int n2 = Add2( 1, 2 );

    return 0;
}

