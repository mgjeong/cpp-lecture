/**
 *  @file       TypeName01.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;


class A
{
public :
    static int DWORD;
};

static int p = 1;

template< typename T >
void foo( T a )
{
    T::DWORD * p;
}


int main( int argc, char* argv[] )
{
    A a;
    foo( a );

    return 0;
}

