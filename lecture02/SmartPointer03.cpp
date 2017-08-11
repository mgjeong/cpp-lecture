/**
 *  @file       SmartPointer03.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;

template< typename T >
class ptr
{
    T* ptr_;

public :
    ptr( T* p = 0 )
        : ptr_( p )
    {
    }

    ~ptr( )
    {
        delete ptr_;
    }

    inline T* operator->( ) { return this->ptr_; }
    inline T& operator*( ) { return *( this->ptr_ ); }
};


int main( int argc, char* argv[] )
{
    ptr< int > p1 = new int;

    *p1 = 10;

    cout << "*p1 = " << *p1 << endl;

    return 0;
}

