/**
 *  @file       CodeBloat02.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;


class VectorImpl
{
    int sz;
    void* buff;

public :
    int Size( ) { return sz; }
    bool Empty( ) { return sz == 0; }
    void Push( void* item, int s ) { }
    void* Top( ) { return buff; }
};


template< typename T >
class Vector : private VectorImpl
{
public :
    int Size( ) { return VectorImpl::Size( ); }
    bool Empty( ) { return VectorImpl::Empty( ); }
    inline void Push( const T& a ) { VectorImpl::Push( &a, sizeof( T ) ); }
    inline T& Top( ) { return static_cast< T& >( *VectorImpl::Top( ) ); }
};


int main( int argc, char* argv[] )
{
    Vector< int > s1;
    Vector< double > s2;

    return 0;
}

