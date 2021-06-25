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
 *  @file       Functor05.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;


template< typename T1, typename T2, typename TR > 
struct Binary_function
{
    typedef T1 first_argument_type;
    typedef T2 second_argument_type;
    typedef TR result_type;
};


//struct Plus : public binary_function< int, int, int > // alread defined.
struct Plus : public Binary_function< int, int, int >
{
    int operator( )( int a, int b ) { return a+b; }
};


int main( int argc, char* argv[] )
{
    Plus p;
    int n = p( 1, 2 );
    cout << n << endl; // 3

    return 0;
}

