/**
 *  @file       Interface03.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;


class ISmartPhone
{
public :
    virtual ~ISmartPhone( ) { }
    virtual void Calling( const char* no ) = 0;
};

class People
{
public :
    void UsePhone( ISmartPhone* p ) { p->Calling( "010-101-0101" ); }
};

class Note : public ISmartPhone
{
public :
    virtual void Calling( const char* no ) {
        cout << "Calling with note : " << no << endl; 
    }
};

class Note2 : public ISmartPhone
{
public :
    virtual void Calling( const char* no ) {
        cout << "Calling with note2 : " << no << endl; 
    }
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

