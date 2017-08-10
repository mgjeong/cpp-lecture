/**
 *  @file       ReferenceReturn05.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;

template<typename T>
class Stack
{
public :
    Stack( ) : index( -1 )
    {
    }

    void push( const T& a )
    {
        buff[ ++index ] = a;
    }

    void pop( )
    {
        --index;
    }

    T& top( )
    {
        return buff[ index ];
    }

private :
    T buff[ 10 ];
    int index;
};


int main( int argc, char* argv[] )
{
    Stack< int > s;

    s.push( 10 );
    s.push( 20 );

    cout << "s.top( ) = " << s.top( ) << endl;
    
    int& r = s.top( );
    s.pop( );
    cout << "r = " << r << endl;
    cout << "s.top( ) = " << s.top( ) << endl;
    s.pop( );

    return 0;
}

