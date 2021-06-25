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
 *  @file       SmartPointer05.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

template< typename T >
class ptr
{
    T* ptr_;
    int* ref_;

public :
    ptr( T* p = 0 )
        : ptr_( p )
    {
        ref_ = new int( 1 );
    }

    ptr( const ptr& p )
        : ptr_( p.ptr_ ), ref_( p.ref_ )
    {
        ++( *ref_ );
    }

    ~ptr( )
    {
        if( --( *ref_ ) <= 0 ) {
            delete ptr_;
            delete ref_;
        }
    }

    inline T* operator->( ) { return this->ptr_; }
    inline T& operator*( ) { return *( this->ptr_ ); }
};


int main( int argc, char* argv[] )
{
    ptr< int > p1 = new int;

    *p1 = 10;

    cout << "*p1 = " << *p1 << endl;

    ptr< int > p2 = p1;

    cout << "*p2 = " << *p2 << endl;

    return 0;
}

