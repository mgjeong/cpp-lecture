/**
 *  @file       LineEdit03.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
#include <vector>
#include <string>
#include "Util.h"

using namespace std;


#define interface struct

interface IValidator
{
    virtual ~IValidator( ) { }
    virtual bool validate( string s, char c ) = 0;
    virtual bool iscomplete( string s ) { return true; }
};

class LineEdit
{
public :
    LineEdit( )
        : pValidator( 0 )
    {
    }

    void SetValidator( IValidator* p ) { pValidator = p; }

	string	GetData( ) {
		data.clear( );
		while( 1 ) {
			char c = getch( );
			if( c == '\n' && ( pValidator == 0 || pValidator->iscomplete( data ) ) ) break;
            if( pValidator == 0 || pValidator->validate( data, c ) ) {
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
    IValidator* pValidator;
};


class LimitDigitValidator : public IValidator
{
public :
    LimitDigitValidator( int n )
        : value( n )
    {
    }

    virtual bool validate( string s, char c ) {
        return s.size( ) < value && isdigit( c );
    }

    virtual bool iscomplete( string s ) {
        return s.size( ) == value;
    }
private :
    int value;
};


int main( )
{
    LineEdit edit;

	LimitDigitValidator v( 5 );
	edit.SetValidator( &v );

	while( 1 ) {
		string s = edit.GetData( );
		cout << s << endl;
	}

	return 0;
}

