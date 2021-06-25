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
 *  @file       SmartPointer07.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

class Car
{
    int count_;
public :
    Car( )
        : count_ ( 0 )
    {
        cout << "Car created.." << endl;
    }

    ~Car( )
    {
        cout << "Car destroyed.." << endl;
    }

    void IncStrong( void ) { ++count_; }
    void DecStrong( void ) { if( --count_ <= 0 ) delete this; }
};



int main( int argc, char* argv[] )
{
    Car* p1 = new Car( );
    p1->IncStrong( );

    Car* p2 = p1;
    p2->IncStrong( );

    p2->DecStrong( );
    p1->DecStrong( );
    
    return 0;
}

