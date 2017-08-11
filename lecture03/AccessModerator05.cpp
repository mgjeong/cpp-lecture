/**
 *  @file       AccessModerator05.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
#include <list>
#include <vector>
#include <deque>
using namespace std;


template< typename T, typename C = deque< T > >
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
    Stack< int > s;

    ls.push( 10 );
    vs.push( 20 );
    s.push( 30 );

    cout << ls.top( ) << endl;
    cout << vs.top( ) << endl;
    cout << s.top( ) << endl;

    return 0;
}

