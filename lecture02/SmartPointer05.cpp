/**
 *  @file       SmartPointer05.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;

template< typename T >
class ptr
{
    T* ptr_;
    int* ref_;

public :
    ptr( T* p = 0 )
        : ptr_( p )
    {
        ref_ = new int( 1 );
    }

    ptr( const ptr& p )
        : ptr_( p.ptr_ ), ref_( p.ref_ )
    {
        ++( *ref_ );
    }

    ~ptr( )
    {
        if( --( *ref_ ) <= 0 ) {
            delete ptr_;
            delete ref_;
        }
    }

    inline T* operator->( ) { return this->ptr_; }
    inline T& operator*( ) { return *( this->ptr_ ); }
};


int main( int argc, char* argv[] )
{
    ptr< int > p1 = new int;

    *p1 = 10;

    cout << "*p1 = " << *p1 << endl;

    ptr< int > p2 = p1;

    cout << "*p2 = " << *p2 << endl;

    return 0;
}

