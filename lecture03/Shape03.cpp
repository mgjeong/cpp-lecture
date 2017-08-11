/**
 *  @file       Shape03.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Shape
{
public :
    void Draw( void )
    {
        cout << "mutex lock." << endl;
        RealDraw( );
        cout << "mutex unlock." << endl;
    }

    virtual Shape* Clone( ) = 0;

private :
    virtual void RealDraw( void ) { cout << "Draw Shape." << endl; }
};


class Rect : public Shape
{
public :
    virtual void RealDraw( void ) { cout << "Draw Rect." << endl; }
    virtual Shape* Clone( ) { return new Rect( *this ); }
};

class Circle : public Shape
{
public :
    virtual void RealDraw( void ) { cout << "Draw Circle." << endl; }
    virtual Shape* Clone( ) { return new Circle( *this ); }
};


class Triangle : public Shape
{
public :
    virtual void RealDraw( void ) { cout << "Draw Triagle." << endl; }
    virtual Shape* Clone( ) { return new Triangle( *this ); }
};

int main( int argc, char* argv[] )
{
    vector< Shape* > v;

    while( 1 ) {
        int cmd;
        cout << " 1: add Rect, 2: add Circle, 3: add Triangle, 8: Clone Shape, 9: Draw, 0: Quit" << endl;
        cout << " Select : ";
        cin >> cmd;

        if( cmd == 1 ) v.push_back( new Rect );
        else if( cmd == 2 ) v.push_back( new Circle );
        else if( cmd == 3 ) v.push_back( new Triangle );
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

