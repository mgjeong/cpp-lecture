/**
 *  @file       AccessModerator01.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;


class A
{
private : int x;
protected : int y;
public : int z;
};

class B : private A
{
};

class C : private A
{
};

class D : private A
{
};

int main( int argc, char* argv[] )
{
    A a;
    a.x = 0;
    a.y = 0;
    a.z = 0;

    B b;
    b.x = 0;
    b.y = 0;
    b.z = 0;

    C c;
    c.x = 0;
    c.y = 0;
    c.z = 0;

    D d;
    d.x = 0;
    d.y = 0;
    d.z = 0;

    return 0;
}

