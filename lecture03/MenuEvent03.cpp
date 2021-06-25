/*******************************************************************************
 * Copyright 2021 MJ All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *******************************************************************************/

/**
 *  @file       MenuEvent02.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
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

