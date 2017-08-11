/**
 *  @file       VirtualDestroyer03.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;

class RefBase
{
public :
    RefBase( ) 
        : mCount( 0 )
    {
        cout << "RefBase created." << endl;
    }

    virtual ~RefBase( )
    {
        cout << "RefBase deleted." << endl;
    }

    void incStrong( ) { ++mCount; }
    void decStrong( ) { if( --mCount <= 0 ) delete this; }

private :
    int mCount;

};

class Car : public RefBase
{
public :
    ~Car( ) { cout << "Car destroyed.." << endl; }

};


int main( int argc, char* argv[] )
{
    Car* p = new Car( );
    p->incStrong( );
    p->decStrong( );

    return 0;
}

