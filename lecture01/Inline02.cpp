/**
 *  @file       Inline02.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
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

void sort( int* x, int n )
{
    for( int i = 0; i < n; i++ ) {
        for( int j = i+1; j < n; j++ ) {
            if( x[i] > x[j] )
                swap( x[i], x[j] );
        }
    }
}


int main( int argc, char* argv[] )
{
    int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };

    sort( x, 10 );

    for( int i = 0; i < 10; i ++ )
        cout << x[i] << " ";
    cout << endl;

    return 0;
}

