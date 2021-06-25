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
 *  @file       New05.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;


void func1( )
{
    vector< int > v( 10, 3 );   // allocate 10 item with 3
    cout << "v.size( ) = " <<  v.size( ) << endl;
    cout << "v.capacity( ) = " << v.capacity( ) << endl;

    v.resize( 5 );  // change the size to 5
    cout << "v.size( ) = " <<  v.size( ) << endl;
    cout << "v.capacity( ) = " << v.capacity( ) << endl;

    v.push_back( 1 );
    cout << "v.size( ) = " <<  v.size( ) << endl;
    cout << "v.capacity( ) = " << v.capacity( ) << endl;

    v.shrink_to_fit( ); // change capacity to size
    cout << "v.size( ) = " <<  v.size( ) << endl;
    cout << "v.capacity( ) = " << v.capacity( ) << endl;
}


class DBConnect
{
public :
    DBConnect( ) { cout << "Create DBConnect" << endl; }
    ~DBConnect( ) { cout << "Destroy DBConnect" << endl; }
};

void func2( )
{
    cout << "Create vector.." << endl;
    vector< DBConnect > v( 10 );
    cout << "v.size( ) = " <<  v.size( ) << endl;
    cout << "v.capacity( ) = " << v.capacity( ) << endl;

    cout << "Resize vector.. 10 -> 5" << endl;
    v.resize( 5 );
    cout << "v.size( ) = " <<  v.size( ) << endl;
    cout << "v.capacity( ) = " << v.capacity( ) << endl;

    cout << "Resize vector.. 5 -> 6" << endl;
    v.resize( 6 );
    cout << "v.size( ) = " <<  v.size( ) << endl;
    cout << "v.capacity( ) = " << v.capacity( ) << endl;

    cout << "Shrink vector.. 10 -> 6" << endl;
    v.shrink_to_fit( );
    cout << "v.size( ) = " << v.size( ) << endl;
    cout << "v.capacity( ) = " << v.capacity( ) << endl;
};


#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

class Queue
{
public :
    Queue( ) { cout << "Create Queue" << endl; }
    ~Queue( ) { cout << "Destroy Queue" << endl; }
};

void func3( )
{
    Queue* q = new Queue;
    delete q;
    
    int fd = open( "test_mmap", O_RDWR|O_CREAT, 0664 );
    Queue* q2 = ( Queue* ) mmap( NULL,  sizeof( Queue ), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0 );
    new( &q2 ) Queue( );

    q2->~Queue( );
    munmap( q2, sizeof( Queue) );
}


int main( int argc, char* argv[ ] )
{
    func1( );

    func2( );

    func3( );
    
    return 0;
}
