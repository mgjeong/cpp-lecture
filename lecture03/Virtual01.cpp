/**
 *  @file       Virtual01.cpp 
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;

class Base
{
public :
    virtual void Foo( ) {
        cout << "Base::Foo" << endl; 
    }

    virtual void Goo( ) {
        cout << "Base::Goo" << endl; 
    }

private:
    long x;
};

class Derived : public Base
{
public :
    virtual void Foo( ) {
        cout << "Derived::Foo" << endl;
    }
private :
    long y;
};



int main( int argc, char* argv[] )
{
    Base b;
    Derived d;


    cout << sizeof( b ) << endl;
    cout << sizeof( d ) << endl;

    Base* p = &d;
    p->Foo( );

    return 0;

}
