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
 *  @file       FunctionTemplate01.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

template< typename T >
void foo( T a )
{
    cout << typeid( a ).name( ) << endl;
}

template< typename T >
void goo( T& a )
{
    cout << typeid( a ).name( ) << endl;
}


int main( int argc, char* argv[] )
{
    int n = 10;
    int x[ 10 ];
    string  str = "string";

    cout << "foo..." << endl;
    foo( n );
    foo( x );
    foo( str );
    foo( "AAA" );
    foo( main );

    cout << "goo..." << endl;
    goo( n );
    goo( x );
    goo( str );
    goo( "AAA" );
    goo( main );


    return 0;
}

