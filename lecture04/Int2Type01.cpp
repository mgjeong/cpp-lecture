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
 *  @file       Int2Type01.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;


template< typename T >
struct Is_Pointer
{
    enum { value = false };
};

template< typename T >
struct Is_Pointer< T* >
{
    enum { value = true };
};

template< typename T >
T Max( T a, T b )
{
    if( Is_Pointer< T >::value )
        return *a < *b ? b : a;
    return a < b ? b : a;
}

int main( int argc, char* argv[] )
{
    int x = 10, y = 20;

    // Max( x, y ); // error.
    Max( &x, &y );

    return 0;
}

