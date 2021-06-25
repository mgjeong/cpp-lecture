/**
 *  @file       LineEdit01.cpp
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
			if ( isdigit( c ) ) {
				data.push_back( c );
				cout << c;
			}
		}
		cout << endl;
		return data;
	}

private :
    string data;
};


int main( )
{
	LineEdit edit;

	while( 1 ) {
		string s = edit.GetData( );
		cout << s << endl;
	}

	return 0;
}

