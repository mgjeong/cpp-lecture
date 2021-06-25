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
 *  @file       RTTI04.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <string>
using namespace std;

typedef string String16;

#define DECLARE_META_INTERFACE( INTERFACE )                     \
    public :                                                    \
    static const String16 descriptor;                           \
    virtual const String16& getInterfaceDescriptor( ) const;    


#define IMPLEMENT_META_INTERFACE( INTERFACE, NAME )                 \
    const String16 INTERFACE::descriptor( NAME );                   \
    const String16& INTERFACE::getInterfaceDescriptor( ) const {    \
        return INTERFACE::descriptor;                               \
    }


class Animal
{
    DECLARE_META_INTERFACE( Animal )
};
IMPLEMENT_META_INTERFACE( Animal, "Animal" )


class Dog : public Animal
{
    DECLARE_META_INTERFACE( Dog )
};
IMPLEMENT_META_INTERFACE( Dog, "Dog" )


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

