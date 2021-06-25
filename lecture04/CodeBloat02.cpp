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
 *  @file       CodeBloat02.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;


class VectorImpl
{
    int sz;
    void* buff;

public :
    int Size( ) { return sz; }
    bool Empty( ) { return sz == 0; }
    void Push( void* item, int s ) { }
    void* Top( ) { return buff; }
};


template< typename T >
class Vector : private VectorImpl
{
public :
    int Size( ) { return VectorImpl::Size( ); }
    bool Empty( ) { return VectorImpl::Empty( ); }
    inline void Push( const T& a ) { VectorImpl::Push( &a, sizeof( T ) ); }
    inline T& Top( ) { return static_cast< T& >( *VectorImpl::Top( ) ); }
};


int main( int argc, char* argv[] )
{
    Vector< int > s1;
    Vector< double > s2;

    return 0;
}

