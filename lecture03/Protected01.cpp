/**
 *  @file       Protected01.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;


class Base
{
protected :
    Base( ) { cout << "Base( )" << endl; }
    Base( int a ) { cout << "Base( int )" << endl; }
    ~Base( ) { cout << "~Base( )" << endl; }
};

class Derived : public Base
{
public :
    Derived( ) { cout << "Derived( ) " << endl; }
    Derived( int a ) { cout << "Derived( int )" << endl; }
    ~Derived( ) { cout << "~Derived( )" << endl; }
};

int main( int argc, char* argv[] )
{
    Derived d1;
    Derived d2(1);

    return 0;
}

