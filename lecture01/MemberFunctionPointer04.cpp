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

