/**
 *  @file       Virtual02.cpp
 *  @author     mg.jeong <myeong.jeong@samsung.com>
 */

#include <iostream>
#include <cstring>
//using namespace std;

class Animal
{
public :
    Animal( const char* n )
    {
        name = new char[ strlen( n ) ];
        strcpy( name, n );
    }

    virtual ~Animal( )
    {
        delete [] name;
    }

    const char* GetName( ) const
    {
        return name;
    }

    friend std::ostream& operator<< ( std::ostream& os, const Animal& animal )
    {
        return os << animal.GetName( ) << "(Animal)";
    }

private :
    char*   name;
};


class Dog : public Animal
{
public :
    Dog( const char* n )
        : Animal( n )
    {
    }


    friend std::ostream& operator<< ( std::ostream& os, const Dog& dog  )
    {
        return os << dog.GetName( ) << "(Dog)";;
    }
};


void foo( Animal* p )
{
    std::cout << *p << std::endl;
}


int main( int argc, char* argv[] )
{
    Animal animal("pooh");
    Dog dog( "pluto" );

    std::cout << animal << std::endl;
    std::cout << dog << std::endl;

    foo( &animal );
    foo( &dog );

    return 0;
}

