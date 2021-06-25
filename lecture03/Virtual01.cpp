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
 *  @file       Virtual01.cpp 
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

class Base
{
public :
    virtual void Foo( ) {
        cout << "Base::Foo" << endl; 
    }

    virtual void Goo( ) {
        cout << "Base::Goo" << endl; 
    }

private:
    long x;
};

class Derived : public Base
{
public :
    virtual void Foo( ) {
        cout << "Derived::Foo" << endl;
    }
private :
    long y;
};



int main( int argc, char* argv[] )
{
    Base b;
    Derived d;


    cout << sizeof( b ) << endl;
    cout << sizeof( d ) << endl;

    Base* p = &d;
    p->Foo( );

    return 0;

}
