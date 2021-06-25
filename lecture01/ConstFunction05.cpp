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
 *  @file       ConstFunction05.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <cstdio>
using namespace std;

struct Cache
{
    char data[32];
    bool valid;
};

class Point
{
public :
    Point( int a = 0, int b = 0 )
        : x( a ), y( b )
    {
        pCache = new Cache;
        pCache->valid = false;
    }

    ~Point( )
    {
        delete pCache;
    }

    const char* toString( void ) const
    {
        if( pCache->valid == false ) {
            sprintf( pCache->data, "%d, %d", x, y );
            pCache->valid = true;
        }
        return pCache->data;
    }

    void Set( int a, int b )
    {
        x = a;
        y = b;
        pCache->valid = false;
    }

private :
    int x;
    int y;
    Cache* pCache;
};


int main( int argc, char* argv[] )
{
    Point p( 1, 2 );

    cout << p.toString( ) << endl;
    cout << p.toString( ) << endl;
    
    p.Set( 10, 20 );
    
    cout << p.toString( ) << endl;

    return 0;
}

