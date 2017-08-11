# C++ Lecture 

___
## Day 4
### Synopsis
- Creation : 2015. 06. 04
- Last Modified : 2017. 07. 19
- Version : 1.1
- Author : MJ( mg.jeong )
___
### Contents
- RTTI
- new
- 함수 템플릿(추가)
- 클래스 템플릿
- 멤버 함수 템플릿
- typename
- valuetype
- 템플릿 인자
- 함수 객체
- int2type
- 자명한 생성자
- 다중 상속


<p>
___
<p>
### RTTI( Run-Time Type Identification )
1. 특정 포인터가 정말 어떤 객체를 가리키고 있었는지 조사하는 기술.<br>
핵심은 가상 함수 테이블 내의 type_info를 확인하는 것이다.

2. 가상 함수 테이블로 관리되므로, 가상 함수가 1개 이상 있어야 제대로 동작한다.<br>
가상 함수가 없는 경우 포인터 타입으로만 판단해 준다.<br>
꼭 필요한 경우, 소멸자를 가상함수로 선언하자.

3. `if( typeid( *p ) == typeid( Dog ) )` 으로 알아낸다.<br>
C#에서는 `if( p is Dog )` 이라고 쓴다. 같은 거다.

4. `Dog* pDog = dynamic_cast< Dog* >( p )`로 조사할 수 도 있다.<br>
down cast 시 0을 리턴하므로 0이 아닐 경우만 쓰면 된다.<br>
C# 에서는 `Dog pDog = p as Dog;` 이라고 쓴다… 같은 거다.


- 코드를 보면서 이해하자. 다음 코드를 보자.
```
    // file : RTTI01.cpp
	#include <iostream>
    #include <typeinfo>
    using namespace std;

    class Animal
    {
    public :
        virtual ~Animal( ) { }
    };

    class Dog : public Animal
    {
    public :
        int color;
    };

    void foo( Animal* p )
    {
        const type_info& t1 = typeid( *p );
        cout << t1.name( ) << endl;

        const type_info& t2 = typeid( Dog );
        if( t1 == t2 ) {
            cout << “p is a Dog.” << endl;
        }
    }

    int main( )
    {
        Animal a; foo( &a );
        Dog d; foo( &d );
    }
```
>- `foo` 함수 내에서 모든 `Animal`에 공통적인 작업을 수행하도록 프로그래밍 했다.
>- 아무런 문제 없었는데,,, 나중에 추가하고 싶은 코드가 생겼다…<br>
> `p->color = 10;`
>-  그런데 이걸 하려면,, `p`가 `Dog` 인지 아닌지 구분해야 한다….
>- 그래서 가상함수 table로 관리되는 `type_info` 객체를 꺼내서 비교한다…
>- 실제 코드는 다음과 같이 하면 된다.
```
	if( typeid( *p ) == typeid( Dog ) ) {
    	cout << “p is a Dog.” << endl;
    	Dog* pDog = static_cast< Dog* >( p );
    	pDog->color = 10;
	}
```

- 다른 방법을 알아보자. 다음 코드를 보자. ( RTTI01.cpp 파일에 추가 )
```
    // file : RTTI02.cpp
	#include <iostream>
    #include <typeinfo>
    using namespace std;

    class Animal
    {
    public :
        virtual ~Animal( ) { }
    };

    class Dog : public Animal
    {
    public :
        int color;
    };

    class Cat : public Animal
    {
    public :
        int type;
    };

    void foo( Animal* p )
    {
        Dog* pDog = dynamic_cast< Dog* >( p );
        cout << pDog << endl;
        if( pDog ) {
            cout << “p is a Dog” << endl;
            pDog->color = 10;
        }
    }

    int main( )
    {
        Animal a; foo( &a );
        Dog d; foo( &d );
        Cat c; foo( &c );
    }
```
>- 또 다른 방법은,, 무조건 casting 한다..
>- `static_cast`는 downcasting 조사가 안된다..
>- `dynamic_cast`는 downcasting시 0이 리턴되므로 0이 아닌 경우라면 사용하면 된다.

- RTTI를 직접 만들어 보자.
- 대부분의 라이브러리가 자신만의 RTTI를 제공한다. ( MFC, Android, QT, … )
- RTTI의 핵심은 `type_info`.. 즉 모든 클래스가 공유하는 `type_info`만 있으면 된다.. --> `static`
- 라이브러리 내에 모든 클래스가 아래의 조건을 만족하기로 한다. ( like Android )
	- 모든 클래스에는 `String16` 형태의 `descriptor`라는 `static` 변수가 있다.
	- `descriptor`는 자신의 클래스 이름으로 초기화 한다.
	- `descriptor`의 참조를 리턴하는 `getInterfaceDescriptor( )` 가상 함수가 있다.

- 다음 코드를 보자. ( RTTI02.cpp 에서 수정 )
```
    // file : RTTI03.cpp
	#include <iostream>
    #include <string>
    using namespace std;

    typedef string String16;

    class Animal
    {
    public :
        virtual ~Animal( ) { }
        static const String16 descriptor:
        virtual const String16& getInterfaceDescriptor( ) const {
            return descriptor;
        }
    };
    const String16 Animal::descriptor( “Animal” );

    class Dog : public Animal
    {
    public :
        virtual ~Dog( ) { }
        static const String16 descriptor:
        virtual const String16& getInterfaceDescriptor( ) const {
            return descriptor;
        }
    };
    const String16 Dog::descriptor( “Dog” );

    void foo( Animal* p )
    {
    	if( p->getInterfaceDescriptor( ) == Dog::descriptor ) {
            cout << “p is a Dog” << endl;
    	}
    }

    int main( )
    {
        Animal a; foo( &a );
        Dog d; foo( &d );
    }
```
>- `static` 변수는 상속안된다. 컴파일 시간에 결정되므로 모든 코드를 다 써야 한다.
>- 중복이 보이니, macro화 하자..

- 다음 코드를 보자.( RTTI03.cpp 에서 수정 )
```
    // file : RTTI04.cpp
	#include <iostream>
    #include <string>
    using namespace std;

    typedef string String16;

    #define DECALRE_META_INTERFACE( INTERFACE )                  \
        public :                                                 \
        static const String16 descriptor:                        \
        virtual const String16& getInterfaceDescriptor( ) const; \

    #define IMPLEMENT_META_INTERFACE( INTERFACE, NAME )                 \
        const String16 INTERFACE::descriptor( NAME );                   \
        const String16& INTERFACE::getInterfaceDescriptor( ) const {	\
            return INTERFACE::descriptor;                               \
        }

    class Animal
    {
        DECLARE_META_INTERFACE( Animal )
    };
    IMPLEMENT_META_INTERFACE( Animal, “Animal” )

    class Dog : public Animal
    {
        DECLARE_META_INTERFACE( Dog )
    };
    IMPLEMENT_META_INTERFACE( Dog, “Dog” )

    void foo( Animal* p )
    {
    	if( p->getInterfaceDescriptor( ) == Dog::descriptor ) {
            cout << “p is a Dog” << endl;
    	}
    }

    int main( )
    {
        Animal a; foo( &a );
        Dog d; foo( &d );
    }
```
>- 안드로이드 코드가 이렇게 되어 있다.<br>
native/include/binder/IInterface.h


<p>
___
<p>
### new
1. `new`의 정확한 동작 방식을 이해하자.
	1. `operator new( )` 함수를 호출해서 메모리를 할당한다. – `malloc` 이다.
	2. 메모리가 할당된 뒤, 객체라면 생성자를 호출한다…
	3. 해당 타입으로 캐스팅해서 리턴한다…

- 다음 코드를 보자.
```
    // file : New01.cpp
	#include <iostream>
    using namespace std;

    class Point
    {
    public :
        Point( )
        	: x( 0 ), y( 0 )
        {
        	cout << “constructor” << endl;
        }

        ~Point( )
        {
        	cout << “destroyer” << endl;
        }

        void Print( ) const
        {
        	cout << x << “, “ << y << endl;
        }

        void Set( int a, int b )
        {
        	x = a; y = b;
        }

    private :
        int x;
        int y;
    };

    int main( )
    {
        Point* p1 = new Point;
        p1->Print( );
        delete p1;

        Point* p2 = static_cast< Point* >( ::operator new( sizeof( Point ) ) );
        p2->Set( 10, 20 );
        p2->Print( );

        ::operator delete( p2 );
    }
```
>- `p1`에 대해서는 memory allocation + constructor 호출 및 destroyer + memory free 가 동작
>- `p2`에 대해서는 constructor/destroyer 없이 memory allocation/free 만 동작

- `operator new`를 재정의 하여 메모리 할당 방식을 변경 할 수 있다.
- `new` 자체를 재정의 하는 것은 불가능하다.
- 다음 코드를 보자.
```
    // file : New02.cpp
	#include <iostream>
    #include <cstdlib>
    using namespace std;

    void* operator new( size_t sz )  // (1)
    {
        cout << “my new” << endl;
        return malloc( sz );
    }

    void operator delete( void* p )
    {
        cout << “my delete” << endl;
        free( p );
    }

    void* operator new( size_t sz, char* s, int n ) // (2)
    {
        cout << “my new 2“ << endl;
        return malloc( sz );
    }

    int main( )
    {
        int* p1 = new int;    // a. use (1) 
        delete p1;

        int* p2 = new( “AAA”, 3 ) int;   // b. use (2)
        delete p2;
    }
```
>- `p1`은 parameter가 하나인 `operator new`를 호출하고,<br>
`p2`은 parameter가 세 개인 `operator new`를 호출한다.
>- `operator new`를 오버로딩할 때, 첫 번째 인자는 무조건 `size_t` 이어야 한다.

- 이걸 언제 쓰냐 ?? 어떤 경우에 사용하면 되냐 ???
- 메모리 관리 또는 메모리 검사를 위해 사용할 수 있다.
- 다음 코드를 보자..
```
    // file : New03.cpp
    #include <iostream>
    #include <cstring>
    #include <cstdlib>
    using namespace std;

    #ifdef DEBUG
    struct BLOCK_INFO {
        char    file[ 256 ];
        int     line;
        void*   addr;
    };

    BLOCK_INFO mem[ 10000 ];
    int count = 0;

    void* operator new( size_t sz, char* file, int n )
    {
        void* p = malloc( sz );
        mem[ count ].line = n;
        mem[ count ].addr = p;
        strcpy( mem[ count ].file, file );
        ++count;
        cout << “my new” << endl;
    	return p;
    }

    void operator delete( void* p )
    {
        for( int i = 0; i < count; i++ ) {
            if( mem[ i ].addr == p ) {
                mem[ i ] = mem[ count-1 ];
                free( p );
                --count;
                break;
            }
        }
        cout << “my delete” << endl;
    }

    #define new new( __FILE__, __LINE__ )

    int Main( );

    int main( )
    {
        int ret = Main( );
        if( count == 0 ) {
            cout << “no memory leakage..” << endl;
        }
        else {
            cout << count << “ memory leakage detected.” << endl;
            for( int I = 0; I < count; i++ ) {
                cout << I << “, “ << mem[i].file << “(“ << mem[i].line << “ : “ << mem[i].addr << endl;
            }
        }
        return ret;
    }

    #define main Main
    #endif

    int main( )
    {
        int* p1 = new int;
        int* p2 = new int;
        int* p3 = new int;

        delete p2;

        return 0;
    }
```
>- `DEBUG` 선언이 된 상태로 빌드를 하면,
>>- `new`는 `new( __FILE__, __LINE__ )` 으로 overloading된 `operator_new`를 호출하도록 한다.
>>- `main` 함수는 `Main` 함수로 변경된다. 맨 마지막에 `define main Main` 되어 있는 이유를 알아야 한다.

>- (TIP) 조사하는 방법으로 컴파일러 확장 문법을 사용해도 된다.
```
    __attribute__((destructor)) void fini( ) 
    {
    }
```
- Placement new 에 대하여 살펴보자.
	- 원하는 메모리 위치를 지정(placement)하여 `new`를 호출하는 기술이다.
```
    void* operator new( size_t sz, void* p )
    {
        return p;
    }
```

- 다음 코드를 보자.( New01.cpp 에서 수정 )
```
    // file : New04.cpp
	#include <iostream>
    using namespace std;

	class Point
    {
    public :
        Point( int a = 0, int b = 0 )
    		: x( a ), y( b )
    	{
        	cout << “constructor” << endl;
        }

        ~Point( )
        {
        	cout << “destroyer” << endl;
        }

    private :
        int x;
        int y;
    };

    int main( )
    {
        Point p1( 1, 1 );
        p1.Point( 2, 2 ); // error !!!!

        new( &p1 ) Point( 2, 2 );

        p1.~Point( ); // okay…

        Point* p2 = new Point( 3, 3 );
        delete p2;
    }
```
>- `p1`을 만들면서 값을 설정했다.
>- 어차피 생성자도 `public` 인데, `Set` 함수 만들지 말고, 생성자 호출하면 안될까 ??? <br>
이게 에러를 발생시킨다.. 불가능하다..
>- 그래서 이미 만들 메모리 영역에 생성자를 다시 호출하는 기술이 placement new 이다.
>- 소멸자는 명시적으로 호출 가능하다…

- 왜 생성자와 소멸자의 명시적 호출이 필요한 것인가 ???
	- `vector`와 같은 메모리의 효율적 관리에 사용될 수 있는데, 
	- 우선 `vector`가 어떻게 동작하는 지 살펴보고 실제 클래스를 생각해보자
	
- 다음 코드를 보자.
```
    // file : New05.cpp
	#include <iostream>
    #include <vector>
    using namespace std;

    void func1( )
    {
        vector< int > v( 10, 3 );
        cout << “v.size( ) = “ << v.size( ) << endl;                   // 10
    	cout << “v.capacity( ) = “ << v.capacity( ) << endl;           // 10

        v.resize( 5 );
    	cout << “v.size( ) = “ << v.size( ) << endl;                   // 5
    	cout << “v.capacity( ) = “ << v.capacity( ) << endl;           // 10

    	v.push_back( 5 );
    	cout << “v.size( ) = “ << v.size( ) << endl;                   // 6
    	cout << “v.capacity( ) = “ << v.capacity( ) << endl;           // 10

        v.shrink_to_fit( );
    	cout << “v.size( ) = “ << v.size( ) << endl;                   // 6
    	cout << “v.capacity( ) = “ << v.capacity( ) << endl;           // 6
    }

    class DBConnect
    {
    };

    void func2( )
    {
        vector< DBConnect > v(10);
        v.resize( 5 );
        v.resize( 6 );
    };

    #include <sys/types.h>
    #include <sys/mman.h>
    #include <sys/stat.h>
    #include <fcntl.h>

    class Queue
    {
    };

    void func3( )
    {
        Queue* q = new Queue;

        int fd = open( “test_mmap”, O_RDWR | O_CREAT, 0664 );
        Queue* q2 = ( Queue* ) mmap( NULL, sizeof( Queue ), PROT_READ | PROT_WRITE, MAP_SHAHRED, fd, 0 );
        new( &q2 ) Queue( );
        // . . . 
        q2->~Queue( );
        munmap( q2, sizeof( Queue ) );
    }

    int main( )
    {
        func1( );
        func2( );
        func3( );
    }
```
>- `func1( )` 함수에서
>>- `int` 타입 10개 짜리 벡터 `v`를 만든다. ( 초기값은 모두 3이다. )
>>- 크기( size )는 `10`, 담을 수 있는 용량은 `10`.
>>- 크기를 `5`로 바꾸어도 용량은 `10`에서 변하지 않는다. ( 다시 늘어날 수 있으니까.. )
>>- 벡터에 `push_back` 하면 크기는 하나 늘어난다..용량은 그대로다..
>>- `shrink_to_fit` 하면 capacity를 size에 맞춘다.

>- DB와의 연결을 담당하는 클래스를 `DBConnect` 라고 하고, 생성자에서 연결, 소멸자에서 연결 종료를 담당한다고 하자.
>- `func2( )` 함수에서,
>>- `v.resize( 5 )` 에서,  실제 메모리가 줄어들지는 않는다, 즉 객체는 메모리에 `10`개가 남아있는 상황인데, 사용하지 않는 `5`개의 객체는 소멸자 함수를 호출해야 한다.
>>- `v.resize( 6 )` 에서, 이미 6번째 객체는 메모리에 있다, 하지만 생성자 함수를 호출하여 DB연결은 수행해야 한다. 이 때 이미 존재하는 객체의 생성자 호출 기술(placement new )이 필요하다.
>- 시스템 프로그램에서 클래스를 사용할 때, `func3( )` 함수에서 
>>-공유 메모리에 `Queue`를 만들고 싶을 때, 이 때 메모리를 먼저 공유 메모리 공간에 할당하고( `mmap` ) 나중에 객체 초기화를 수행할 때 사용한다.

- C++ 표준에서 지원하는 new에는 세 가지가 있다.
	- standard new : 실패 시 exception ( std::bad_alloc ) 발생
	- new( nothrow ) : 실패 시 0 리턴
	- placement new : 이미 존재하는 객체의 생성자를 호출하기 위한 기술

- new( nothrow )를 직접 만들어 보자.
- 다음 코드를 보자.
```
    // file : New06.cpp
	#include <iostream>
    #include <cstdlib>
    using namespace std;

    void* operator new( size_t sz )
    {
        cout << “operator new” << endl;
        void* p = malloc( sz );
        if( p == 0 ) throw std::bad_alloc( );

        return p;
    }

    // parameter for overloading… empty class !!!
    struct my_nothrow_t
    {
    };

    void* operator new( size_t sz, my_nothrow_t )
    {
        cout << “operator new nothrow” << endl;
        void* p = malloc( sz );
        return p;
    }

    int main( )
    {
        int* p1 = new int;
        if( p1 == 0 ) {
            cout << “not enough memory.” << endl;
        }
        else {
            delete p1;
    	}

        int* p2;
        try {
            p2 = new int;
            delete p2;
        }
        catch( std::bad_alloc& e ) {
            cout << “not enough memory.” << endl;
        }

        my_nothrow_t my_nothrow;
        int* p3 = new( my_nothrow ) int;
        delete p3;

    }
```
>- `operator new( size_t )` 는 표준 `new` 에서 사용하는 방법이다.
>- `operator new( size_t, my_nothrow )` 는 실패 시 `0` 을 리턴하기 위한 오버로딩 함수이다.
>>- 오버로딩에 필요한 함수 파라미터를 추가하기 위해 크기가 `1`인 empty class( `my_nothrow_t` )를 선언하여 사용한다.
>>- 표준에는 `<new>` 헤더파일에 `nothrow_t` 가 선언되어 있다.


<p>
___
<p>
### 함수 템플릿
1. 일반 함수를 `template`으로 작성할 때 파라미터 타입에 대한 정확한 정보를 얻어야 할 때가 있다.
2. 다음 두 템플릿의 차이점을 구분할 수 있어야 한다.
```
template< typename T > void foo( T a );
template< typename T> void foo( T& a );
```
- 함수의 파라미터를 `T`로 하면,
	- 배열 => 포인터, 문자열 => 문자열 포인터, 함수 => 함수 포인터로 변환되어 전달된다.
	- Decay 라는 현상이다.
- 함수의 파라미터를 `T&`로 하면
	- 정확한 타입을 받을 수 있다.

- 다음 코드를 보자.
```
    // file : FunctionTemplate01.cpp
	#include <iostream>
    #include <typeinfo>
    using namespace std;

    template< typename T > void foo( T a )
    {
        cout << typeid( a ).name( ) << endl;
    }

    template< typename T > void goo( T& a )
    {
        cout << typeid( a ).name( ) << endl;
    }

    int main( )
    {
        int n = 10, x[ 10 ];

        foo( n ); foo( x ); foo( “AAA” ); foo( main );
        goo( n ); goo( x ); goo( “AAA” ); goo( main );

    }
```
>- 출력을 확인하여 서로 다른 타입을 나타내는 것을 확인하자.

- 코드 생성기(`template`)을 활용할 때 배열은 크기에 따라 타입이 다르게 인식된다. 문자열을 보낼 때는 조심해야 한다.
- 다음 코드를 보자.
```
    // file : FunctionTemplate02.cpp

    template< typename T > void foo( T a , T b )
    {
    }

    template< typename T > void goo( T& a , T& b )
    {
    }

    void hoo( const char* s1, const char* s2 )
    {
    }

    void moo( const char s1[], const char s2[] )
    {
    }

    int main( )
    {
        foo( “orange”, “kiwi” ); // okay
        goo( “orange”, “kiwi” ); // error
        hoo( “orange”, “kiwi” ); // okay
        moo( “orange”, “kiwi” ); // okay
    }
```
>- `goo` 함수는 정확한 타입`( char[7], char[5] )`를 인자로 받은 함수가 없기 때문에 빌드 오류.
>- 다음과 같이 작성하면 빌드가 가능하다.
```
template< typename T > void goo( const T a[7], const T b[5] );
```

- 문자열 전용 함수를 제공하여 문제를 해결한다…
- 함수를 찾는 순서는 다음과 같다.
	1. 정확한 타입을 찾는다.  -> `char[ ]`를 인자로 하는 함수
	2. 변환 가능한 타입을 찾는다. -> `char*`를 인자로 하는 함수
	3. 없으면 `template`을 사용한다.


<p>
___
<p>
### 클래스 템플릿
1. 생성자와 복사 생성자를 만들 때, 정확한 선언 방법을 확인하자.
- 다음 코드를 보자.
```
    // file : ClassTemplate01.cpp

    template< typename T >
    class Stack
    {
        T* buff;
    public :
        Stack( ) { }        // 1. ok..
        Stack< T >(  ) { }  // 2. error…

        Stack( const Stack& s ) { }       // 1. error, but acceptable
        Stack( const Stack< T >& s ) { } // 2. ok.. parameter should be ‘type’

        void Push( const T& a );  // separate declaration and implementation 

        template< typename U > T foo( U a ); // separate declaration and implementation
    };

    template< typename T >
    void Stack< T >::Push( const T& a )
    {
    }

    template< typename T > template< typename U >
    T Stack< T >::foo( U a )
    {
    }

    int main( )
    {
        Stack< int > s1;          // okay.
        Stack s2;                 // error;
        Stack< int > s3( s1 )     // okay.
    }
```
>- `Stack< int >` 는 타입이다..
>- `Stack` 은 타입을 만드는 틀이다. 타입이 아니다.
>- 이 둘을 잘 구분해서 사용해야 한다.


<p>
___
<p>
### 멤버 함수 템플릿
1. 앞에서 잠깐 봤던 멤버 함수를 템플릿으로 선언하는 방법에 대하여 알아보자.
2. 왜 클래스 템플릿에 멤버함수 템플릿을 사용하는 가에 대한 답을 할 수 있어야 한다.
- 다음 코드를 보자.
```
    // file : MemberTemplate01.cpp

    /*
    class Complex
    {
    public :
        Complex( double a = .0, double b = .0 )
            : re( a ), im( b )
        {
        }
    private :
        double im, re;
    };
    */

    template< typename T >
    class Complex
    {
    public :
        Complex( T a = 0, T b = 0 )
            : re( a ), im( b )
        {
        }
    private :
        T re, im;
    };

    int main( )
    {
	    Complex< int > c1( 1, 1 );
	    Complex< double > c2;
    }
```
>- `Complex` 클래스를 `double`로 해서 만들면 되는데 왜 `T` 를 만들었을까 ???
>- `double`은 속도가 느리기 때문이다..

- 여기서, `T`의 타입에 따라 초기화를 결정하는 Zero Initialization을 적용하자.
- 다음 코드를 보자.( MemberTemplate01.cpp 에서 한 줄 수정 )
```
    // file : MemberTemplate02.cpp

    template< typename T >
    class Complex
    {
    public :
        Complex( T a = T( ), T b = T( ) )
            : re( a ), im( b )
        {
        }
    private :
        T re, im;
    };

    int main( )
    {
    	Complex< int > c1( 1, 1 );
    	Complex< double > c2;
    }
```
>- `T a = T( );`
>>-  `T`가 primitive 이거나 포인터이면 `0`, `T`가 user defined type이면 디폴트 생성자 호출.

- 복사 생성자를 이용하여 객체를 복사할 수 있어야 한다.
```
	Complex< int > c1( 1, 1 );
	Complex< int > c2( c1 );
```
- 그런데 다른 타입을 가지는 Complex를 복사 생성자를 이용해서 만들고자 한다면 ??
```
	Complex< double > c3( c1 ); // error
```
>- `Complex< int >`의 기본 복사 생성자는 `int` 타입만 다룰 수 있다…

- 다음 코드를 보자. 복사 생성자 얘기이다. ( MemberTemplate02.cpp 에서 추가 )
```
    // file : MemberTemplate03.cpp

    template< typename T >
    class Complex
    {
    public :
        Complex( T a = T( ), T b = T( ) )
            : re( a ), im( b )
        {
        }

        template< typename U > Complex( const Complex< U >& u );

		template< typename > friend class Complex;

    private :
        T re, im;
    };

    template< typename T > template <typename U >
    Complex< T >::Complex( const Complex< U >& u )
        : re( u.re ), im( u.im ) // <- friend class declaration
    {
    }

    int main( )
    {
        Complex< int > c1( 1, 1 );
        Complex< int > c2( c1 );
        Complex< double > c3( c1 );
    }
```
>- 어떤 타입의 `Complex`가 복사될 때 코드를 생성할 수 있도록 `template` 으로 작성한다.
>- 복사 생성자에서 서로 다른 타입의 `Complex`의 `im`, `re` 가 복사될 수 있도록 `friend`로 엮어야 한다.
>- 대부분의 복사 생성자, 대입 연산자가 이렇게 정의되어 있다


<p>
___
<p>
### typename
1. 템플릿에 의존적인 타입을 확인하는 방법을 알아보자..
- 다음 코드를 해석해 보자..
```
template< typename T >
void foo( T a )
{
    T::DWORD * p;
}
```

- 다음과 같은 두 가지 해석이 가능하다.. 무엇이 맞는 것인가 ??
- 첫 번째, `DWORD`는 `static` 변수이다. 그래서 곱하기 `p` 하고 있다.
```
    // file : TypeName01.cpp

    class A
    {
    public :
        static int DWORD;
    };

    static int p = 1;

    template< typename T >
    void foo( T a )
    {
        T::DWORD * p;
    }

    int main( )
    {
    	A a;
    	foo( a );
    }
```
- 두 번째, `DWORD`는 `typedef` 되어 있는 타입이다.. 즉 포인터 `p`를 선언하는 문장이다..
```
    // file : TypeName02.cpp

    class A
    {
    public :
        typedef int DWORD;
    };

    template< typename T >
    void foo( T a )
    {
        typename T::DWORD * p;
    }

    int main( )
    {
	    A a;
	    Foo( a );
    }
```
- `T::DWORD * p;` 자체로는 해석이 되지 않는다. `T`가 무엇이 될지 모르기 때문이다.
- 그래서 이 상황은 기본적으로 `static` 으로만 해석한다.
- 타입으로 보고 싶으면 꼭 `typename` 이라고 써야 한다.


<p>
___
<p>
### valuetype
1. 모든 `template` 기반의 컨테이너는 자신과 연관된 타입이 있다.( 저장하는 타입 )
2. 그런데 외부에서 이 타입을 알고 싶을 때가 있는데,, 주로 함수 템플릿에서.. 알 수가 없다.
- 그래서 모든 컨테이너는 다음과 같이 만들어 진다.
```
    template< typename T >
    class list
    {
    public :
        typedef T value_type;
        // ...
    };
```
- 다음 코드를 보자. 인자로 전달된 컨테이너의 첫 번째 요소를 출력하는 함수이다.
```
    // file : ValueType01.cpp
	#include <iostream>
    #include <vector>
    using namespace std;

    // print first element.
    void print( vector< int >& v )
    {
        int n = v.front( );
        cout << n << endl;
    }
    int main( )
    {
        vector< int > v( 10, 3 );
        print( v );
    }
```
- 만일, type이 `int`에서 `double`로 바뀐다면 ??? 
```
    // file : ValueType02.cpp
	#include <iostream>
    #include <vector>
    using namespace std;

    // print first element.
    template< typename T >
    void print( vector< T >& v )
    {
        T n = v.front( );
        cout << n << endl;
    }

    int main( )
    {
        vector< int > v( 10, 3 );
        print( v );

        vector< double > dv( 10, 2.5 );
        print( dv );
    }
```
- 그런데 container가 `vector`에서 `list`로 바뀐다면 ???
```
    // file : ValueType03.cpp
    #include <iostream>
    #include <vector>
    #include <list>
    using namespace std;

    // print first element.
    template< typename T >
    void print( T& v )
    {
        typename T::value_type n = v.front( );
        cout << n << endl;
    }

    int main( )
    {
        vector< int > v( 10, 3 );
        print( v );

        vector< double > dv( 10, 2.5 );
        print( dv );

        list< double > dl( 10, 2.4 );
        print( dl );
    }
```


<p>
___
<p>
### 템플릿 인자
1. 템플릿에 인자가 될 수 있는 것은 다음과 같다.
	- type
	- 정수형 상수 ( `float`, `double` 안된다. 변수도 안된다. )
	- `template`
	- 가변 인자 ( from c+ + 2.0 ) – TemplatArg03.cpp
```
       template< typename … ARGS >
       class Tuple
       {
       };
       Tuple< int > t1;
       Tuple< int, int > t2;
       Tuple< int, int, int > t3;
```

- 코드를 보면서 이해하자. 다음 코드를 보자.
```
    // file : TemplateArg01.cpp

    template< typename T = int, int N = 10 >
    class Stack
    {
        T buff[ N ];
    }

    int main( )
    {
        Stack< int, 20 > s1;        // okay
        int a = 10;
        Stack< int, a > s2;         // error
        Stack< int > s3;            // okay. use default N.
        Stack< > s4;                // okay. use default T, N
    }
```

- 템플릿 인자로 템플릿이 사용되는 경우이다.
```
    // file : TemplateArg02.cpp

    template< typename T >
    class List
    {
    };

    template< typename T, template< typename > class C >
    class Stack
    {
    	C c;      // error.. C is not a type, template.
    	C< T > c; // okay.
    }

    int main( )
    {
        list l1;               // error
        list< int > l2;        // okay.
        Stack< int, list > st; // okay.
    }
```


<p>
___
<p>
### 함수 객체, 바인더...
1. C+ + 에서 흔히 사용되는 함수 객체를 살펴볼건데,, 내용이 어렵다.
2. 이런 것들이 있구나를 알고 따로 공부해보자..
- 다음 코드를 보자.
```
    // file : Functor01.cpp

    #include <functional>
    #include <algorithm>

    bool foo( int a ) { return a % 2 == 0; } // cannot substitute with inline
    struct IsEven
    {
        inline bool operator( )( int a ) { return a % 2 == 0; }
    };

    int main( )
    {
        int x[ 10 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        int* p1 = find( x, x+10, 3 );
        cout << *p1 << endl; // 3

        int* p2 = find_if( x, x+10, foo ); // find first even number.
        cout << *p2 << endl; // 2

        IsEven even;
        int* p3 = find_if( x, x+10, even );
        cout << *p3 << endl; // 2
    }
```
>- `find` 함수는 정말 generic 한 함수인가 ?? `find` 함수는 상수 검색만 가능하다.<br>
> 주어진 구간에서 처음으로 나오는 짝수를 찾고 싶다…
>- 짝수인지 구분할 수 있는 함수 포인터 `foo`를 사용하여 검색할 수 있는데, 함수 포인터는 `inline` 치환이 되지 않는다.. ( 첫 시간에 배운 거. )
>- 함수 객체인 `IsEven` 객체를 만들어서 `find_if`의 인자로 사용하자.

- C+ + 표준에는 이미 많은 함수 객체가 있다. .. `functional` 헤더 내부에 .. 공부해보자.
- 다음 코드를 보자.
```
    // file : Functor02.cpp
    #include <iostream>
    #include <functional>
    #include <algorithm>
    using namespace std;

    int main( )
    {
    	modulus< int > m;
        int n = m( 10, 3 ); // 10 % 3
        cout << n << endl; // 1

        int x[ 10 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        int* p = find_if( x, x+10, m ); // error. 
    }
```
>- `modulus` 는 이항 함수 객체이기 때문에 `find_if`의 인자로 사용할 수 없다.<br>
> `find_if`의 인자는 단항 함수이어야 한다.( `find_if`의 선언을 참고하자. )

- 이항 함수를 단항 함수로 바꿀 수 있다. 다음 코드를 보자.
```
    // file : Functor03.cpp
	#include <iostream>
    #include <functional>
    #include <algorithm>
    using namespace std;

    int main( )
    {
        modulus< int > m;
        binder2nd< modulus< int > > f( m, 2 );

        cout << f( 3 ) << endl; // 1
        cout << f( 4 ) << endl; // 0

        int x[ 10 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        int* p = find_if( x, x+10, f ); 
        cout << *p << endl; // 1
    }
```

- `binder2nd< modulus< int > > f( m, 2 );` 는 `m`의 두 번째 인자를 `2`로 고정한 단항함수이다.
- `binder2nd< >` 템플릿을 직접 쓰려니까 불편하다.. ( ??? )
- 클래스 템플릿은 추론이 안되기 때문에 추론이 가능한 함수 템플릿을 이용하여 헬퍼를 만들자.
- 다음 코드를 보자.
```
    // file : Functor04.cpp
    #include <iostream>
    #include <functional>
    #include <algorithm>
    using namespace std;

    template< typename T >
    binder2nd< T > Bind2nd( T f, int n )
    {
        return binder2nd< T >( f, n );
    }

    int main( )
    {
        modulus< int > m;
        int x[ 10 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        int* p = find_if( x, x+10, Bind2nd( m, 2 ) ); 
        cout << *p << endl; // 1
    }
```
>-	`Bind2nd`라는 함수 템플릿은 `T` 타입과 `int` 타입을 인자로 받고 `binder2nd< T >( f, n )`을 반환한다.
>- 	이미 C+ +에 `bind2nd` 로 존재한다.

- 직접 이항 함수를 단항 함수로 만들어 주는 도구를 만들어 보자.
	- 바인더를 만들 때, 특정 함수 객체의 파라미터 타입, 리턴 타입을 알 수 있는 방법은 없다.
	- 함수 객체를 만드는 사람이 알려주어야 한다.
	- 예를 들면, 
```
    struct Plus
    {
        int operator( )( int a, int b ) { return a + b; }
        typedef int first_argument_type;
        typedef int second_argument_type;
        typedef int result_type;
    };
```

- 위의 세 줄을 항상 쓰게 할래 ?? 우린 상속을 배웠자나…
- 다음 코드를 보자.
```
    // file : Functor05.cpp

    template< typename T1, typename T2, typenamne TR >
    struct Binary_function
    {
    	typedef T1 first_argument_type;
        typedef T2 second_argument_type;
        typedef TR result_type;
    };

    struct Plus : public Binary_function< int, int, int >
    {
        int operator()( int a, int b ) { return a + b; }
    };

    int main( )
    {
        Plus p;.
        int n = p( 1, 2 );
        cout << n <<  endl; // 3
    }
```
>- 이미 C+ + 에 `binary_function` 템플릿이 있다.

- 타입을 확인했으면, 이제 함수 바인더를 만들어 보자.
```
    // file : Functor06.cpp
    #include <iostream>
    usikng namespace std;

    template< typename T1, typename T2, typenamne TR >
    struct Binary_function
    {
	    typedef T1 first_argument_type;
        typedef T2 second_argument_type;
        typedef TR result_type;
    };

    struct Plus : public Binary_function< int, int, int >
    {
        int operator()( int a, int b ) { return a + b; }
    };

    template< typename T >
    struct xbinder2nd
    {
        T op;
        int second;
    public :
        xbinder2nd( T f, int s )
            : op( f ), second( s )
        {
        }

        int operator( )( int first ) { return op( first, second ); }
    };

    int main( )
    {
        Plus p;.
        xbinder2nd< Plus > f( p, 2 );
        int n = f( 1 ); // = p( 1, 2 );
        cout << n << endl;
    }
```
>- `T op;` 는 이항 함수 객체이다.
>- `int second;` 는 고정될 두 번째 인자이다…
>- first, second, return 타입이 `int`로 고정되어 있는게 아쉽다..

- 템플릿 의존적인 타입을 이용하여 일반적으로 사용할 수 있게 바꿔보자.
```
    // file : Functor06.cpp ( modified )
	#include <iostream>
    using namespace std;

    template< typename T1, typename T2, typenamne TR >
    struct Binary_function
    {
    	typedef T1 first_argument_type;
        typedef T2 second_argument_type;
        typedef TR result_type;
    };

    struct Plus : public Binary_function< int, int, int >
    {
        int operator()( int a, int b ) { return a + b; }
    };

    template< typename T >
    struct xbinder2nd
    {
        T op;
        typename T::second_argument_type second;
    public :
        xbinder2nd( T f, typename T::second_argument_type s )
            : op( f ), second( s )
        {
        }

        typename T::result_type operator( )( typename T::first_argument_type first )
        {
            return op( first, second );
        }
    };

    int main( )
    {
        Plus p;.
        xbinder2nd< Plus > f( p, 2 );
        int n = f( 1 ); // = p( 1, 2 );
        cout << n << endl;
    }
```

- 진정한 generic 함수가 C+ + 2.0에는 존재한다.
	- `bind( )` 함수는 `M`항을 `N`항으로 바꿔준다


<p>
___
<p>
### int2type
1. 템플릿 전문화/부분 전문화를 통해 전달된 인자의 타입에 따라 다른 동작을 수행하는 것에 대해 살펴본적이 있다.
2. User defined 타입이 아닌 상황에서 코드의 동작에 대해 살펴보도록 하자.
- 다음 코드를 보자.
```
    // file : Int2Type01.cpp

    template< typename T > sturct IS_POINTER        { enum { value = false }; };
    template< typename T > struct IS_POINTER< T* >	{ enum { value = true }; };

    template< typename T >
    T Max( T a, T b )
    {
        if( IS_POINTER< T >::value )
            return *a < *b ? b : a;
        return a < b ? b : a;
    };

    int main( )
    {
        int x = 10, y = 20;
        Max( x, y );     /// ??? error.
        Max( &x, &y );  /// ???  okay.
    }
```
>- 위 코드에서 무엇이 문제일까 ?<br>
> `Max( x, y );`  // 이 라인에서 컴파일 오류가 발생한다 ?? 왜일까 ???
>- `if` 문은 실행 시간의 분기문이다. `false` 라면 실행되지 않지만 컴파일은 해야 한다.
>- 즉, `int` 타입의 `Max` 함수가 컴파일러에 의해 작성될 때, `int` 타입의 역참조`(*a, *b)`가 발생하게 된다. 
>- 이것을 해결하려면,, ???  `if`문을 컴파일 시간에 분기시켜야 한다…
>- 함수 overloading은 컴파일 시간의 분기문이다. 함수 overlaoding을 이용하자..

- 다음 코드를 보자. ( Int2Type01.cpp 에서 수정 )
```
    // file : Int2Type02.cpp
	#include <iostraem>
    using namespace std;

    template< int N > struct int2type { enum { value = N }; };

    template< typename T > sturct IS_POINTER        { enum { value = false; }; };
    template< typename T > struct IS_POINTER< T* >	{ enum { value = true; }; };

    template< typename T > 
    T MaxImpl( T a, T b, int2type< 0 > )
    {
        cout << “Not pointer case” << endl;
        return a < b ? b : a;
    }

    template< typename T > 
    T MaxImpl( T a, T b, int2type< 1 > )
    {
        cout << “Pointer case” << endl;
        return *a < *b ? b : a;
    }

    template< typename T >
    T Max( T a, T b )
    {
    	return MaxImpl( a, b, int2type< IS_POINTER< T >::value >( ) ); // IMPORTANT
    };

    int main( )
    {
        int x = 10, y = 20;
        Max( x, y );     /// ??? okay.
        Max( &x, &y );  /// ???  okay.
    }
```
>- 중요한 내용들이 나오는 데, 핵심은 컴파일 시간에 결정된 상수에 따라서 오버로딩을 가능하게 하고 코드를 분기하게 하자.
>- `int2type` 템플릿은 입력된 `T` 타입의 값 `N  에 따라 서로 다른 타입을 만들게 된다.
예 )
```
		int2type< 0 > type0;
		int2type< 1 > type1;
```
>- `0`과 `1`이라는 integer 타입에서 `type0`, `type1` 이라는 서로 다른 타입으로 변경한다.
>- T가 포인터일 때와 아닐 때의 implementation을 분리한다. ( `MaxImpl` )
같은 타입을 가지는 함수는 overloading할 수 없으니, `0`과 `1`을 이용하여 서로 다는 타입을 만들고, 이를 overloading 하도록 하자.
>- `IS_POINTER< T >::value` 의 결과는 `0` 또는 `1`이다. `0`과 `1`을 같은 타입(`int`) 이므로 함수 overloading을 위해서 서로 다른 타입이 되도록 해주자.
>-	모든 타입 뒤에 ( )를 추가하면 임시 객체가 만들어진다.
`int2type< IS_POINTER< T >::value >( )`
이 때, 값이 중요하지 않다. 만들어진 임시 객체의 타입이 중요하고 임시 객체의 값이 얼마인지는 상관 없다.

- `enum` 이 아닌 `const` 를 사용한 방법도 있다.
- 다음 코드를 보자.
```
    // file : Int2Type03.cpp
	#include <iostraem>
    using namespace std;

    template< typename T, T N > struct INTEGRAL_CONSTANT { static const T value = N; };

    typedef INTEGRAL_CONSTANT< bool, true > TRUE_TYPE;
    typedef INTEGRAL_CONSTANT< bool, false > FALSE_TYPE;

    template< typename T > struct IS_POINTER : public FALSE_TYPE { };
    template< typename T > struct IS_POINTER< T* > : public TRUE_TYPE { };

    template< typename T > 
    T MaxImpl( T a, T b, FALSE_TYPE )
    {
        cout << “Not pointer case” << endl;
        return a < b ? b : a;
    }

    template< typename T > 
    T MaxImpl( T a, T b, TRUE_TYPE )
    {
        cout << “Pointer case” << endl;
        return *a < *b ? b : a;
    }

    template< typename T >
    T Max( T a, T b )
    {
    	return MaxImpl( a, b, IS_POINTER< T >( ) ); // IMPORTANT
    };

    int main( )
    {
        int x = 10, y = 20;
        Max( x, y );     /// ??? okay.
        Max( &x, &y );  /// ???  okay.
    }
```
>- `INTEGRAL_CONSTANT` 구조체 내에 `static const` 상수를 하나 포함하게 하고
>- `bool` 타입의 값 `true`와 `false`에 따라 서로 다른 타입을 정의한다.
>- `TRUE_TYPE`과 `FALSE_TYPE`은 `bool` 타입이 아니다. 각 각 별도의 타입이다.
>- `IS_POINTER`는 `FALSE_TYPE`을 상속하여 선언하고, 부분 전문화한 `IS_POINTER< T* >`는 `TRUE_TYPE`을 상속하여 선언한다. 즉, 사용된 타입에 따라( 포인터냐 아니냐 ) 부모 클래스를 바꾼다.!!!
>- `Max` 함수 내에서 `IS_POINTER< T >`의 임시 객체에 따라 분기할 수 있도록 해준다. 역시 `IS_POINTER< T >( )` 임시 객체의 값은 중요치 않다. 타입만이 중요하다.
( 오버로딩된 함수의 구분 자체에서 값을 활용하지 않기 때문에. )

- 이미 C+ +에 다 구현되어 있다.
	- `#include <type_traits>`
	- `integral_constant`, `is_pointer`, `true_type`, `false_type` 다 있다.

```
    // file : Int2Type04.cpp
	#include <iostream>
    #include <type_traits>
    using namespace std;

    template< typename T > 
    T MaxImpl( T a, T b, false_type )
    {
        cout << “Not pointer case” << endl;
        return a < b ? b : a;
    }

    template< typename T > 
    T MaxImpl( T a, T b, true_type )
    {
        cout << “Pointer case” << endl;
        return *a < *b ? b : a;
    }

    template< typename T >
    T Max( T a, T b )
    {
    	return MaxImpl( a, b, is_pointer< T >( ) ); // IMPORTANT
    };

    int main( )
    {
        int x = 10, y = 20;
        Max( x, y );     /// ??? okay.
        Max( &x, &y );  /// ???  okay.
    }
```


<p>
___
<p>
### 자명한 생성자
1. 아무일도 하지 않는 생성자란 뜻이다.
	1. 가상 함수가 없고,
	2. 부모가 없거나 부모의 생성자가 자명하고
	3. 객체형 멤버가 없거나 객체형 멤버의 생성자가 자명하고
	4. 정말 하는 일이 없다면 <br><br> 생성자는 자명하다고 한다.

- 기본 생성자가 생성되지 않는다. 다음 코드를 보자.
```
    // file : TrivialConstructor01.cpp
	#include <iostream>
    #include <cstdlib>
    using namespace std;

    class A
    {
    public :
        A( ) { cout << “A( )” << endl; }
        virtual ~A( ) { }
    };’

    class B : public A
    {
    public :
        B( ) { cout << “B( )” << endl; }
        virtual ~B( ) { }
        virtual void foo( ) { cout << “foo” << endl; }
    };

    class C
    {
    public :
        C( ) { }
    };

    int main( )
    {
        B* p = static_cast< B* >( malloc( sizeof( B ) );
        new( p ) B;
        p->foo( );

        B* p2 = new B( );
        p2->foo( );

        C c;
    }
```
>- `class C`가 자명하다.. trivial 하다고 한다.
>- `C c;` 는 기계어 코드에도 안나타난다.

- 다음 코드를 보자. 좀 어려운데,,, 이런게 있다고 보고 넘어가도 좋다.
```
    // file : TrivialConstructor02.cpp
    #include <cstring>
    #include <type_traits>

    template< typename T > struct trait_trivial_ctor { enum { value = false }; };
    template< typename T > struct trait_trivial_dtor { enum { value = false }; };
    template< typename T > struct trait_trivial_copy { enum { value = false }; };

    #define IOTIVITY_BASIC_TYPE_TRAITS( T )  \
    template< > struct trait_trivial_ctor< T > { enum { value = true }; };  \
    template< > struct trait_trivial_dtor< T > { enum { value = true }; };  \
    template< > struct trait_trivial_copy< T > { enum { value = true }; };

    IOTIVITY_BASIC_TYPE_TRAITS( int )
    IOTIVITY_BASIC_TYPE_TRAITS( double )
    IOTIVITY_BASIC_TYPE_TRAITS( char )

    struct Point {
        int x;
        int y;
    };

    IOTIVITY_BASIC_TYPE_TRAITS( Point )

    template< typename T >
    struct traits
    {
        enum {
            IS_POINTER = is_pointer< T >::value,
            HAS_TRIVIAL_COPY = IS_POINTER || trait_trivial_copy< T >::value,
        };
    };

    typename< template T >
    void copy_type( T* dst, T* src, int sz )
    {
        if( !traits< T >::HAS_TRIVIAL_COPY ) {
            while( sz-- ) {
                new( dst ) T( *src );
                ++src, ++dst;
            }
        }
        else {
            memcpy( dst, src, sz );
        }
    }

    int main( )
    {
        char s1[ 10 ] = “hello”;
        char s2[ 10 ];
        copy_type(s2, s1, 10 ): // strcpy( s2, s1 );

        Point p1, p2;
        p1.x = 1;
        p1.y = 2;
        copy_type( &p2, &p1, sizeof( Point ) );
    }
```
>- 템플릿 전문화를 이용하여 특정 타입은 trivial 하다고 선언할 수 있게 한다.
>- trivial한 생성자/복사생성자를 가진 타입은 `memcpy`하여 복사한다.
>>- `memcpy`가 빠르니까.


<p>
___
<p>
### 다중 상속
1. Diamond 상속이라 불리우는 상속 관계에 대해서 살펴보자.
2. 다중 상속으로만 해결 가능한 문제를 제외하곤 가급적인면 사용하지 말자.
3. 결론
	- **Diamond 상속의 모양이 나타나면, 1차 child를 가상 상속으로 해야 한다.**

- 다음 코드를 보자.
```
    // file : MultiInherit01.cpp

    class X { public : int x; };
    class A : public X { public : int a; };
    class B : public X { public : int b; };

    class C : public A, public B { };

    int main( )
    {
        C c;
        c.x = 10;    // error… 
        c.A::x = 10;  // okay.
    }
```
>- `C` 클래스가 diamond 상속을 한 형태이다.
>- `c.x = 10;` 는 오류이다. `x`는 두 번 상속된 상황인데, `A`를 통해 상속된 것인지, `B`를 통해 상속된 것인지 알 수 없기 때문이다.
>- 상속된 `class`를 명시할 수 있지만 근본적인 해결책은 아니다. `x`는 하나만 있는 게 좋다.

- 다음 코드를 보자.( MultiIhnerit01.cpp 에서 수정 )
```
    // file : MultiInherit02.cpp

    class X { public : int x; };
    class A : virtual public X { public : int a; };
    class B : virtual public X { public : int b; };

    class C : public A, public B { };

    int main( )
    {
        C c;
        c.x = 10;
    }
```

- 다중 상속과 casting 관계를 살펴보자.
- 다음 코드를 보고 결과를 예측해 보자.
```
    // file : MultiInherit03cpp
    #incldue <iostream>
    using namespace std;

    class A { public : int a; };
    class B { public : int b; };

    class C : public A, public B { };

    int main( )
    {
        C c;
        cout << “&c = “ << &c << endl;

        A* p1 = &c;
        B* p2 = &c;
        B* p3 = ( B* ) &c;
        B* p4 = static_cast< B* >( &c );
        B* p5 = reinterpret_cast< B* >( &c );

        p5->b = 10;
        cout << “c.b = “ << c.b << endl; // ???? 0
        cout << “c.a = “ << c.a << endl; // ???? 10 

        cout << “p1 = “ << p1 << endl;  // ????
        cout << “p2 = “ << p2 << endl;  // ????
        cout << “p3 = “ << p3 << endl;  // ????
        cout << “p4 = “ << p4 << endl;  // ????
        cout << “p5 = “ << p5 << endl;  // ????
    }
```
>- 객체 `C` 의 메모리를 그려보면,
>>- 제일 위에 `A`가 있고, 그 아래 `B` 가 있다.
>>- 그런데, `A`에는 `int a` 가 있으니 4 바이트 뒤에 `B`가 존재한다.
>
>- 객체 `C` 가 `0x100` 번지에 생성되었다고 가정하면, 
>>- p1 = 0x100
>>- p2 = 0x104
>>- p3 = 0x104
>>- p4 = 0x104    -> `static_cast`는 논리적으로 찾는 거고, ( 연관성이 없으면 실패한다. )
>>- p5 = 0x100    -> `reinterpret_cast` 는 무조건 view 를 바꾸는 거고.
>>- 그래서 `p5->b` 는 `a` 의 위치를 가리키게 된다


<p>
___
<p>
### Code Bloat
1. `template`으로 인한 코드 생성이 과다해지는 code bloat 현상을 막기 위해 다음과 같은 방법을 사용한다.
2. `typename T` 와 관련 없는 모든 멤버는 부모 클래스로 만든다.
3. 단, 만들어지는 부모 클래스는 `template`이 아니다.

- 다음 코드를 보자
```
    // file : CodeBloat01.cpp

    template< typename T >
    class Vector
    {
        T* buff;
        int sz;
    public :
        int Size( ) { return sz; }
        bool Empty( ) { return sz == 0; }
        inline void Push( const T& a ) { }
    };

    int main( )
    {
	    Vector< int > s1;
	    Vector< double > s2; // ??? (1)
    }
```
>- (1) 순간 메모리에 생성된 Vector 관련 함수는 총 몇 개일까 ??
>>- 각 멤버함수가 두 개씩 생성되어 6개.

- 다음 코드를 보자
```
    // file : CodeBloat02.cpp

    class VectorImpl
    {
        int sz;
        void* buff;
    public :
        int Size( ) { return sz; }
        bool Empty( ) { return sz == 0; }
        void Push( void* item, int s ) { }
        void* Top( ) { return buff; }
    };

    template< typename T >
    class Vector : private VectorImpl
    {
    public :
        int Size( ) { return VectorImpl::Size( ); }
        bool Empty( ) { return VectorImpl::Empty( ); }
        inline void Push( const T& a ) { VectorImpl::Push( &a, sizeof( T ) ); }
        inline T* Top( ) { return static_cast< T& >( *VectorImpl::Top( ) ); }
    };

    int main( )
    {
	    Vector< int > s1;
	    Vector< double > s2; // ??? (1)
    }
```
>- (1) 순간 메모리에 생성된 `Vector` 관련 함수는 총 몇 개일까 ??

- Android에 구현된 `Vector`, `VectorImpl`을 참조하면 좋다.

