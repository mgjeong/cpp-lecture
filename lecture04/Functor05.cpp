/**
 *  @file       Functor05.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;


template< typename T1, typename T2, typename TR > 
struct Binary_function
{
    typedef T1 first_argument_type;
    typedef T2 second_argument_type;
    typedef TR result_type;
};


//struct Plus : public binary_function< int, int, int > // alread defined.
struct Plus : public Binary_function< int, int, int >
{
    int operator( )( int a, int b ) { return a+b; }
};


int main( int argc, char* argv[] )
{
    Plus p;
    int n = p( 1, 2 );
    cout << n << endl; // 3

    return 0;
}

