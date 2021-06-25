/**
 *  @file       Upcasting01.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Animal
{
public :
    void Cry( void )
    {
        cout << "Animal Cry..." << endl;
    }
};


class Dog : public Animal
{
};


void foo( Animal* p )
{
    p->Cry( );
}

int main( int argc, char* argv[] )
{
    vector< Animal * > av;
    vector< Dog * > dv;

    Animal a;   foo( &a );
    Dog d;      foo( &d );

    return 0;
}

