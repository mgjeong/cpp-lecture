/**
 *  @file       Inline07.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
#include <algorithm>
using namespace std;


bool cmp1( int a, int b ) { return a < b; }
bool cmp2( int a, int b ) { return a > b; }


int main( int argc, char* argv[] )
{
    int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };

    sort( x, x+10, cmp1 );
    for( int i = 0; i < 10; i ++ )
        cout << x[i] << " ";
    cout << endl;

    sort( x, x+10, cmp2 );
    for( int i = 0; i < 10; i ++ )
        cout << x[i] << " ";
    cout << endl;

    less<int> f1;
    greater<int> f2;

    sort( x, x+10, f1 );
    for( int i = 0; i < 10; i ++ )
        cout << x[i] << " ";
    cout << endl;

    sort( x, x+10, f2 );
    for( int i = 0; i < 10; i ++ )
        cout << x[i] << " ";
    cout << endl;

    return 0;
}

