/**
 *  @file       CodeBloat01.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;



template< typename T >
class Vector
{
    T* buff;
    int sz;
public :
    int Size( ) { return sz; }
    bool Empty( ) { return sz == 0; }
    inline void Push( const T& a ) { }
};


int main( int argc, char* argv[] )
{
    Vector< int > s1;
    Vector< double > s2;

    return 0;
}

