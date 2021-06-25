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
 *  @file       SmartPointer06.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <memory>
using namespace std;

// g++ -o SmartPointer06 -std=c++0x SmartPointer06.cpp

int main( int argc, char* argv[] )
{
    shared_ptr< int > p1( new int( 1 ) );
    // shared_ptr< int > p2 = new int( 2 ); // Error

    shared_ptr< int > p3 = shared_ptr< int >( new int( 3 ) );

    *p1 = 2;
    *p3 = 5;

    shared_ptr< int > p4 = p1;

    cout << "*p1 = " << *p1 << endl;
    cout << "*p3 = " << *p3 << endl;
    cout << "*p4 = " << *p4 << endl;

    return 0;
}

