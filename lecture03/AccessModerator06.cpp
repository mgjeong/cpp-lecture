/**
 *  @file       AccessModerator06.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
#include <stack>
#include <list>
#include <vector>
using namespace std;


int main( int argc, char* argv[] )
{
    stack< int, list< int > > ls;    
    stack< int, vector< int > > vs;
    stack< int > s;

    ls.push( 10 );
    vs.push( 20 );
    s.push( 30 );

    cout << ls.top( ) << endl;
    cout << vs.top( ) << endl;
    cout << s.top( ) << endl;

    return 0;
}

