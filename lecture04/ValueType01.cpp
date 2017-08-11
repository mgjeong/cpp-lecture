/**
 *  @file       ValueType01.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
#include <vector>
using namespace std;


void print( vector< int >& v )
{
    int n = v.front( );
    cout << n << endl;
}


int main( int argc, char* argv[] )
{
    vector< int > v( 10, 3 );
    print( v );

    return 0;
}

