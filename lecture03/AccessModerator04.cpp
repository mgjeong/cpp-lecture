/**
 *  @file       AccessModerator04.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <list>
#include <vector>
using namespace std;


template< typename T, typename C >
class Stack
{
public :
    inline void push( const T& a ) { st.push_back( a ); }
    inline void pop( ) { st.pop_back( ); }
    inline T& top( ) { return st.back( ); }

private :
    C st;
};

int main( int argc, char* argv[] )
{
    Stack< int, list< int > > ls;    
    Stack< int, vector< int > > vs;

    ls.push( 10 );
    vs.push( 20 );

    cout << ls.top( ) << endl;
    cout << vs.top( ) << endl;

    return 0;
}

