/**
 *  @file       TemplateSpecialization04.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

template< typename T >
struct trait_pointer
{
    enum {
        value = false,
    };
};

template< typename T >
struct trait_pointer< T* >
{
    enum {
        value = true,
    };
};

template< typename T >
void foo( const T& p )
{
    if( trait_pointer<T>::value )
        cout << "It is a pointer..." << endl;
    else
        cout << "It is not a pointer..." << endl;
}


int main( int argc, char* argv[] )
{
    int x = 0;
    foo( x );
    foo( &x );

    return 0;
}

