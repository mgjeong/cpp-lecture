/**
 *  @file       TemplateArg03.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;

template< typename ... ARGS > 
class Tuple
{
};


int main( int argc, char* argv[] )
{
    Tuple< int > t1;
    Tuple< int, int > t2;
    Tuple< int, int, int > t3;

    return 0;
}

