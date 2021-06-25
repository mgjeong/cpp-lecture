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
 *  @file       ReferenceReturn03.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

void foo( int n ) { ++n; }
void goo( int* p ) { ++(*p); }
void hoo( int& r ) { ++r; }

int main( int argc, char* argv[] )
{
    int x = 1, y = 1, z = 1;

    foo( x );
    goo( &y );
    hoo( z );

    cout << "x= " << x << endl;
    cout << "y= " << y << endl;
    cout << "z= " << z << endl;

    return 0;
}

