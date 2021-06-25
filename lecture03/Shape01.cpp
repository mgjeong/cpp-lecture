/**
 *  @file       Shape01.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Shape
{
public :
    virtual void Draw( void ) {
        cout << "mutex lock" << endl;
        cout << "Draw Shape" << endl;
        cout << "mutex unlock" << endl;

    }

    virtual Shape* Clone( ) {
        return new Shape( *this ); 
    }
};


class Rect : public Shape
{
public :
    virtual void Draw( void ) {
        cout << "mutex lock" << endl;
        cout << "Draw Rect." << endl;
        cout << "mutex unlock" << endl;
    }

    virtual Shape* Clone( ) {
        return new Rect( *this );
    }
};

class Circle : public Shape
{
public :
    virtual void Draw( void ) {
        cout << "mutex lock" << endl;
        cout << "Draw Circle." << endl;
        cout << "mutex unlock" << endl;
    }

    virtual Shape* Clone( ) {
        return new Circle( *this ); 
    }
};


int main( int argc, char* argv[] )
{
    vector< Shape* > v;

    while( 1 ) {
        int cmd;
        cout << " 1: add Rect, 2: add Circle, 8: Clone Shape, 9: Draw, 0: Quit" << endl;
        cout << " Select : ";
        cin >> cmd;

        if( cmd == 1 ) v.push_back( new Rect );
        else if( cmd == 2 ) v.push_back( new Circle );
        else if( cmd == 8 ) {
            int k;
            cout << " Select the order ( zero based )  ";
            cin >> k;
            v.push_back( v[k]->Clone( ) );
        }
        else if( cmd == 9 ) {
            for( int i = 0; i < ( int )v.size( ); i++ )
                v[i]->Draw( );
        }
        else if( cmd == 0 ) break;
    }

    return 0;
}

