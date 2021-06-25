/**
 *  @file       TemplateSpecialization01.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;


template< typename T >
class Stack
{
public :
    void Push( )
    {
        cout << "T" << endl;
    }
};

template< typename T >
class Stack< T* >
{
public :
    void Push( )
    {
        cout << "T*" << endl;
    }
};

template< >
class Stack< char* >
{
public :
    void Push( )
    {
        cout << "char*" << endl;
    }
};


int main( int argc, char* argv[] )
{
    Stack< int > s1;
    Stack< int* > s2;
    Stack< char* > s3;

    s1.Push( );
    s2.Push( );
    s3.Push( );

    return 0;
}

