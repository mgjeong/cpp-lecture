/**
 *  @file       TrivialConstructor02.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
#include <type_traits>
#include <cstring>
using namespace std;


template< typename T > struct trait_trivial_ctor { enum { value = false }; };
template< typename T > struct trait_trivial_dtor { enum { value = false }; };
template< typename T > struct trait_trivial_copy { enum { value = false }; };


#define IOTIVITY_BASIC_TYPE_TRAITS( T )                                 \
template<> struct trait_trivial_ctor< T > { enum { value = true }; };   \
template<> struct trait_trivial_dtor< T > { enum { value = true }; };   \
template<> struct trait_trivial_copy< T > { enum { value = true }; };


IOTIVITY_BASIC_TYPE_TRAITS( int )
IOTIVITY_BASIC_TYPE_TRAITS( double )
IOTIVITY_BASIC_TYPE_TRAITS( char )


struct Point
{
    int x;
    int y;
};

IOTIVITY_BASIC_TYPE_TRAITS( Point )


template< typename T >
struct traits
{
    enum { 
        IS_POINTER          = is_pointer< T >::value,
        HAS_TRIVIAL_COPY    = IS_POINTER || trait_trivial_copy< T >::value,
    };
};


template< typename T >
void copy_type( T* dst, T* src, int sz )
{
    if( !traits<T>::HAS_TRIVIAL_COPY ) {
        while( sz-- ) {
            new( dst ) T( *src );
            ++src, ++dst;
        }
    }
    else {
        memcpy( dst, src, sz );
    }
}


int main( int argc, char* argv[] )
{
    char s1[ 10 ] = "hello";
    char s2[ 10 ];

    copy_type( s2, s1, 10 );

    cout << s2 << endl;
    
    Point p1, p2;
    p1.x = 1;
    p1.y = 2;

    copy_type( &p2, &p1, sizeof( Point ) );
    cout << p2.x << ", " << p2.y << endl;

    return 0;
}

