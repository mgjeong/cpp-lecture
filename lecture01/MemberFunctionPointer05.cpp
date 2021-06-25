/*******************************************************************************
 * Copyright 2021 MJ All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *******************************************************************************/

/**
 *  @file       MemberFunctionPointer.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
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

