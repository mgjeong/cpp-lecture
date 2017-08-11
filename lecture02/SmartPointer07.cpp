/**
 *  @file       SmartPointer07.cpp
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



int main( int argc, char* argv[] )
{
    Car* p1 = new Car( );
    p1->IncStrong( );

    Car* p2 = p1;
    p2->IncStrong( );

    p2->DecStrong( );
    p1->DecStrong( );
    
    return 0;
}

