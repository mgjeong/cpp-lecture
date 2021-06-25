/**
 *  @file       FunctionBinding02.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

class Animal
{
public :
    virtual void Cry( void ) 
    {
        cout << "Animal Cry.." << endl;
    }
};

class Dog : public Animal
{
public :
    void Cry( void )
    {
        cout << "Dog Cry.." << endl;
    }
};

int main( int argc, char* argv[] )
{
    Animal a; a.Cry( );
    Dog d; d.Cry( );


    int n = 0;
    cout << "select.. ";
    cin >> n;

    Animal* p;
    if( n == 0 ) p = &d;
    else         p = &a;

    p->Cry( );

    return 0;
}

