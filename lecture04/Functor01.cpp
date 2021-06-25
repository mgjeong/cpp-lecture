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
 *  @file       Functor01.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;


bool foo( int a )
{
    return a % 2 == 0;
}

struct IsEven
{
    inline bool operator( )( int a ) { return a % 2 == 0; }
};


int main( int argc, char* argv[] )
{
    int x[ 10 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int* p = find( x, x+10, 3 );
    cout << *p << endl;

    int* p2 = find_if( x, x+10, foo );
    cout << *p2 << endl;

    // using inlining with functor.
    IsEven even;
    int* p3 = find_if( x, x+10, even );
    cout << *p3 << endl;

    return 0;
}

