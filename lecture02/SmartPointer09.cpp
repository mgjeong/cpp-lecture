/**
 *  @file       SmartPointer09.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

class RefBase
{
    int count_;

public :
    RefBase( )
        : count_( 0 )
    {
    }

    virtual ~RefBase( )
    {
    }

    void IncStrong( ) { ++count_; }
    void DecStrong( ) { if( --count_ <= 0 ) delete this; }
};


class Car : public RefBase
{
public :
    Car( )
    {
        cout << "Car created.." << endl;
    }

    ~Car( )
    {
        cout << "Car destroyed.." << endl;
    }

    void Go( ) { cout << "Car go..." << endl; }
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

    p1->Go( );
    p2->Go( );

    return 0;
}

