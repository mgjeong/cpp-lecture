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
 *  @file       MultiInherit03.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;


class A { public : int a; };
class B { public : int b; };

class C : public A, public B
{
};


int main( int argc, char* argv[] )
{
    C c;
    cout << "&c = " << &c << endl;

    A* p1 = &c;
    B* p2 = &c;
    B* p3 = ( B* )&c;
    B* p4 = static_cast< B* >( &c );
    B* p5 = reinterpret_cast< B* >( &c );

    p5->b = 10;
    cout << "c.a = " << c.a << endl;
    cout << "c.b = " << c.b << endl;

    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "p3 = " << p3 << endl;
    cout << "p4 = " << p4 << endl;
    cout << "p5 = " << p5 << endl;

    return 0;
}

