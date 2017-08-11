/**
 *  @file       TemplateArg01.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
using namespace std;


template< typename T = int, int N = 10 > class Stack
{
    T buff[ N ];
};


int main( int argc, char* argv[] )
{
    int a = 10;
    Stack< int, 10 > s1;    // okay
    //Stack< int, a > s2;     // error

    Stack< int > s3;        // okay
    Stack<> s4;             // okay..

    return 0;
}

