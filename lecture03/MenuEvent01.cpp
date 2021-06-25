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
 *  @file       MenuEvent01.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;


struct IMenuListener
{
    virtual ~IMenuListener( ) {} 
    virtual void OnCommand( int id ) = 0;
};


class MenuItem
{
public :
    MenuItem( int n )
        : id( n )
    {
    }

    void AddListener( IMenuListener* plistener ) {
        v.push_back( plistener );
    }

    virtual void Command( ) {
        for( int i = 0; i < v.size( ); i++ )
            v[i]->OnCommand( id );
    }

private :
    int id;
    vector< IMenuListener* > v;
};


class Camera : public IMenuListener
{
public :
    virtual void OnCommand( int id ) {
        switch( id ) {
        case 11 :
            cout << "Brightness configuration" << endl;
            break;
        default :
            cout << "Confusing.." << endl;
            break;
        }
    }
};


int main( int argc, char* argv[] )
{
    Camera c;
    MenuItem m1(11), m2(12);

    m1.AddListener( &c );
    m1.Command( );

    m2.AddListener( &c );
    m2.Command( );

    return 0;
}

