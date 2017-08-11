/**
 *  @file       ClassTemplate01.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;

// Stack vs. Stack< T >

template< typename T >
class Stack
{
    T* buff;
public :
    Stack( ) { }        // okay
    //Stack< T >( ) {  }  // error

    //Stack( const Stack& s ) { }         // error, but acceptable
    Stack( const Stack< T >& s ) { }    // okay

    void push( const T& a );

    template< typename U > T foo( U a );
};

template< typename T >
void Stack< T >::push( const T& a )
{
}


template< typename T > template< typename U >
T Stack< T >::foo( U a )
{
    cout << "foo( U a ) = " <<  a << endl;
}



int main( int argc, char* argv[] )
{
    Stack< int > s1;
//    Stack        s2;
    Stack< int >  s3( s1 );


    s1.foo( 5.2f ); 

    return 0;
}

