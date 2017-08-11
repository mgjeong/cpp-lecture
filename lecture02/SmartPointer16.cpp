/**
 *  @file       SmartPointer16.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;


template< typename T >
class ptr
{
    T* m_ptr;
public :
    inline ptr( T* p = 0 )
        : m_ptr( p )
    {
    }

    inline ~ptr( )
    {
        delete m_ptr;
    }

    inline T* operator->( ) { return this->m_ptr; }
    inline T& operator*( ) { return *(this->m_ptr); }

private :
    ptr( const ptr& p );
    void operator=( const ptr& p );
};


int main( int argc, char* argv[] )
{
    ptr< int > p1 ( new int );

    *p1 = 10;
    cout << *p1 << endl;

    ptr< int > p3 ( new int[ 10 ] ); // Q ? it it right ???

    return 0;
}


