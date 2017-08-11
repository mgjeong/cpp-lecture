/**
 *  @file       Explicit04.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
//#include <stdio.h>
#include <cstdio>
using namespace std;


class OFile
{
public :
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

