/**
 *  @file       SIngleton04.cpp
 *  @author     mg.jeong <mg.jeong@gmail.com>
 */

#include <iostream>
#include <typeinfo>
using namespace std;


class Mutex
{
public :
    void Lock( )
    {
        cout << "Mutex lock" << endl;
    }

    void Unlock( )
    {
        cout << "Mutex unlock" << endl;
    }

    class Autolock
    {
    public :
        Autolock( Mutex& m )
            : mtx( m )
        {
            mtx.Lock( );
        }

        ~Autolock( )
        {
            mtx.Unlock( );
        }
    private :
        Mutex& mtx;
    };
};


template< typename T > class Singleton 
{
protected :
    Singleton( )
    {
        cout << typeid(T).name( )  << " Singleton created" << endl;
    }

private :
    Singleton( const Singleton& c );
    void operator=( const Singleton& c );
    static T* pInstance;
    static Mutex sLock;

public :
    static T& GetInstance( ) 
    {
        Mutex::Autolock autolock( sLock );

        if( pInstance == 0 )
            pInstance = new T( );

        return *pInstance;
    }

    ~Singleton( )
    {
        cout << "Singleton deleted" << endl;
    }
};


template< typename T > T* Singleton<T>::pInstance = NULL;
template< typename T > Mutex Singleton<T>::sLock;


class DoorService : public Singleton< DoorService >
{
};

class CateringService : public Singleton< CateringService >
{
};

class AAA 
{
public :
    void Print( void )
    {
        cout << "AAA..." << endl;
    }
};

int main( int argc, char* argv[] )
{
    DoorService& d1 = DoorService::GetInstance( );
    DoorService& d2 = DoorService::GetInstance( );

    CateringService& t1 = CateringService::GetInstance( );

    AAA& a1 = Singleton< AAA >::GetInstance( );
    //AAA& a1 = AAA::GetInstance( );
    a1.Print( );

    return 0;
}


