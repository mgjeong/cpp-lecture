/**
 *  @file       MenuEvent04.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;

struct ICommand
{
    virtual ~ICommand( ) { }
    virtual void Execute( ) = 0;
};


class FunctionCommand : public ICommand
{
public :
    FunctionCommand( void( *f )( ) )
        : handler( f )
    {
    }

    virtual void Execute( ) { handler( ); }

private :
    void( *handler )( );
};


void foo( )
{
    cout << "foo" << endl;
}


template< typename T >
class MemberCommand : public ICommand
{
public :
    MemberCommand( T* p, void( T::*f )( ) )
        : obj( p ), handler( f )
    {
    }

    virtual void Execute( ) {
        ( obj->*handler )( );
    }
private : 
    T* obj;
    void( T::*handler )( );
};

class Dialog
{
public :
    void Close( void ) { cout << "Close dialdog.." << endl; }
};


int main( int argc, char* argv[] )
{
    FunctionCommand fc( &foo );
    ICommand* p = &fc;
    p->Execute( );

    Dialog dlg;
    MemberCommand< Dialog > mc( &dlg, &Dialog::Close );
    //MemberCommand mc( &dlg, &Dialog::Close );
    ICommand* pp = &mc;
    pp->Execute( );

    return 0;
}

