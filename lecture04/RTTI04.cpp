/**
 *  @file       RTTI04.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
#include <string>
using namespace std;

typedef string String16;

#define DECLARE_META_INTERFACE( INTERFACE )                     \
    public :                                                    \
    static const String16 descriptor;                           \
    virtual const String16& getInterfaceDescriptor( ) const;    


#define IMPLEMENT_META_INTERFACE( INTERFACE, NAME )                 \
    const String16 INTERFACE::descriptor( NAME );                   \
    const String16& INTERFACE::getInterfaceDescriptor( ) const {    \
        return INTERFACE::descriptor;                               \
    }


class Animal
{
    DECLARE_META_INTERFACE( Animal )
};
IMPLEMENT_META_INTERFACE( Animal, "Animal" )


class Dog : public Animal
{
    DECLARE_META_INTERFACE( Dog )
};
IMPLEMENT_META_INTERFACE( Dog, "Dog" )


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

