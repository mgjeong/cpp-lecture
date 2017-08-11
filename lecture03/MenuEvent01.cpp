/**
 *  @file       MenuEvent01.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
#include <vector>
using namespace std;


struct IMenuListener
{
    virtual ~IMenuListener( ) {} 
    virtual void OnCommand( int id ) = 0;
};


class MenuItem
{
public :
    MenuItem( int n )
        : id( n )
    {
    }

    void AddListener( IMenuListener* plistener ) {
        v.push_back( plistener );
    }

    virtual void Command( ) {
        for( int i = 0; i < v.size( ); i++ )
            v[i]->OnCommand( id );
    }

private :
    int id;
    vector< IMenuListener* > v;
};


class Camera : public IMenuListener
{
public :
    virtual void OnCommand( int id ) {
        switch( id ) {
        case 11 :
            cout << "Brightness configuration" << endl;
            break;
        default :
            cout << "Confusing.." << endl;
            break;
        }
    }
};


int main( int argc, char* argv[] )
{
    Camera c;
    MenuItem m1(11), m2(12);

    m1.AddListener( &c );
    m1.Command( );

    m2.AddListener( &c );
    m2.Command( );

    return 0;
}

