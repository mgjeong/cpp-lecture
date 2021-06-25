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
 *  @file       ClassTemplate01.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

// Stack vs. Stack< T >

template< typename T >
class Stack
{
    T* buff;
public :
    Stack( ) { }        // okay
    //Stack< T >( ) {  }  // error

    //Stack( const Stack& s ) { }         // error, but acceptable
    Stack( const Stack< T >& s ) { }    // okay

    void push( const T& a );

    template< typename U > T foo( U a );
};

template< typename T >
void Stack< T >::push( const T& a )
{
}


template< typename T > template< typename U >
T Stack< T >::foo( U a )
{
    cout << "foo( U a ) = " <<  a << endl;
}



int main( int argc, char* argv[] )
{
    Stack< int > s1;
//    Stack        s2;
    Stack< int >  s3( s1 );


    s1.foo( 5.2f ); 

    return 0;
}

