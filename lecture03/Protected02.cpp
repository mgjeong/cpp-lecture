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
 *  @file       Protected02.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;


class Base
{
protected :
    Base( ) { cout << "Base( )" << endl; }
    Base( int a ) { cout << "Base( int )" << endl; }
    ~Base( ) { cout << "~Base( )" << endl; }
};

class Derived : public Base
{
public :
    Derived( ) { cout << "Derived( ) " << endl; }
    Derived( int a ) : Base( a ) { cout << "Derived( int )" << endl; }
    ~Derived( ) { cout << "~Derived( )" << endl; }
};

int main( int argc, char* argv[] )
{
    Derived d1;
    Derived d2(1);

    return 0;
}

