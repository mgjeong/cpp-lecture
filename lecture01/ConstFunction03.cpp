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
 *  @file       ConstFunction03.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <stdio.h>
using namespace std;

class Point
{
public :
    Point( int a = 0, int b = 0 )
        : x( a ), y( b ), cache_valid( false )
    {
    }

    // 객체를 문자열로 바꾸어 주는 함수
    // java, C#에는 모든 클래스에 대하여 toString() 을 이미 지원
    const char* toString( ) const
    {
        if( cache_valid == false ) {
            sprintf( cache, "%d, %d", x, y );  // error !!
            cache_valid = true; // error !!
        }
        return cache;
    }

private :
    int x, y;
    char cache[32];
    bool cache_valid;
};

int main( )
{
    Point p( 1, 2 );
    cout << p.toString( ) << endl;

    return 0;
}

