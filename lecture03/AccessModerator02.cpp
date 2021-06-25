/**
 *  @file       AccessModerator02.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <list>
using namespace std;


template< typename T >
class stack : private list< T >
{
public :
    inline void push( const T& a ) { this->push_back( a ); }
    inline void pop( ) { this-> pop_back( ); }
    inline T& top( ) { return this-> back( ); }
};

int main( int argc, char* argv[] )
{
    stack< int > s;
    s.push( 10 );
    s.push( 20 );

    cout << s.top( ) << endl;

    // s.push_front( 30 );
    // cout << s.top( ) << endl;

    return 0;
}

