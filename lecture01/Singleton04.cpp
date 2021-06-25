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
 *  @file       SIngleton04.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <typeinfo>
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


template< typename T > class Singleton 
{
protected :
    Singleton( )
    {
        cout << typeid(T).name( )  << " Singleton created" << endl;
    }

private :
    Singleton( const Singleton& c );
    void operator=( const Singleton& c );
    static T* pInstance;
    static Mutex sLock;

public :
    static T& GetInstance( ) 
    {
        Mutex::Autolock autolock( sLock );

        if( pInstance == 0 )
            pInstance = new T( );

        return *pInstance;
    }

    ~Singleton( )
    {
        cout << "Singleton deleted" << endl;
    }
};


template< typename T > T* Singleton<T>::pInstance = NULL;
template< typename T > Mutex Singleton<T>::sLock;


class DoorService : public Singleton< DoorService >
{
};

class CateringService : public Singleton< CateringService >
{
};

class AAA 
{
public :
    void Print( void )
    {
        cout << "AAA..." << endl;
    }
};

int main( int argc, char* argv[] )
{
    DoorService& d1 = DoorService::GetInstance( );
    DoorService& d2 = DoorService::GetInstance( );

    CateringService& t1 = CateringService::GetInstance( );

    AAA& a1 = Singleton< AAA >::GetInstance( );
    //AAA& a1 = AAA::GetInstance( );
    a1.Print( );

    return 0;
}


