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
 *  @file       AccessModerator03.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <list>
using namespace std;


template< typename T >
class Stack
{
public :
    inline void push( const T& a ) { l.push_back( a ); }
    inline void pop( ) { l.pop_back( ); }
    inline T& top( ) { return l.back( ); }

private :
    list< T > l;
};

int main( int argc, char* argv[] )
{
    Stack< int > s;
    s.push( 10 );
    s.push( 20 );

    cout << s.top( ) << endl;
    cout << s.top( ) << endl;

    return 0;
}

