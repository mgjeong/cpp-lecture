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
 *  @file       CopyConstrcutor01.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

class Point
{
public :
    Point( ) 
        : x( 0 ), y( 0 )
    {
    }

    Point( int a, int b )
        : x( a ), y( b )
    {
    }

    Point( const Point& p )
        : x( p.x ), y( p.y )
    {
    }

public :
    int x;
    int y;
};


int main( int argc, char* argv[] )
{
    Point p1;
    Point p2( 1, 1 );
    Point p3( p2 );

    cout << "p3 = " << p3.x << ", " << p3.y << endl;

    return 0;
}

