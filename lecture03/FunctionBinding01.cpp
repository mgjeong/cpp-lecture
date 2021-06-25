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
 *  @file       FunctionBinding01.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

class Animal
{
public :
    void Cry( void ) 
    {
        cout << "Animal Cry.." << endl;
    }
};

class Dog : public Animal
{
public :
    void Cry( void )
    {
        cout << "Dog Cry.." << endl;
    }
};

int main( int argc, char* argv[] )
{
    Animal a; a.Cry( );
    Dog d; d.Cry( );


    int n = 0;
    cout << "select.. ";
    cin >> n;

    Animal* p;
    if( n == 0 ) p = &d;
    else         p = &a;

    p->Cry( );

    return 0;
}

