/**
 *  @file       MenuEvent05.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
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

public :
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
public : 
    T* obj;
    void( T::*handler )( );
};

class Dialog
{
public :
    void Close( void ) { cout << "Close dialdog.." << endl; }
};

template< typename T > MemberCommand< T >* cmd( T* p, void( T::*f )() )
{
    return new MemberCommand< T >( p, f );
}


FunctionCommand* cmd( void( *f )( ) )
{
    return new FunctionCommand( f );
}

int main( int argc, char* argv[] )
{
    Dialog dlg;

    ICommand* p = cmd< Dialog >( &dlg, &Dialog::Close );
    p->Execute( );

    // or

    ICommand* p1 = cmd( &foo );
    ICommand* p2 = cmd( &dlg, &Dialog::Close );

    p1->Execute( );
    p2->Execute( );

    return 0;
}

