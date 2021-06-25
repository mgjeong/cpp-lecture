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
 *  @file       New01.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

class Point
{
    int x, y;
public :
    Point( ) : x( 0 ), y( 0 ) { cout << "constructor" << endl; }
    ~Point( ) { cout << "destroyer" << endl; }

    void Print( ) const {
        cout << "x = " << x << ", y = " << y << endl;
    }

    void Set( int a, int b ) { x = a; y = b; }
};


int main( int argc, char* argv[] )
{
    Point* p = new Point;
    p->Print( );
    delete p;


    // memory allocation without constructor.
    Point* p2 = static_cast< Point* >( ::operator new( sizeof( Point ) ) );
    p2->Set( 10, 20 );
    p2->Print( );

    // memory release without destoryer.
    ::operator delete( p2 );

    return 0;
}

