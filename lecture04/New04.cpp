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
 *  @file       New04.cpp
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
        cout << "Constructor" << endl;
    }

    ~Point( )
    {
        cout << "Destroyer" << endl;
    }

public :
    int x, y;
};



int main( int argc, char* argv[] )
{
    Point p( 1, 1 );
    cout << p.x << ", " << p.y << endl;

    //p.Point( 2, 2 );
    new( &p ) Point( 2, 2 );
    cout << p.x << ", " << p.y << endl;

    p.~Point( );

    Point* p2 = new Point( 3, 3 );
    cout << p2->x << ", " << p2->y << endl;

    delete p2;

    return 0;
}

