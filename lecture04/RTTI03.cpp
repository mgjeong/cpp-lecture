/**
 *  @file       RTTI03.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
#include <string>
using namespace std;

typedef string String16;


class Animal
{
public :
    virtual ~Animal( ) { }
    static const String16 descriptor;   // role of type_info
    virtual const String16& getInterfaceDescriptor( ) const // role of typeid( )
    {
        return descriptor;
    }
};
const String16 Animal::descriptor( "Animal" );


class Dog : public Animal
{
public :
    virtual ~Dog( ) { }
    static const String16 descriptor;   // role of type_info
    virtual const String16& getInterfaceDescriptor( ) const // role of typeid( )
    {
        return descriptor;
    }
};
const String16 Dog::descriptor( "Dog" );

void foo( Animal* p )
{
    if( p->getInterfaceDescriptor( ) == Dog::descriptor ) {
        cout << "p is a Dog.." << endl;
    }
}

int main( int argc, char* argv[] )
{
    cout << "Animal inspection." << endl;
    Animal a; foo( &a );

    cout << "Dog inspection." << endl;
    Dog d; foo( &d );

    return 0;
}

