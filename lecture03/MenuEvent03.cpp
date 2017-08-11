/**
 *  @file       MenuEvent02.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
#include <vector>

using namespace std;


class Camera 
{
public :
    void TakePicture( void ) {
        cout << "Take a picture,," << endl;
    }

    void BrightnessControl( void ) {
        cout << "Brightness configuration." << endl;
    }
};


class MenuItem
{
public :
    MenuItem(  )
    {
    }

    void SetCameraHandler( Camera* c, void ( Camera::*f )( ) ) {
        obj = c;
        handler = f;
    }

    virtual void Command( ) {
        ( obj->*handler )( );
    }

private :
    Camera* obj;
    void ( Camera::*handler )( );
};


int main( int argc, char* argv[] )
{
    Camera c;
    MenuItem m;

    //m.SetCameraHandler( &c, &Camera::TakePicture );
    m.SetCameraHandler( &c, &Camera::BrightnessControl );

    m.Command( );

    return 0;
}

