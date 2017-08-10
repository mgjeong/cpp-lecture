/**
 *  @file       CopyConstructor03.cpp
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
        ref = 1;
    }

    Cat( const Cat& c )
        : age( c.age ), name( c.name )
    {
        ++ref;
    }

    ~Cat( )
    {
        if( --ref == 0 ) {
            delete [] name;
        }

    }

public :
    char* name;
    int age;
    static int ref;
};

int Cat::ref = 0;

int main( int argc, char* argv[] )
{
    Cat c1( "neo", 10 );
    Cat c2( c1 );
    Cat c3( c2 );

    cout << "c3 " << c3.name << " " << c3.age << endl;
    cout << "c2 " << c2.name << " " << c2.age << endl;

    return 0;
}

