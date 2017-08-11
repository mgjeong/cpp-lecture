/**
 *  @file       MultiInherit02.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;


class X
{
public :
    int x;
};

class A : virtual public X
{
public :
    int a;
};

class B : virtual public X
{
public :
    int b;
};

class C : public A, public B
{
};

int main( int argc, char* argv[] )
{
    C c;
    c.x = 10;

    return 0;
}

