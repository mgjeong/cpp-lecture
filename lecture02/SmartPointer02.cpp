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
 *  @file       SmartPointer02.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;


class Car
{
public :
    void Go( ) { cout << "Car go " << endl; }
};

class ptr
{
    Car* m_ptr;

public :
    ptr( Car* p = 0 )
        : m_ptr( p )
    {
    }

    ~ptr( )
    {
        delete m_ptr;
    }

    inline Car* operator->( ) { return this->m_ptr; }
    inline Car& operator*( ) { return *(this->m_ptr); }

};

int main( int argc, char* argv[] )
{
    ptr p = new Car;  // ptr p( new Car );

    p->Go( ); // ( p.operator->( ) )->Go( );

    (*p).Go( );

    return 0;
}

