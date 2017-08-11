/**
 *  @file       TrivialConstructor01.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
#include <cstdlib>
using namespace std;


class A
{
public :
    A( ) { cout << "A( ) " << endl; }
    virtual ~A( ) { }
};


class B : public A
{
public :
    B( ) { cout << "B( ) " << endl; }
    virtual ~B( ) { }
    virtual void foo( ) { cout << "foo" << endl; }
};

class C
{
public :
    C( ) { }
};


int main( int argc, char* argv[] )
{
    B* p1 = new B;
    p1->foo( );

    B* p2 = static_cast< B* >( malloc( sizeof( B ) ) );
    new( p2 ) B;
    p2->foo( );

    C c;

    return 0;
}

