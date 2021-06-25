/**
 *  @file       RTTI02.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <typeinfo>
using namespace std;

class Animal
{
public :
    virtual ~Animal( )
    {
    }
};

class Dog : public Animal
{
public :
    int color;
};

class Cat: public Animal
{
public :
    int color;
};

void foo( Animal* p )
{
    Dog* pd = dynamic_cast< Dog* >( p );
    cout << pd << endl;

    if( pd ) {
        cout << "p is a Dog." << endl;
        pd->color = 10;
    }
}


int main( int argc, char* argv[] )
{
    Animal a; foo( &a );
    Dog d; foo( &d );
    Cat c; foo( &c );

    return 0;
}

