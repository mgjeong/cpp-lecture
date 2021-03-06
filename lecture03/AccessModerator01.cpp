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
 *  @file       AccessModerator01.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;


class A
{
private : int x;
protected : int y;
public : int z;
};

class B : private A
{
};

class C : private A
{
};

class D : private A
{
};

int main( int argc, char* argv[] )
{
    A a;
    a.x = 0;
    a.y = 0;
    a.z = 0;

    B b;
    b.x = 0;
    b.y = 0;
    b.z = 0;

    C c;
    c.x = 0;
    c.y = 0;
    c.z = 0;

    D d;
    d.x = 0;
    d.y = 0;
    d.z = 0;

    return 0;
}

