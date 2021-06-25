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
 *  @file       MenuEvent05.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

struct ICommand
{
    virtual ~ICommand( ) { }
    virtual void Execute( ) = 0;
};


class FunctionCommand : public ICommand
{
public :
    FunctionCommand( void( *f )( ) )
        : handler( f )
    {
    }

    virtual void Execute( ) { handler( ); }

public :
    void( *handler )( );
};


void foo( )
{
    cout << "foo" << endl;
}


template< typename T >
class MemberCommand : public ICommand
{
public :
    MemberCommand( T* p, void( T::*f )( ) )
        : obj( p ), handler( f )
    {
    }

    virtual void Execute( ) {
        ( obj->*handler )( );
    }
public : 
    T* obj;
    void( T::*handler )( );
};

class Dialog
{
public :
    void Close( void ) { cout << "Close dialdog.." << endl; }
};

template< typename T > MemberCommand< T >* cmd( T* p, void( T::*f )() )
{
    return new MemberCommand< T >( p, f );
}


FunctionCommand* cmd( void( *f )( ) )
{
    return new FunctionCommand( f );
}

int main( int argc, char* argv[] )
{
    Dialog dlg;

    ICommand* p = cmd< Dialog >( &dlg, &Dialog::Close );
    p->Execute( );

    // or

    ICommand* p1 = cmd( &foo );
    ICommand* p2 = cmd( &dlg, &Dialog::Close );

    p1->Execute( );
    p2->Execute( );

    return 0;
}

