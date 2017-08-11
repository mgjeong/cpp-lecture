/**
 *  @file       SmartPointer12.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
#include <memory>
using namespace std;

struct Node {
    int data;
    weak_ptr< Node > next;

    ~Node( )
    {
        cout << "Node destroyed.." << endl;
    }
};


int main( int argc, char* argv[] )
{
    shared_ptr< Node > sp1( new Node );
    weak_ptr< Node > wp1 = sp1;

    sp1->data = 10;

    {
        shared_ptr< Node > sp2 = wp1.lock( );
        if( sp2 ) {
            cout << "sp2 has copy of sp1 .. " << endl;
            cout << "sp2->data = " << sp2->data << endl;
        }
    }

    sp1.reset( );
    shared_ptr< Node > sp3 = wp1.lock( );
    if( sp3 ) {
        cout << "It's impossible to reach here..." << endl;
    }

    return 0;
}

