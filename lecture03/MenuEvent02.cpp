/**
 *  @file       MenuEvent02.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>

using namespace std;

class MenuItem
{
public :
    MenuItem( int n )
        : id( n )
    {
    }

    virtual void command( ) {
        handler( );
    }

private :
    int id;
    void ( *handler )( );
};


int main( int argc, char* argv[] )
{
    MenuItem m1(11), m2(12);

    m1.command( );

    return 0;
}

