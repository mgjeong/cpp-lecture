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
 *  @file       RTTI03.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <string>
using namespace std;

typedef string String16;


class Animal
{
public :
    virtual ~Animal( ) { }
    static const String16 descriptor;   // role of type_info
    virtual const String16& getInterfaceDescriptor( ) const // role of typeid( )
    {
        return descriptor;
    }
};
const String16 Animal::descriptor( "Animal" );


class Dog : public Animal
{
public :
    virtual ~Dog( ) { }
    static const String16 descriptor;   // role of type_info
    virtual const String16& getInterfaceDescriptor( ) const // role of typeid( )
    {
        return descriptor;
    }
};
const String16 Dog::descriptor( "Dog" );

void foo( Animal* p )
{
    if( p->getInterfaceDescriptor( ) == Dog::descriptor ) {
        cout << "p is a Dog.." << endl;
    }
}

int main( int argc, char* argv[] )
{
    cout << "Animal inspection." << endl;
    Animal a; foo( &a );

    cout << "Dog inspection." << endl;
    Dog d; foo( &d );

    return 0;
}

