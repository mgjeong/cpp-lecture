/**
 *  @file       Virtual05.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;

class A
{
    int a;
public :
    virtual void foo( ) { cout << "A foo" << endl; }
};

class B
{
    int b;
public :
    virtual void goo( ) { cout << "B goo" << endl; }
};


int main( int argc, char* argv[] )
{
    A a;
    B* pB = reinterpret_cast< B* >( &a );
    pB->goo( );

    return 0;
}

