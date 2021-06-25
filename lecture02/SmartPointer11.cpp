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
 *  @file       SmartPointer11.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <memory>
using namespace std;

struct Node
{
    int data;
    weak_ptr< Node > next;

    ~Node( )
    {
        cout << "Node destroyed..." << endl;
    }

};


int main( int argc, char* argv[] )
{
    shared_ptr< Node > sp1 ( new Node );
    shared_ptr< Node > sp2 ( new Node );

    sp1->next = sp2;
    sp2->next = sp1;
    
    return 0;
}

