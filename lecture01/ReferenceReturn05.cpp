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
 *  @file       ReferenceReturn05.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

template<typename T>
class Stack
{
public :
    Stack( ) : index( -1 )
    {
    }

    void push( const T& a )
    {
        buff[ ++index ] = a;
    }

    void pop( )
    {
        --index;
    }

    T& top( )
    {
        return buff[ index ];
    }

private :
    T buff[ 10 ];
    int index;
};


int main( int argc, char* argv[] )
{
    Stack< int > s;

    s.push( 10 );
    s.push( 20 );

    cout << "s.top( ) = " << s.top( ) << endl;
    
    int& r = s.top( );
    s.pop( );
    cout << "r = " << r << endl;
    cout << "s.top( ) = " << s.top( ) << endl;
    s.pop( );

    return 0;
}

