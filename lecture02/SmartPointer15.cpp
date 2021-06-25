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
 *  @file       SmartPointer15.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

struct weakref_impl {
    int count_; // managed by sp
    int weak_;  // managed by wp
};

class RefBase
{
    weakref_impl* refs_;

public :
    RefBase( )
    {
        refs_ = new weakref_impl;
    }

    virtual ~RefBase( )
    {
    }

    void IncStrong( ) const
    {
       ++refs_->count_;
    }

    void DecStrong( ) const
    {
        if( --refs_->count_ <= 0 ) {
            delete refs_;
            delete this;
        }
    }
};


class Point : public RefBase
{
    int x, y;
public :
    Point( int a = 0, int b = 0 )
        : x( a ), y( b )
    {
    }

    void Print( ) const
    {
        cout << "x = " << x << ", y = " << y << endl;
    }
};


int main( int argc, char* argv[] )
{
    const Point p( 1, 2 );
    p.Print( );         // ok...
    p.IncStrong( );     // Q ? Is it acceptable ???

    return 0;
}

