/**
 *  @file       SmartPointer10.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
#include <memory>
using namespace std;

struct Node
{
    int data;
    shared_ptr< Node > next;

    ~Node( )
    {
        cout << "Node destroyed..." << endl;
    }

};


int main( int argc, char* argv[] )
{
    shared_ptr< Node > p1 ( new Node );
    shared_ptr< Node > p2 ( new Node );

    p1->next = p2;
    p2->next = p1;
    
    return 0;
}

