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
 *  @file       Functor03.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;


int main( int argc, char* argv[] )
{
    modulus< int > m;
    binder2nd< modulus< int > > f( m, 2 ); // set 2nd paramete as 2 of m.

    cout << f( 3 ) << endl; // 1
    cout << f( 4 ) << endl; // 0

    int x[ 10 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int* p = find_if( x, x+10, f );
    cout << *p << endl; // 1

    return 0;
}

