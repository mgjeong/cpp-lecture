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
 *  @file       ConstFunction01.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

class Point
{
public :
    Point( int a = 0, int b = 0 )
        : x( a ), y( b )
    {
    }

    void Set( int a, int b )
    {
        x = a;
        y = b;
    }

    void Print( void )
    {
        cout << "x = " << x << ", y = " << y << endl;
        x = 10;
    }

public :
    int x;
    int y;
};


int main( int argc, char* argv[] )
{
    const Point p( 1, 2 );
    // p.x = 10;         // error;
    // p.Set( 10, 20 );  // error;
    // p.Print( );       // error;

    return 0;
}

