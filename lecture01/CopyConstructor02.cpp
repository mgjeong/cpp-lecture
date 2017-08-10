/**
 *  @file       CopyConstructor02.cpp
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
    }

    Cat( const Cat& c )
        : age( c.age )
    {
        name = new char[ strlen( c.name ) ];
        strcpy( name, c.name );
    }

    ~Cat( )
    {
        delete [] name;
    }

public :
    char* name;
    int age;
};


int main( int argc, char* argv[] )
{
    Cat c1( "neo", 10 );
    Cat c2( c1 );

    cout << c2.name << " " << c2.age << endl;

    return 0;
}

