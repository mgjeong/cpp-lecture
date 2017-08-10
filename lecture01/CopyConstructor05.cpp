/**
 *  @file       CopyConstructor05.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
#include <cstring>
using namespace std;

class Cat 
{
public :
    Cat( const char* n, int a )
        : age( a )
    {
        name = new char[ strlen( n ) ];
        strcpy( name, n );
        ref = new int(1); // initialized by 1
    }

    Cat( const Cat& c )
        : age( c.age ), name( c.name ), ref( c.ref )
    {
        ++(*ref);
    }

    ~Cat( )
    {
        if( --(*ref) == 0 ) {
            delete [] name;
            delete ref;
        }

    }

public :
    char* name;
    int age;
    int* ref;
};


int main( int argc, char* argv[] )
{
    Cat c1( "neo", 10 );
    Cat c2( c1 );
    Cat c3( "bella", 5 );
    Cat c4( c3 );

    cout << "c4 " << c4.name << " " << c4.age << endl;
    cout << "c2 " << c2.name << " " << c2.age << endl;

    return 0;
}

