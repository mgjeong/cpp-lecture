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
 *  @file       TrivialConstructor01.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <cstdlib>
using namespace std;


class A
{
public :
    A( ) { cout << "A( ) " << endl; }
    virtual ~A( ) { }
};


class B : public A
{
public :
    B( ) { cout << "B( ) " << endl; }
    virtual ~B( ) { }
    virtual void foo( ) { cout << "foo" << endl; }
};

class C
{
public :
    C( ) { }
};


int main( int argc, char* argv[] )
{
    B* p1 = new B;
    p1->foo( );

    B* p2 = static_cast< B* >( malloc( sizeof( B ) ) );
    new( p2 ) B;
    p2->foo( );

    C c;

    return 0;
}

