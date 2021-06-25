/**
 *  @file       SmartPointer02.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;


class Car
{
public :
    void Go( ) { cout << "Car go " << endl; }
};

class ptr
{
    Car* m_ptr;

public :
    ptr( Car* p = 0 )
        : m_ptr( p )
    {
    }

    ~ptr( )
    {
        delete m_ptr;
    }

    inline Car* operator->( ) { return this->m_ptr; }
    inline Car& operator*( ) { return *(this->m_ptr); }

};

int main( int argc, char* argv[] )
{
    ptr p = new Car;  // ptr p( new Car );

    p->Go( ); // ( p.operator->( ) )->Go( );

    (*p).Go( );

    return 0;
}

