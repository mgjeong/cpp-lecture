/**
 *  @file       SmartPointer11.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
#include <memory>
using namespace std;

struct Node
{
    int data;
    weak_ptr< Node > next;

    ~Node( )
    {
        cout << "Node destroyed..." << endl;
    }

};


int main( int argc, char* argv[] )
{
    shared_ptr< Node > sp1 ( new Node );
    shared_ptr< Node > sp2 ( new Node );

    sp1->next = sp2;
    sp2->next = sp1;
    
    return 0;
}

