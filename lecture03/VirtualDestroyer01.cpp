/**
 *  @file       VirtualDestroyer01.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;


class Animal
{
public :
    ~Animal( ) {}
};

class Dog : public Animal
{
public :
    Dog( ) { cout << "Allocate resource." << endl; }
    ~Dog( ) { cout << "Release resource." << endl; }
};


int main( int argc, char* argv[] )
{
    Animal *p = new Dog;

    delete p;

    return 0;
}

