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
 *  @file       
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Util.h"

using namespace std;


class BaseMenu
{
public :
    BaseMenu( string s )
        : title( s )
    {
    }

    virtual ~BaseMenu( )
    {
    }

    string GetTitle( ) const {
        return title;
    }

    virtual void Command( ) = 0;


private :
    string title;
};


class MenuItem : public BaseMenu
{
public :
    MenuItem( string s, int n )
        : BaseMenu( s ), id( n )
    {
    }

    virtual void Command( ) {
        cout << GetTitle( ) << " menu selected." << endl;
        char c = getch( );
    }
private :
    int id;
};


class PopupMenu : public BaseMenu
{
public :
    PopupMenu( string s )
        : BaseMenu( s ) 
    {
    }

    virtual ~PopupMenu( )
    {
        for( int i = 0; i < v.size( ) ; i++ )
            delete v[ i ];
    }

    void AddMenu( BaseMenu* m ) {
        v.push_back( m );
    }

    virtual void Command( ) {
        while( 1 ) {
            system( "clear" );
            int sz = v.size( );
            for( int i = 0; i < sz; i++ )
                cout << i+1 << ". " << v[i]->GetTitle( ) << endl;
            cout << sz+1 << ". upper menu" << endl;

            cout << "select item.. ";
            int cmd;
            cin >> cmd;
            
            if( cmd == sz+1 )
                break;
            else if( cmd < 1 || cmd > sz+1 )
                continue;
            else
                v[cmd-1]->Command( );
        }
    }
private :
    vector< BaseMenu* > v;
};


int main( int argc, char* argv[] )
{
    PopupMenu* menubar = new PopupMenu( "Menu Bar" );
    PopupMenu* pm1 = new PopupMenu( "Alarm" );
    PopupMenu* pm2 = new PopupMenu( "Light" );
    PopupMenu* pm3 = new PopupMenu( "Door" );
    
    menubar->AddMenu( pm1 );
    menubar->AddMenu( pm2 );
    menubar->AddMenu( pm3 );

    pm1->AddMenu( new MenuItem( "Set Time", 11 ) );
    pm1->AddMenu( new MenuItem( "View Time", 12 ) );

    pm2->AddMenu( new MenuItem( "Turn On", 21 ) );
    pm2->AddMenu( new MenuItem( "Turn Off", 22 ) );

    pm3->AddMenu( new MenuItem( "Open", 31 ) );
    pm3->AddMenu( new MenuItem( "Close", 32 ) );


    menubar->Command( );

    delete menubar;

    return 0;
}

