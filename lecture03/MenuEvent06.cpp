/**
 *  @file       MenuEvent06.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <functional>
using namespace std;


void foo( ) { cout << "foo" << endl; }
void goo( int a ) { cout << "goo : " << a << endl; }
void hoo( int a, int b ) { cout << "hoo : " << a-b << endl; }

class Dialog
{
public :
    void Close( ) { cout << "Close dialog" << endl; }
};


int main( int argc, char* argv[] )
{
    function< void( ) > f1;
    f1 = &foo;
    f1( );  // == foo( );

    function< void( int ) > f2;
    f2 = &goo;
    f2( 10 ); // == goo( 10 );

    Dialog dlg;
    function< void( ) > f3;
    f3 = bind( &Dialog::Close, &dlg );
    f3( ); // dlg.Close( );


    // Question 1
    f1 = bind( &goo, 5 );
    f1( );

    // Question 2
    f1 = bind( &hoo, 10, 4 );
    f1( );

    using namespace std::placeholders;
    function< void ( int, int ) > f4;
    f4 = bind( &hoo, _2, _1 );
    f4( 10, 5 );


    return 0;
}

