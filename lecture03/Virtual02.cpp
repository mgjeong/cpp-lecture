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
 *  @file       Virtual02.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <cstring>
//using namespace std;

class Animal
{
public :
    Animal( const char* n )
    {
        name = new char[ strlen( n ) ];
        strcpy( name, n );
    }

    virtual ~Animal( )
    {
        delete [] name;
    }

    const char* GetName( ) const
    {
        return name;
    }

    friend std::ostream& operator<< ( std::ostream& os, const Animal& animal )
    {
        return os << animal.GetName( ) << "(Animal)";
    }

private :
    char*   name;
};


class Dog : public Animal
{
public :
    Dog( const char* n )
        : Animal( n )
    {
    }


    friend std::ostream& operator<< ( std::ostream& os, const Dog& dog  )
    {
        return os << dog.GetName( ) << "(Dog)";;
    }
};


void foo( Animal* p )
{
    std::cout << *p << std::endl;
}


int main( int argc, char* argv[] )
{
    Animal animal("pooh");
    Dog dog( "pluto" );

    std::cout << animal << std::endl;
    std::cout << dog << std::endl;

    foo( &animal );
    foo( &dog );

    return 0;
}

