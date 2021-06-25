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
 *  @file       SmartPointer12.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <memory>
using namespace std;

struct Node {
    int data;
    weak_ptr< Node > next;

    ~Node( )
    {
        cout << "Node destroyed.." << endl;
    }
};


int main( int argc, char* argv[] )
{
    shared_ptr< Node > sp1( new Node );
    weak_ptr< Node > wp1 = sp1;

    sp1->data = 10;

    {
        shared_ptr< Node > sp2 = wp1.lock( );
        if( sp2 ) {
            cout << "sp2 has copy of sp1 .. " << endl;
            cout << "sp2->data = " << sp2->data << endl;
        }
    }

    sp1.reset( );
    shared_ptr< Node > sp3 = wp1.lock( );
    if( sp3 ) {
        cout << "It's impossible to reach here..." << endl;
    }

    return 0;
}

