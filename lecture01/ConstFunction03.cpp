/**
 *  @file       ConstFunction03.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <stdio.h>
using namespace std;

class Point
{
public :
    Point( int a = 0, int b = 0 )
        : x( a ), y( b ), cache_valid( false )
    {
    }

    // 객체를 문자열로 바꾸어 주는 함수
    // java, C#에는 모든 클래스에 대하여 toString() 을 이미 지원
    const char* toString( ) const
    {
        if( cache_valid == false ) {
            sprintf( cache, "%d, %d", x, y );  // error !!
            cache_valid = true; // error !!
        }
        return cache;
    }

private :
    int x, y;
    char cache[32];
    bool cache_valid;
};

int main( )
{
    Point p( 1, 2 );
    cout << p.toString( ) << endl;

    return 0;
}

