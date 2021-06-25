/**
 *  @file       AbstractClass01.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;


class Shape
{
public :
    virtual Shape* Clone( ) = 0;
};

class Rect : public Shape
{
//public :
//    virtual Shape* Clone( ) { cout << " Clone rect " << endl; }
};


int main( int argc, char* argv[] )
{
    Rect r;
    r.Clone( );

    return 0;
}

