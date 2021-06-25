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
 *  @file       TemplateSpecialization05.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

template< typename T >
struct trait_array
{
    enum { size = -1 };
    enum { value = false };
};


template< typename T >
void foo( const T& a )
{
    if( trait_array<T>::value )
        cout << "It is an array..." << endl;
    else
        cout << "It is not an array..." << endl;
}


int main( int argc, char* argv[] )
{
    int n = 1;
    foo( n );

    int x[10];
    foo( x );
    
    
    int y[] = { 1, 3, 5, 7, 9, 11 };
    foo( y );

    return 0;
}


