/**
 *  @file       Functor02.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;


int main( int argc, char* argv[] )
{
    modulus< int > m;
    int n = m( 10, 3 ); // 10 % 3;
    cout << n << endl;

    int x[ 10 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    //int* p = find_if( x, x+10, m );

    return 0;
}

