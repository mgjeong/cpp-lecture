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
 *  @file       LineEdit02.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <vector>
#include <string>
#include "Util.h"

using namespace std;

class LineEdit
{
public :
	string	GetData( ) {
		data.clear( );
		while( 1 ) {
			char c = getch( );
			if( c == '\n' ) break;
			if ( validate( c ) ) {
				data.push_back( c );
				cout << c;
			}
		}
		cout << endl;
		return data;
	}

private :
    virtual bool validate( char c ) { return isdigit( c ); }

private :
    string data;
};

class AddressEdit : public LineEdit
{
private :
    virtual bool validate( char c ) { return true; }
};


int main( )
{
	AddressEdit edit;

	while( 1 ) {
		string s = edit.GetData( );
		cout << s << endl;
	}

	return 0;
}

