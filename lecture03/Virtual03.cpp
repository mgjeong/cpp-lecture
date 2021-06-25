/**
 *  @file       Virtual03.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
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

    virtual std::ostream& Print( std::ostream& os ) const
    {
        return os << GetName( ) << " (Animal)";
    }

    friend std::ostream& operator<< ( std::ostream& os, const Animal& animal )    
    {
        return animal.Print( os ); 
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

    virtual std::ostream& Print( std::ostream& os ) const 
    {
        return os << GetName( ) << " (Dog)";
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

