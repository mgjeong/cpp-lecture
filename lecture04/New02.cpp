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
 *  @file       New02.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <cstdlib>
using namespace std;


void* operator new( size_t sz )
{
    cout << "my new" << endl;
    return malloc( sz );
}


void operator delete( void* p )
{
    cout << "my delete" << endl;
    free( p );
}


void* operator new( size_t sz, char* s, int n )
{
    cout << "my new 2" << endl;
    return malloc( sz );
}


int main( int argc, char* argv[] )
{
    int* p = new int;
    delete p;

    int* p2 = new( "AAA", 3 ) int;
    delete p2;

    return 0;
}

