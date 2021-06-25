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
 *  @file       FunctionTemplate02.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <typeinfo>
using namespace std;

template< typename T >
void foo( const T a, const T b )
{
    cout << a << " + " << b << endl;
}

template< typename T >
void goo( const T& a, const T& b )
{
    cout << a << " + " << b << endl;
}

void hoo( const char* s1, const char* s2 )
{
    cout << s1 << " + " << s2 << endl;
}

void moo( const char s1[ ], const char s2[ ] )
{
    cout << s1 << " + " << s2 << endl;
}


int main( int argc, char* argv[] )
{
    foo( "orange", "kiwi" );
    goo( "orange", "kiwi" ); // error
    hoo( "orange", "kiwi" );
    moo( "orange", "kiwi" );

    return 0;
}

