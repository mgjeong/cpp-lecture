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

