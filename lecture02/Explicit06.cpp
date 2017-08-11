/**
 *  @file       Explicit06.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;

class Test
{
public :
    explicit
    Test( int n = 0 )
        : value( n )
    {
    }

    operator int( ) { return value; }

private :
    int value;
};


int main( int argc, char* argv[] )
{
    Test t1( 5 );
    Test t2 = 5;

    cout << t1 << ", " << t2 << endl;

    return 0;
}

