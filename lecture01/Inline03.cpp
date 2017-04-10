/**
 *  @file       Inline03.cpp
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

void sort( int* x, int n, bool ( *cmp )( int, int ) )
{
    for( int i = 0; i < n; i++ ) {
        for( int j = i+1; j < n; j++ ) {
            if( cmp( x[i], x[j] ) )
                swap( x[i], x[j] );
        }
    }
}

bool cmp1( int a, int b ) { return a < b; }
bool cmp2( int a, int b ) { return a > b; }


int main( int argc, char* argv[] )
{
    int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };

    sort( x, 10, cmp1 );

    for( int i = 0; i < 10; i ++ )
        cout << x[i] << " ";
    cout << endl;

    sort( x, 10, cmp2 );

    for( int i = 0; i < 10; i ++ )
        cout << x[i] << " ";
    cout << endl;

    return 0;
}

