/**
 *  @file       New02.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <cstdlib>
using namespace std;


void* operator new( size_t sz )
{
    cout << "my new" << endl;
    return malloc( sz );
}


void operator delete( void* p )
{
    cout << "my delete" << endl;
    free( p );
}


void* operator new( size_t sz, char* s, int n )
{
    cout << "my new 2" << endl;
    return malloc( sz );
}


int main( int argc, char* argv[] )
{
    int* p = new int;
    delete p;

    int* p2 = new( "AAA", 3 ) int;
    delete p2;

    return 0;
}

