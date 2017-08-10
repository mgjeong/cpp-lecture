/**
 *  @file       CopyConstructor06.cpp
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

    Cat( Cat& c )
        : name( c.name ), age( c.age )
    {
        c.name = 0;
        c.age = 0;
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

    cout << "c2 " << c2.name << " " << c2.age << endl;
    cout << "c1 " << c1.name << " " << c1.age << endl;

    return 0;
}

