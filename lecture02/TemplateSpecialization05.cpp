/**
 *  @file       TemplateSpecialization05.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

template< typename T >
struct trait_array
{
    enum { size = -1 };
    enum { value = false };
};


template< typename T >
void foo( const T& a )
{
    if( trait_array<T>::value )
        cout << "It is an array..." << endl;
    else
        cout << "It is not an array..." << endl;
}


int main( int argc, char* argv[] )
{
    int n = 1;
    foo( n );

    int x[10];
    foo( x );
    
    
    int y[] = { 1, 3, 5, 7, 9, 11 };
    foo( y );

    return 0;
}


