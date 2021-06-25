/**
 *  @file       Interface05.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

#define interface struct

interface ISmartPhone
{
    virtual ~ISmartPhone( ) { }
    virtual void Calling( const char* no ) = 0;
};

interface IMP3
{
    virtual ~IMP3( ) { }
    virtual void PlayMP3( const char* file ) = 0;
};


class People
{
public :
    void UsePhone( ISmartPhone* p ) { p->Calling( "010-101-0101" ); }
    void PlayMP3( IMP3* p ) { p->PlayMP3( "music" ); }
};

class Note : public ISmartPhone
{
public :
    virtual void Calling( const char* no ) {
        cout << "Calling with note : " << no << endl; 
    }
};

class Note2 : public ISmartPhone, public IMP3
{
public :
    virtual void Calling( const char* no ) {
        cout << "Calling with note2 : " << no << endl; 
    }
    virtual void PlayMP3( const char* file ) {
        cout << "Play MP3 with notw2" << endl;
    }
};


int main( int argc, char* argv[] )
{
    People p;
    Note n;
    p.UsePhone( &n );

    Note2 n2;
    p.UsePhone( &n2 );
    p.PlayMP3( &n2 );
    
    return 0;
}

