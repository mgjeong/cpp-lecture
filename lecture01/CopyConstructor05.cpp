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
 *  @file       CopyConstructor05.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <cstring>
using namespace std;

class Cat 
{
public :
    Cat( const char* n, int a )
        : age( a )
    {
        name = new char[ strlen( n ) ];
        strcpy( name, n );
        ref = new int(1); // initialized by 1
    }

    Cat( const Cat& c )
        : age( c.age ), name( c.name ), ref( c.ref )
    {
        ++(*ref);
    }

    ~Cat( )
    {
        if( --(*ref) == 0 ) {
            delete [] name;
            delete ref;
        }

    }

public :
    char* name;
    int age;
    int* ref;
};


int main( int argc, char* argv[] )
{
    Cat c1( "neo", 10 );
    Cat c2( c1 );
    Cat c3( "bella", 5 );
    Cat c4( c3 );

    cout << "c4 " << c4.name << " " << c4.age << endl;
    cout << "c2 " << c2.name << " " << c2.age << endl;

    return 0;
}

