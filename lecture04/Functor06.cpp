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
 *  @file       Functor06.cpp
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

struct Plus : public Binary_function< int, int, int >
{
    int operator( )( int a, int b ) { return a+b; }
};


template< typename T >
struct xbinder2nd
{
    T op;
    //int second;
    typename T::second_argument_type second;
public :
    xbinder2nd( T f, typename T::second_argument_type s )
         : op( f ), second( s )
    {
    }

    typename T::result_type operator( )( typename T::first_argument_type first ) {
        return op( first, second );
    }
};

int main( int argc, char* argv[] )
{
    Plus p;
    int n = p( 1, 2 );
    cout << n << endl; // 3

    xbinder2nd< Plus > f( p, 2 );
    int n2 = f( 1 ); // p( 1, 2 ) = 3;
    cout << n2 << endl; // 3

    return 0;
}

