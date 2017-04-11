/**
 *  @file       MemberFunctionPointer.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
#include <pthread.h>

using namespace std;

//------------------------------------------------------------------------
// Library provider
//------------------------------------------------------------------------
class Thread
{
public :
    void run( void ) {
        pthread_t thread;
        pthread_create( &thread, 0, _ThreadLoop, this ); // !! 
    }

    static void* _ThreadLoop( void* p )
    {
        Thread* const self = static_cast< Thread* >( p );
        self->ThreadLoop( );

        return 0;
    }

    virtual bool ThreadLoop( )
    {
        return false;
    }
};


//------------------------------------------------------------------------
// Library user
//------------------------------------------------------------------------
class MyThread : public Thread
{
public :
    virtual bool ThreadLoop( )
    {
        for( int i = 0; i < 10; i++ ) {
            cout << "My Thread: " << i << endl;
            sleep( 1 );
        }

        return true;
    }
};

int main( int argc, char* argv[ ] )
{
    int status;
    MyThread t;

    t.run( );

    cin >> status;

    return 0;
}

