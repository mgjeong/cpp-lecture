/**
 *  @file       MemberFunctionPointer.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
#include <pthread.h>

using namespace std;

// Traditional thread..

void* thread_loop( void* arg )
{
    cout << "thread loop: " << (int*) arg << ", " << getpid( ) << endl;

    pthread_exit( ( void* ) 0 );
}


int main( int argc, char* argv[] )
{
    pthread_t thread;
    int status;

    cout << "main loop: " << getpid( ) << endl;

    pthread_create( &thread, NULL, &thread_loop, ( void * ) 10 );

    cout << "thread launched..." << endl;

    cin >> status;;

    return 0;
}

