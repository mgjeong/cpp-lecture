/**
 *  @file       TemplateArg02.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;


template< typename T >
class list
{
};


template< typename T, template< typename > class C > 
class Stack
{
//    C c; // error
    C< T > c; // okay
};


int main( int argc, char* argv[] )
{
//    list s1; // error
    list< int > s2; // okay
    Stack< int, list > st; // okay

    return 0;
}

