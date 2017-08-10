/**
 *  @file       CopyConstructor04.cpp
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
        cout << "construct cat ... " << endl;
    }

    Cat( const Cat& c )
        : age( c.age ), name( c.name )
    {
        ++ref;
        cout << "copy cat ... " << ref << endl;
    }

    ~Cat( )
    {
        if( --ref == 0 ) {
            cout << "destroy cat ... " << endl;
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
    Cat c4( "bella", 5 );
    Cat c5( c4 );

    cout << "c5 " << c5.name << " " << c5.age << endl;
    cout << "c4 " << c4.name << " " << c4.age << endl;
    cout << "c3 " << c3.name << " " << c3.age << endl;
    cout << "c2 " << c2.name << " " << c2.age << endl;

    return 0;
}

