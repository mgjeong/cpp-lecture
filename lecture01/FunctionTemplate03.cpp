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
 *  @file       FunctionTemplate03.cpp
 *  @authro     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

template<typename T>
T Max( T a, T b )   { return a > b ? a : b; }


int main( int argc, char* argv[] )
{
    int n = Max( 1, 2 );
    double d = Max( 3.1, 4.5 );

    cout << "Max( 1, 2 ) = " << n << endl;
    cout << "Max( 3.1, 4.5 ) = " << d << endl;

    //===== quiz.. 
    short s1=5, s2=2;
    cout << "Max( s1, s2 ) = " << Max( s1, s2 ) << endl;

    cout << "Max<int>( s1, s2 ) = " << Max<int>( s1, s2 ) << endl;

    return 0;
}

