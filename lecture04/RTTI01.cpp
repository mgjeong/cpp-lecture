/**
 *  @file       RTTI01.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
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


void foo( Animal* p )
{
    const type_info& t1 = typeid( *p );
    cout << t1.name( ) << endl;

    const type_info& t2 = typeid( Dog );
    if( t1 == t2 ) {
        cout << "p is a Dog instance. " << endl;
    }

    if ( typeid( *p ) == typeid( Dog ) ) {
        cout << "p is a Dog... " << endl;
        Dog* pd = static_cast< Dog* >( p );
        pd->color = 10;
    }
}


int main( int argc, char* argv[] )
{
    Animal a; foo( &a );
    Dog d; foo( &d );

    return 0;
}

