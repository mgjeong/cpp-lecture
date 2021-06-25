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
 *  @file       Inline06.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

inline
void swap( int& a, int& b )
{
    int tmp = a;
    a = b;
    b = tmp;
}

struct LESS
{
    inline bool operator( )( int a, int b ) { return a < b; }
};

struct GREATER
{
    inline bool operator( )( int a, int b ) { return a > b; }
};

template< typename T >
void sort( int* x, int n, T cmp )
{
    for( int i = 0; i < n; i++ ) {
        for( int j = i+1; j < n; j++ ) {
            if( cmp( x[i], x[j] ) )
                swap( x[i], x[j] );
        }
    }
}


int main( int argc, char* argv[] )
{
    int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
    LESS cmpl;
    GREATER cmpg;

    sort( x, 10, cmpl );

    for( int i = 0; i < 10; i ++ )
        cout << x[i] << " ";
    cout << endl;

    sort( x, 10, cmpg );

    for( int i = 0; i < 10; i ++ )
        cout << x[i] << " ";
    cout << endl;

    return 0;
}

