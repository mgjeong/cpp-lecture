/**
 *  @file       TypeName02.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;


class A
{
public :
    typedef int DWORD;
};

template< typename T >
void foo( T a )
{
    typename T::DWORD * p;
}


int main( int argc, char* argv[] )
{
    A a;
    foo( a );

    return 0;
}

