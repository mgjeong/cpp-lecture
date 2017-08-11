/**
 *  @file       Int2Type04.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
#include <type_traits>
using namespace std;


template< typename T > 
T MaxImpl( T a, T b, true_type )
{
    cout << "Pointer case." << endl;
    return *a < *b ? b : a;
}

template< typename T >
T MaxImpl( T a, T b, false_type )
{
    cout << "Not pointer calse" << endl;
    return a < b ? b : a;
}

template< typename T >
T Max( T a, T b )
{
    return MaxImpl( a, b, is_pointer< T >( ) );
}


int main( int argc, char* argv[] )
{
    int a = 10, b = 20;
    int r1, r2;

    r1 = Max( a, b );
    r2 = *Max( &a, &b );

    cout << r1 << endl;
    cout << r2 << endl;

    return 0;
}

