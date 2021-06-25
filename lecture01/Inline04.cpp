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
 *  @file       Inline04.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

void foo( int a ) { cout << "foo( " << a << " )" << endl; }
inline void goo( int a ) { cout << "goo( " << a << " )" << endl; }


int main( int argc, char* argv[] )
{
    foo( 1 );
    goo( 1 );

    void ( *f )( int );
    int n = 0;
    cout << "input...";
    cin >> n;
    if( n == 0 ) 
        f = &goo;
    else
        f = &foo;

    f(1);

    return 0;
}

