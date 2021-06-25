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
 *  @file       Shape02.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Shape
{
public :
    void Draw( void ) {
        cout << "mutex lock" << endl;
        RealDraw( );
        cout << "mutex unlock" << endl;
    }
    virtual Shape* Clone( ) { return new Shape( *this ); }

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

