/**
 *  @file       SIngleton02.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;


class Mutex
{
public :
    void Lock( )
    {
        cout << "Mutex lock" << endl;
    }

    void Unlock( )
    {
        cout << "Mutex unlock" << endl;
    }
};


class Cursor
{
private :
    Cursor( ) 
    {
        cout << "Cursor created..." << endl;
    }

    Cursor( const Cursor& c );
    void operator=( const Cursor& c );

    static Cursor* pInstance;
    static Mutex  sLock;

    int a;
    int b;
    double d;

public :
    static Cursor& GetInstance( ) 
    {
        sLock.Lock( );

        if( pInstance == 0 )
            pInstance = new Cursor( );

        sLock.Unlock( );

        return *pInstance;
    }

    ~Cursor( )
    {
        cout << "delete cursor" << endl;
    }
};


Cursor* Cursor::pInstance = NULL;
Mutex Cursor::sLock;

int main( int argc, char* argv[] )
{
    void foo( Cursor& cursor );

    Cursor& c1 = Cursor::GetInstance( );
    Cursor& c2 = Cursor::GetInstance( );

    cout << "address of c1 = " << &c1 << endl;
    cout << "address of c2 = " << &c2 << endl;

    Cursor* p = &c1;

    cout << "sizeof ( c1 ) = " << sizeof c1 << endl;
    cout << "sizeof ( p ) = " << sizeof p << endl;

    foo( *p );

    return 0;
}

void foo( Cursor& cursor )
{
    cout << "address of cursor = " << &cursor << endl;
}

