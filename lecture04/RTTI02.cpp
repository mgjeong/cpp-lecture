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
 *  @file       RTTI02.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <typeinfo>
using namespace std;

class Animal
{
public :
    virtual ~Animal( )
    {
    }
};

class Dog : public Animal
{
public :
    int color;
};

class Cat: public Animal
{
public :
    int color;
};

void foo( Animal* p )
{
    Dog* pd = dynamic_cast< Dog* >( p );
    cout << pd << endl;

    if( pd ) {
        cout << "p is a Dog." << endl;
        pd->color = 10;
    }
}


int main( int argc, char* argv[] )
{
    Animal a; foo( &a );
    Dog d; foo( &d );
    Cat c; foo( &c );

    return 0;
}

