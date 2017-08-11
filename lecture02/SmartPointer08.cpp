/**
 *  @file       SmartPointer08.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;

class Car
{
    int count_;
public :
    Car( )
        : count_ ( 0 )
    {
        cout << "Car created.." << endl;
    }

    ~Car( )
    {
        cout << "Car destroyed.." << endl;
    }

    void IncStrong( void ) { ++count_; }
    void DecStrong( void ) { if( --count_ <= 0 ) delete this; }
};


template< typename T >
class sp
{
    T* ptr_;

public :
    sp( T* p = 0 )
        : ptr_( p )
    {
        if( ptr_ ) ptr_->IncStrong( );
    }

    sp( const sp& p )
        : ptr_ ( p.ptr_ )
    {
        if( ptr_ ) ptr_->IncStrong( );
    }

    ~sp( )
    {
        if( ptr_ ) ptr_->DecStrong( );
    }

    inline T* operator->( ) { return this->ptr_; }
    inline T& operator*( ) { return *(this->ptr_); }
};



int main( int argc, char* argv[] )
{
    sp< Car > p1 = sp< Car >( new Car );
    sp< Car > p2 = p1;

    return 0;
}

