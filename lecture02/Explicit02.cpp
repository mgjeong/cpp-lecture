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
 *  @file       Explicit02.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

class Point
{
    int x, y;

public :
    Point( )
        : x( 0 ), y( 0 )
    {
    }

    Point( int a, int b )
        : x( a ), y( b )
    {
    }

    Point( int a )
        : x( a ), y( 0 )
    {
    }

    operator int( ) { return x; }

};


int main( int argc, char* argv[] )
{
    double d = 4.4;
    int n = d;
    
    Point p1;
    Point p( 2, 1 );

    int n2 = p; /// ???
    cout << "n2 = " << n2 << endl;

    p = n; // ???
    cout << "p = " << p << endl;

    return 0;
}

