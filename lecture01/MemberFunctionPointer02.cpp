/**
 *  @file       MemberFunctionPointer02.cpp
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
    void (*f1)( void ) = &foo;
    void (*f2)( ) = &Dialog::Close;  // ???? 
    void (*f3)( void ) = &Dialog::Close2; // ??

    f1();
    f3();

    return 0;
}

