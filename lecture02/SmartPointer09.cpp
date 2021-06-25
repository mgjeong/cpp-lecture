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
 *  @file       SmartPointer09.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

class RefBase
{
    int count_;

public :
    RefBase( )
        : count_( 0 )
    {
    }

    virtual ~RefBase( )
    {
    }

    void IncStrong( ) { ++count_; }
    void DecStrong( ) { if( --count_ <= 0 ) delete this; }
};


class Car : public RefBase
{
public :
    Car( )
    {
        cout << "Car created.." << endl;
    }

    ~Car( )
    {
        cout << "Car destroyed.." << endl;
    }

    void Go( ) { cout << "Car go..." << endl; }
};


template< typename T >
class sp
{
    T* ptr_;

public :
    sp( T* p = 0 )
        : ptr_( p )
    {
        if( ptr_ ) ptr_->IncStrong( );
    }

    sp( const sp& p )
        : ptr_ ( p.ptr_ )
    {
        if( ptr_ ) ptr_->IncStrong( );
    }

    ~sp( )
    {
        if( ptr_ ) ptr_->DecStrong( );
    }

    inline T* operator->( ) { return this->ptr_; }
    inline T& operator*( ) { return *(this->ptr_); }
};



int main( int argc, char* argv[] )
{
    sp< Car > p1 = sp< Car >( new Car );
    sp< Car > p2 = p1;

    p1->Go( );
    p2->Go( );

    return 0;
}

