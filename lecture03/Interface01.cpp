/**
 *  @file       Interface01.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;

class Note 
{
public :
    void Calling( const char* no ) { cout << "Calling with note : " << no << endl; }
};

class People
{
public :
    void UsePhone( Note* p ) { p->Calling( "010-101-0101" ); }
};


int main( int argc, char* argv[] )
{
    People p;
    Note n;
    p.UsePhone( &n );

    return 0;
}

