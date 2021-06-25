/**
 *  @file       Int2Type02.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

template< int N >
struct int2type
{
    enum { value = N };
};

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
T MaxImpl( T a, T b, int2type< 1 > type1 )
{
    cout << "Pointer case : " << type1.value << endl;
    return *a < *b ? b : a;
}

template< typename T >
T MaxImpl( T a, T b, int2type< 0 > type0 )
{
    cout << "Not pointer case : " << type0.value << endl;
    return a < b ? b : a;
}

template< typename T > 
T Max( T a, T b )
{
    return MaxImpl( a, b, int2type< Is_Pointer< T > :: value >( ) );
}

int main( int argc, char* argv[] )
{
    int x = 10, y = 20;
    int r1, r2;

    r1 = Max( x, y ); 
    r2 = *Max( &x, &y );

    cout << r1 << endl;
    cout << r2 << endl;

    return 0;
}

