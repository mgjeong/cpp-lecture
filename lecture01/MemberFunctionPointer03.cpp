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
 *  @file       MemberFunctionPointer03.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

class Dialog
{
public :
    void Close( )
    {
        cout << "Close dialog" << endl;
    }
    static void Close2( )
    {
        cout << "Close dialog 2" << endl;
    }
};

void foo( )
{
    cout << "foo" << endl;
}

int main( int argc, char* argv[] )
{
    void ( *f1 )( ) = &foo;
    void( Dialog::*f2)( ) = &Dialog::Close;

    void ( Dialog::*f3 )( );
    f3 = &Dialog::Close;

    f1( );

    Dialog dlg;
    ( dlg.*f2 )( ); // dlg.Close( );
    ( dlg.*f3 )( );

    return 0;
}

