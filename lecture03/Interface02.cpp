/**
 *  @file       Interface02.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

class Note 
{
public :
    void Calling( const char* no ) { cout << "Calling with note : " << no << endl; }
};

class Note2
{
public :
    void Calling( const char* no ) { cout << "Calling with note2 : " << no << endl; }
};

class People
{
public :
    void UsePhone( Note* p ) { p->Calling( "010-101-0101" ); }
    void UsePhone( Note2* p ) { p->Calling( "010-101-0101" ); }
};


int main( int argc, char* argv[] )
{
    People p;
    Note n;
    p.UsePhone( &n );

    Note2 n2;
    p.UsePhone( &n2 );
    
    return 0;
}

