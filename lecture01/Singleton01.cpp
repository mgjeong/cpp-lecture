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
 *  @file       SIngleton01.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

class Cursor
{
private :
    Cursor( ) // rule 1.
    {
        cout << "Created..." << endl;
    }

    ~Cursor( )
    {
        cout << "Destoroyed..." << endl;
    }

    Cursor( const Cursor& c );  // rule 3.
    void operator=( const Cursor& c ); // rule 3.

public :
    static Cursor& GetInstance( )  // rule 2.
    {
        static Cursor instance;
        return instance;
    }
};


int main( int argc, char* argv[] )
{
    Cursor& c1 = Cursor::GetInstance( );
    Cursor& c2 = Cursor::GetInstance( );

    // Cursor c3 = Cursor::GetInstance( ); // error by rule 3.
    // Cursor c4( c1 ); // error by rule 3.

    cout << "address of c1 = " << &c1 << endl;
    cout << "address of c2 = " << &c2 << endl;

    return 0;
}

