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
 *  @file       Inline01.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

int Add1( int a, int b )
{
    return a + b;
}

inline
int Add2( int a, int b )
{
    return a + b;
}


int main( int argc, char* argv[] )
{
    int n1 = Add1( 1, 2 );
    int n2 = Add2( 1, 2 );

    return 0;
}

