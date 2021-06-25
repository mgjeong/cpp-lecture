/**
 *  @file       TemplateSpecialization03.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

template< typename T >
T Max( T a, T b )
{
    if ( T is Pointer )
        return *a < *b ? b : a;
    return a < b ? b : a;
}



int main( int argc, char* argv[] )
{
    int x = 10, y = 20;
    Max( x, y );
    Max( &x, &y );

    return 0;
}

