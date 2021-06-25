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
 *  @file       MemberTemplate03.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;


template< typename T >
class Complex
{
public :
    Complex( T a = T( ), T b = T( ) )
        : re( a ), im( b )
    {
        cout << "( " << re << ", " << im << " )" << endl;
    }
    
    template< typename U > Complex( const Complex< U >& u );

    template<typename> friend class Complex;
private :
    T re;
    T im;
};


template< typename T > template< typename U >
Complex< T >::Complex( const Complex< U >& u )
    : re( u.re ), im( u.im )
{
    cout << "( " << re << ", " << im << " )" << endl;
}


int main( int argc, char* argv[] )
{
    Complex< int > c1( 1, 1 );
    Complex< int > c2( c1 );

    Complex< double > c3( c1 );

    return 0;
}

