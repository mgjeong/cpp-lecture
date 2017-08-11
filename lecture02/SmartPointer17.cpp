/**
 *  @file       SmartPointer17.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;


template< typename T >
struct DefaultDelete
{
    inline void operator( )( T* p )
    {
        delete p;
        cout << "delete pointer..." << endl;
    }
};

template< typename T >
struct DefaultDelete< T[ ] >
{
    inline void operator( )( T* p )
    {
        delete [ ] p;
        cout << "delete array..." << endl;
    }
};

template< typename T, typename D = DefaultDelete< T > > 
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
        //D del;
        //del( m_ptr );
        D()(m_ptr); 
    }

    inline T* operator->( ) { return this->m_ptr; }
    inline T& operator*( ) { return *(this->m_ptr); }

private :
    ptr( const ptr& p );
    void operator=( const ptr& p );
};

template< typename T, typename D > 
class ptr< T[ ] , D >
{
    T* m_ptr;
public :
    inline ptr( T* p = 0 )
        : m_ptr( p )
    {
    }

    inline ~ptr( )
    {
        D del;
        del( m_ptr );
    }

    inline T& operator[ ]( int n ) { return *(this->m_ptr + n ); }

private :
    ptr( const ptr& p );
    void operator=( const ptr& p );
};

int main( int argc, char* argv[] )
{
    ptr< int > p1 ( new int );

    *p1 = 10;
    cout << *p1 << endl;

    ptr< int[ ] > p3 ( new int[ 10 ] );
    for( int i = 0; i < 10; i++ ) {
        p3[ i ] = i * 2;
    }

    for( int i = 0; i < 10; i++ ) {
        cout << p3[ i ] << ", ";
    }

    cout << endl;

    return 0;
}


