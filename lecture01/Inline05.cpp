/**
 *  @file       Inline05.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

inline
void swap( int& a, int& b )
{
    int tmp = a;
    a = b;
    b = tmp;
}

struct LESS
{
    inline bool operator( )( int a, int b ) { return a < b; }
};

struct GREATER
{
    inline bool operator( )( int a, int b ) { return a > b; }
};

void sort( int* x, int n, LESS cmp )
{
    for( int i = 0; i < n; i++ ) {
        for( int j = i+1; j < n; j++ ) {
            if( cmp( x[i], x[j] ) )
                swap( x[i], x[j] );
        }
    }
}


int main( int argc, char* argv[] )
{
    int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
    LESS cmpl;

    sort( x, 10, cmpl );

    for( int i = 0; i < 10; i ++ )
        cout << x[i] << " ";
    cout << endl;

    return 0;
}

