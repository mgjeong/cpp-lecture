/**
 *  @file       LineEdit02.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
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

