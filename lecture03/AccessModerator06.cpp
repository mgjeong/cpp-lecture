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
 *  @file       AccessModerator06.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <stack>
#include <list>
#include <vector>
using namespace std;


int main( int argc, char* argv[] )
{
    stack< int, list< int > > ls;    
    stack< int, vector< int > > vs;
    stack< int > s;

    ls.push( 10 );
    vs.push( 20 );
    s.push( 30 );

    cout << ls.top( ) << endl;
    cout << vs.top( ) << endl;
    cout << s.top( ) << endl;

    return 0;
}

