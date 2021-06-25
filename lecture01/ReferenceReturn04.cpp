/**
 *  @file       ReferenceReturn04.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

struct Data {
    int buf[ 1000 ];
};


void foo( Data a )
{
}

int main( int argc, char* argv[] )
{
    Data x;

    foo( x );
    
    return 0;
}

