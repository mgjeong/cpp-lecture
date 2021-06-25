/**
 *  @file       TemplateSpecialization02.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
using namespace std;


template< int N >
struct Factorial
{
    enum {
        value = N * Factorial< N-1 >::value,
    };
};

template< >
struct Factorial< 1 >
{
    enum {
        value = 1,
    };
};

int main( int argc, char* argv[] )
{
    int n = Factorial< 5 >::value;

    cout << "n = " << n << endl;

    return 0;
}

