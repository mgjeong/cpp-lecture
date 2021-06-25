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
 *  @file       Explicit05.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <stdio.h>
using namespace std;


class OFile
{
public :
    explicit
    OFile( const char* name, const char* mode = "wt" )
    {
        fp = fopen( name, mode );
    }

    ~OFile( )
    {
        fclose( fp );
    }

    operator FILE*( ) { return fp; }

private : 
    FILE* fp;
};



void foo( OFile f )
{

}


int main( int argc, char* argv[] )
{
    OFile f( "a.txt" );
    fputs( "hello\n", f );

    fprintf( f, "%d\n", 10 );

    //foo( f );
    foo( "hello" );

    return 0;
}

