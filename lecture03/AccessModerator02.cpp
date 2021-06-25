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
 *  @file       AccessModerator02.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <list>
using namespace std;


template< typename T >
class stack : private list< T >
{
public :
    inline void push( const T& a ) { this->push_back( a ); }
    inline void pop( ) { this-> pop_back( ); }
    inline T& top( ) { return this-> back( ); }
};

int main( int argc, char* argv[] )
{
    stack< int > s;
    s.push( 10 );
    s.push( 20 );

    cout << s.top( ) << endl;

    // s.push_front( 30 );
    // cout << s.top( ) << endl;

    return 0;
}

