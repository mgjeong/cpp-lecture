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
 *  @file       MenuEvent06.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <functional>
using namespace std;


void foo( ) { cout << "foo" << endl; }
void goo( int a ) { cout << "goo : " << a << endl; }
void hoo( int a, int b ) { cout << "hoo : " << a-b << endl; }

class Dialog
{
public :
    void Close( ) { cout << "Close dialog" << endl; }
};


int main( int argc, char* argv[] )
{
    function< void( ) > f1;
    f1 = &foo;
    f1( );  // == foo( );

    function< void( int ) > f2;
    f2 = &goo;
    f2( 10 ); // == goo( 10 );

    Dialog dlg;
    function< void( ) > f3;
    f3 = bind( &Dialog::Close, &dlg );
    f3( ); // dlg.Close( );


    // Question 1
    f1 = bind( &goo, 5 );
    f1( );

    // Question 2
    f1 = bind( &hoo, 10, 4 );
    f1( );

    using namespace std::placeholders;
    function< void ( int, int ) > f4;
    f4 = bind( &hoo, _2, _1 );
    f4( 10, 5 );


    return 0;
}

