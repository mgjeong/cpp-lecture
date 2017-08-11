/**
 *  @file       MultiInherit01.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;

class X
{
public :
    int x;
};

class A : public X
{
public :
    int a;
};

class B : public X
{
public :
    int b;
};

// Diamond inherit
class C : public A, public B
{
};


int main( int argc, char* argv[] )
{
    C c;
    //c.x = 10;       // error
    c.A::x = 10;

    return 0;
}

