/**
 *  @file       SmartPointer06.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <memory>
using namespace std;

// g++ -o SmartPointer06 -std=c++0x SmartPointer06.cpp

int main( int argc, char* argv[] )
{
    shared_ptr< int > p1( new int( 1 ) );
    // shared_ptr< int > p2 = new int( 2 ); // Error

    shared_ptr< int > p3 = shared_ptr< int >( new int( 3 ) );

    *p1 = 2;
    *p3 = 5;

    shared_ptr< int > p4 = p1;

    cout << "*p1 = " << *p1 << endl;
    cout << "*p3 = " << *p3 << endl;
    cout << "*p4 = " << *p4 << endl;

    return 0;
}

