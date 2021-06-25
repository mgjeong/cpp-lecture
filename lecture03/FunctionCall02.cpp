/**
 *  @file       FunctionCall02.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

class A
{
public :
    virtual void foo( int a = 10 ) { cout << "A : " << a << endl; }
};

class B : public A
{
public :
    virtual void foo( int a = 20 ) { cout << "B : " << a << endl; }
};

int main( )
{
    A* p = new B;
    p->foo( ); // ???
}

