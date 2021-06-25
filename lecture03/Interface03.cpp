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
 *  @file       Interface03.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;


class ISmartPhone
{
public :
    virtual ~ISmartPhone( ) { }
    virtual void Calling( const char* no ) = 0;
};

class People
{
public :
    void UsePhone( ISmartPhone* p ) { p->Calling( "010-101-0101" ); }
};

class Note : public ISmartPhone
{
public :
    virtual void Calling( const char* no ) {
        cout << "Calling with note : " << no << endl; 
    }
};

class Note2 : public ISmartPhone
{
public :
    virtual void Calling( const char* no ) {
        cout << "Calling with note2 : " << no << endl; 
    }
};


int main( int argc, char* argv[] )
{
    People p;
    Note n;
    p.UsePhone( &n );

    Note2 n2;
    p.UsePhone( &n2 );
    
    return 0;
}

