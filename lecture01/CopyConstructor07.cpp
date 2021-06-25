/**
 *  @file       CopyConstructor07.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <cstring>
using namespace std;

#ifdef SUPPORT_CPP0X
#define MAKE_NON_COPYABLE( classname )                  \
    private :                                           \
        classname( const classname& ) = delete;         \
        void operator=( const classname& ) = delete;
#else /* SUPPORT_CPP0X */
#define MAKE_NON_COPYABLE( classname )                  \
    private :                                           \
        classname( const classname& );                  \
        void operator=( const classname& );
#endif /* SUPPORT_CPP0X else */


class Cat 
{
public :
    Cat( const char* n, int a )
        : age( a )
    {
        name = new char[ strlen( n ) ];
        strcpy( name, n );
    }

    ~Cat( )
    {
        delete [] name;
    }

public :
    char* name;
    int age;

private :
    Cat( const Cat& c );
    void operator=( const Cat& c );
};

class Dog
{
    MAKE_NON_COPYABLE( Dog )
public :
    Dog( )
    {
    }

    ~Dog( )
    {
    }
};


int main( int argc, char* argv[] )
{
    Cat c1( "neo", 10 );
 //   Cat c2( c1 );
    Dog d1;
 //   Dog d2( d1 );

    cout << "c1 " << c1.name << " " << c1.age << endl;

    return 0;
}

