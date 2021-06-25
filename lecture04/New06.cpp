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
 *  @file       New06.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <cstdlib>
using namespace std;

/*
void* operator new( size_t sz )
{
    cout << "oerator new" << endl;
    void* p = malloc( sz );
    if( p == 0 ) {
        throw std::bad_alloc( );
    }

    return p;
}
*/

struct my_nothrow_t {
};

void* operator new( size_t sz, my_nothrow_t nothrow )
{   
    cout << "operator new my_nothrow" << endl;
//    void* p = malloc( sz );
    void* p = 0;

    return p;
}


//#define new new(my_nothrow)

int main( int argc, char* argv[] )
{
    int* p1 = new int;
    
    if( p1 == 0 ) {
        cout << "Not enough memory." << endl;
    }
    else {
        cout << "p1 is allocated.. " << p1 << endl;
        delete p1;
    }


    int* p2;
    try {
        p2 = new int;
        cout << "p2 is allocated.." << p2 << endl;
        delete p2;
    }
    catch( std::bad_alloc& e ) {
        cout << "not enough memory.." << endl;
    }

    my_nothrow_t my_nothrow;
    int* p3 = new( my_nothrow ) int;
    cout << "p3 is allocated.." << p3 << endl;
    delete p3;

    return 0;
}

