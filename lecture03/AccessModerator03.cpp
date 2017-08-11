/**
 *  @file       AccessModerator03.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
#include <list>
using namespace std;


template< typename T >
class Stack
{
public :
    inline void push( const T& a ) { l.push_back( a ); }
    inline void pop( ) { l.pop_back( ); }
    inline T& top( ) { return l.back( ); }

private :
    list< T > l;
};

int main( int argc, char* argv[] )
{
    Stack< int > s;
    s.push( 10 );
    s.push( 20 );

    cout << s.top( ) << endl;
    cout << s.top( ) << endl;

    return 0;
}

