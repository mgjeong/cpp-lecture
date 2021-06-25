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
 *  @file       VirtualDestroyer04.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

template< typename T >
class LightRefBase
{
public :
    LightRefBase( ) 
        : mCount( 0 )
    {
        cout << "LightRefBase created." << endl;
    }

    ~LightRefBase( )
    {
        cout << "LightRefBase deleted." << endl;
    }

    void incStrong( ) { ++mCount; }
    void decStrong( ) {
        if( --mCount <= 0 )
            delete static_cast< T* >( this ); 
    }

private :
    int mCount;

};

class Car : public LightRefBase< Car >
{
public :
    ~Car( ) { cout << "Car destroyed.." << endl; }

};


int main( int argc, char* argv[] )
{
    Car* p = new Car( );
    p->incStrong( );
    p->decStrong( );

    return 0;
}

