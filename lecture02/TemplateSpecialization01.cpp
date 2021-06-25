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
 *  @file       TemplateSpecialization01.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;


template< typename T >
class Stack
{
public :
    void Push( )
    {
        cout << "T" << endl;
    }
};

template< typename T >
class Stack< T* >
{
public :
    void Push( )
    {
        cout << "T*" << endl;
    }
};

template< >
class Stack< char* >
{
public :
    void Push( )
    {
        cout << "char*" << endl;
    }
};


int main( int argc, char* argv[] )
{
    Stack< int > s1;
    Stack< int* > s2;
    Stack< char* > s3;

    s1.Push( );
    s2.Push( );
    s3.Push( );

    return 0;
}

