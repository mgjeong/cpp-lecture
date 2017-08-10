/**
 *  @file       ConstFunction05.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
#include <cstdio>
using namespace std;

struct Cache
{
    char data[32];
    bool valid;
};

class Point
{
public :
    Point( int a = 0, int b = 0 )
        : x( a ), y( b )
    {
        pCache = new Cache;
        pCache->valid = false;
    }

    ~Point( )
    {
        delete pCache;
    }

    const char* toString( void ) const
    {
        if( pCache->valid == false ) {
            sprintf( pCache->data, "%d, %d", x, y );
            pCache->valid = true;
        }
        return pCache->data;
    }

    void Set( int a, int b )
    {
        x = a;
        y = b;
        pCache->valid = false;
    }

private :
    int x;
    int y;
    Cache* pCache;
};


int main( int argc, char* argv[] )
{
    Point p( 1, 2 );

    cout << p.toString( ) << endl;
    cout << p.toString( ) << endl;
    
    p.Set( 10, 20 );
    
    cout << p.toString( ) << endl;

    return 0;
}

