/**
 *  @file       Int2Type01.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;


template< typename T >
struct Is_Pointer
{
    enum { value = false };
};

template< typename T >
struct Is_Pointer< T* >
{
    enum { value = true };
};

template< typename T >
T Max( T a, T b )
{
    if( Is_Pointer< T >::value )
        return *a < *b ? b : a;
    return a < b ? b : a;
}

int main( int argc, char* argv[] )
{
    int x = 10, y = 20;

    // Max( x, y ); // error.
    Max( &x, &y );

    return 0;
}

