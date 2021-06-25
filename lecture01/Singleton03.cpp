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
 *  @file       SIngleton03.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;


class Mutex
{
public :
    void Lock( )
    {
        cout << "Mutex lock" << endl;
    }

    void Unlock( )
    {
        cout << "Mutex unlock" << endl;
    }

    class Autolock
    {
    public :
        Autolock( Mutex& m )
            : mtx( m )
        {
            mtx.Lock( );
        }

        ~Autolock( )
        {
            mtx.Unlock( );
        }
    private :
        Mutex& mtx;
    };
};


class Cursor
{
private :
    Cursor( ) 
    {
        cout << "Cursor created..." << endl;
    }

    Cursor( const Cursor& c );
    void operator=( const Cursor& c );

    static Cursor* pInstance;
    static Mutex  sLock;

    int a;
    int b;
    double d;

public :
    static Cursor& GetInstance( ) 
    {
        Mutex::Autolock autolock( sLock ); 
        if( pInstance == 0 )
            pInstance = new Cursor( );

        return *pInstance;
    }

    ~Cursor( )
    {
        cout << "delete cursor" << endl;
    }
};


Cursor* Cursor::pInstance = NULL;
Mutex Cursor::sLock;

int main( int argc, char* argv[] )
{
    void foo( Cursor& cursor );

    Cursor& c1 = Cursor::GetInstance( );
    Cursor& c2 = Cursor::GetInstance( );

    cout << "address of c1 = " << &c1 << endl;
    cout << "address of c2 = " << &c2 << endl;

    Cursor* p = &c1;

    cout << "sizeof ( c1 ) = " << sizeof c1 << endl;
    cout << "sizeof ( p ) = " << sizeof p << endl;

    foo( *p );

    return 0;
}

void foo( Cursor& cursor )
{
    cout << "address of cursor = " << &cursor << endl;
}

