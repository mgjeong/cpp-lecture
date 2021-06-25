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
 *  @file       Int2Type03.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

template< typename T, T N >
struct INTEGRAL_CONSTANT
{
    static const T value = N;
};

//INTEGRAL_CONSTANT< int, 0 > n0;
//INTEGRAL_CONSTANT< short, 0 > s0;

typedef INTEGRAL_CONSTANT< bool, true > TRUE_TYPE;
typedef INTEGRAL_CONSTANT< bool, false > FALSE_TYPE;

template< typename T > 
struct IS_POINTER : public FALSE_TYPE
{
};

template< typename T >
struct IS_POINTER< T* > : public TRUE_TYPE
{
};

template< typename T > 
T MaxImpl( T a, T b, TRUE_TYPE )
{
    cout << "Pointer case." << endl;
    return *a < *b ? b : a;
}

template< typename T >
T MaxImpl( T a, T b, FALSE_TYPE )
{
    cout << "Not pointer calse" << endl;
    return a < b ? b : a;
}

template< typename T >
T Max( T a, T b )
{
    return MaxImpl( a, b, IS_POINTER< T >( ) );
}


int main( int argc, char* argv[] )
{
    int a = 10, b = 20;
    int r1, r2;

    r1 = Max( a, b );
    r2 = *Max( &a, &b );

    cout << r1 << endl;
    cout << r2 << endl;

    return 0;
}

