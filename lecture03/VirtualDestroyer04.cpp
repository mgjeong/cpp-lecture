/**
 *  @file       VirtualDestroyer04.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;

template< typename T >
class LightRefBase
{
public :
    LightRefBase( ) 
        : mCount( 0 )
    {
        cout << "LightRefBase created." << endl;
    }

    ~LightRefBase( )
    {
        cout << "LightRefBase deleted." << endl;
    }

    void incStrong( ) { ++mCount; }
    void decStrong( ) {
        if( --mCount <= 0 )
            delete static_cast< T* >( this ); 
    }

private :
    int mCount;

};

class Car : public LightRefBase< Car >
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

