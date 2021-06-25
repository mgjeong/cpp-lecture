/**
 *  @file       New03.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#ifdef DEBUG
struct BLOCK_INFO {
    char    file[ 256 ];
    int     line;
    void*   addr;
};

BLOCK_INFO mem[ 10000 ];
int count = 0;

void* operator new( size_t sz, char* file, int n )
{
    void* p = malloc( sz );
    mem[ count ].line = n;
    mem[ count ].addr = p;
    strcpy( mem[ count ].file, file );
    ++count;
    cout << "my new" << endl;

    return p;
}

void operator delete( void* p )
{
    for( int i = 0; i < count; i++ ) {
        if( mem[ i ].addr == p ) {
            mem[ i ] = mem[ count-1 ];
            free( p );
            --count;
            break;
        }
    }

    cout << "my delete" << endl;
}

#define new new( __FILE__, __LINE__ )

int Main( );

int main( )
{
    int ret = Main( );

    if( count == 0 ) {
        cout << "no memory leakage.." << endl; 
    }
    else {
        cout << count<< " memory leakage detected." << endl;
        for( int i = 0; i < count; i++ ) {
            cout << i << ", " << mem[i].file << "(" << mem[i].line << " : " << mem[i].addr << endl;
        }
    }

    return ret;
}


__attribute__((destructor)) void fin( )
{
    cout << "finished.." << endl;
}


#define main Main
#endif



int main( )
{
    int* p1 = new int;
    int* p2 = new int;
    int* p3 = new int;

    delete p2;

    return 0;
}

