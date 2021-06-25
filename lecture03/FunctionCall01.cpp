/**
 *  @file       FunctionCall01.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

class Test
{
public :
    void f1( ) { cout << "f1" << endl; }
    void f2( ) { cout << "f2" << endl; }

    int call_f3( ) {
        return this ? f3( ) : 0;
    }

    int call_f4( ) {
        return this ? f4( ) : 0;
    }

private :
    int f3( )   { cout << "f3" << endl; return data; }
    virtual int f4( )   { cout << "f4" << endl; return 0; }

    int data;

};

int main( int argc, char* argv[] )
{
    Test* p = 0;
    p->f1( );
    p->f2( );
//    p->f3( );
    p->call_f3( );
//    p->f4( );
    p->call_f4( );

    Test* q = new Test;

    q->call_f3( );
    q->call_f4( );

    return 0;
}

