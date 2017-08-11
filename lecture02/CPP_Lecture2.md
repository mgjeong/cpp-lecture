# C++ Lecture 

___
## Day 2
### Synopsis
- Creation : 2015. 06. 04
- Last Modified : 2017. 07. 19
- Version : 1.1
- Author : MJ( mg.jeong )
___
### Contents
- 템플릿 전문화
- 스마트 포인터
- 변환

<p>
___
<p>
### 템플릿 전문화( template specilization )
1. 너무 많이 활용되는 문법이다.
- 다음 코드를 보자
```
    // file : TemplateSpecialization01.cpp

    // 일반적으로 널리 사용되는 형태로 primary template라고 부른다.
    template< typename T >
    class Stack
    {
    public :
        void Push( ) 
        {
            cout << “T” << endl;
        }
    };

    // 포인터만 다르게 관리하고 싶을 때가 있다.
    // 예로, 포인터는 깊은 복사(deep copy)를 하고자 할 때,
    // template partial specialization(부분 전문화, 부분 특화)라고 부른다.
    template< typename T >
    class Stack< T* >
    {
    public :
        void Push( )
        {
            cout << “T*” << endl;
        }
    };

    // char 포인터만 다르게 관리하고 싶을 때,,,
    // typename을 사용하지 않는다…
    // template specialization( 전문화 ) 라고 부른다.
    template< > class
    Stack< char* >
    {
    public :
        void Push( )
        {
            cout << “char*” << endl;
        }
    };

    int main( )
    {
        Stack< int > s1;
        Stack< int* > s2;
        Stack< char* > s3;

        s1.Push( );
        s2.Push( );
        s3.Push( );
    }
```
>- `template`을 이용하여 원하는 type에 대한 관리를 분리해야 수행할 수 있다.

- 다음 코드를 보자
```
    // file : TemplateSpecialization02.cpp

    template< int N > struct Factorial
    {
        enum {
            value = N * Factorial< N-1 >::value,
        };
    };

    template< > struct Factorial< 1 >
    {
        enum {
            value = 1,
        };
    };

    int main( )
    {
        int n = Factorial< 5 >::value;
        cout << n << endl;
        return 0;
    }
```
>- 템플릿 전문화를 이용한 컴파일 타임 recursion 방법이다
>>- `template`을 사용하여 run-time이 아닌 compile time에 recursion을 수행한다.
>
>- template meta programming 이라고도 한다.
>- `int n = Factorial< 5 >::value;`는 다음처럼 풀린다.<br>
> `= 5 * Factorial< 4 >::value;`<br>
> `= 5 * Factorial< 4 >::value;`<br>
> `= 5 * 4 * Factorial< 3 >::value;`<br>
> `= 5 * 4 * 3 * Factorial< 2 >::value;`<br>
> `= 5 * 4 * 3 * 2 * Factorial< 1 >::value;`<br>
> `= 5 * 4 * 3 * 2 * 1`<br>
> `= 120`
>- 기계어 코드로 보면 `120`만 보인다.
>- 최적화 측면에서 `template` 코드가 코드생성기로 동작하여 변환된 코드는 없다.
>- 단, 실행 시간에 인자를 받는<br>
> `cin >> a;` <br>
> `int n = Factorial< a >::value;`<br>
> 방법은 안된다.. 왜냐 ?? 컴파일 타임에 a값을 모르기 때문에..

- 다음은 traits(특성) 기술인데, 아주 유명한 기술이다. 반드시 알아야 하는 내용이다..
- 다음을 살펴 보자…( 빌드가 되지 않는 코드이다.. )
```
    // file : TemplateSpecialization03.cpp

    template< typename T >
    T Max( T a, T b )
    {
        // T가 포인터라면, 똑똑하게 그 값을 비교해서 역참조 해줄께…
        // T가 포인터인지 알아내는 게 핵심이다..
        if( T is Pointer )
            return *a < *b ? b : a;
        return a < b ? b : a;
    };

    int main( )
    {
        int x = 10, y = 20;
        Max( x, y );
        Max( &x, &y );

        return 0;
    }
```
>- `T`가 포인터라면 address 자체를 비교해서 값을 돌려주게 된다..
>- `T`가 포인터일 때 그 주소가 가리키는 값을 비교해서 결과를 리턴하는 방법은 없을까 ???

- 타입이 포인터인지 아닌지 확인하는 방법을 알아보자. (`trait_pointer` == 특성 포인터 )
```
    // file : TemplateSpecialization04.cpp

    // rule 1. primary template는 false를 리턴하고,
    template< typename T >
    struct trait_pointer
    {
        enum {
            value = false,
        };
    };

    // rule 2. 부분 전문화 버전은 true를 리턴하게 하자.
    template< typename T >
    struct trait_ponter< T* >
    {
        enum {
            value = true,
        };
    };

    template< typename T >
    void foo( const T& p )
    {
        if( trait_pointer<T>::value )
            cout << “It is a pointer.” << endl;
        else
            cout << “It is not a pointer.” << endl;
    }

    int main( )
    {
        int x = 10;
        foo( x );
        foo( &x );

        return 0;
    }
```
>- 부분 전문화 템플릿을 사용하여 사용된 타입이 포인터인지 아닌지 확인할 수 있다.

- 다음 코드를 보자.
```
    // file : TemplateSpecialization05.cpp

    template< typename T >
    struct trait_array
    {
        enum { size = -1 };
        eunm { value = false };
    };

    template< typename T >
    void foo( const T& a )
    {
        if( trait_array<T>::value )  // trait_array를 만들어 보자…..
            cout << “It’s an array” << endl;
        else
            cout << “It’s not an array” << endl;
    }

    int main( )
    {
        int n = 10;
        int x[ 10 ];
        int y[] = { 1, 3, 5, 7, 9, 11 };

        foo( n );
        foo( x );
        foo( y );

        return 0;
    }
```
>- 빌드하여 실행하면 모두 array가 아닌 것으로 나온다…
>- Array가 맞는지, 아닌지 확인하는 trait_array를 만들어 보자.

- 완성된 코드는 다음과 같다.
```
    // file : TemplateSpecialization06.cpp

    template< typename T >
    struct trait_array
    {
        enum { size = -1 };
        eunm { value = false };
    };

    template< typename T, int N >
    struct trait_array< T[N] >
    {
        enum { size = N };
        enum { value = true };
    };

    template< typename T >
    struct trait_array< T[ ] >
    {
    enum { size = sizeof( T ) };
        enum { value = true };
    }

    template< typename T >
    void foo( const T& a )
    {
        if( trait_array<T>::value )
            cout << “It’s an array” << endl;
        else
            cout << “It’s not an array” << endl;
    }

    int main( )
    {
        int n = 10;
        int x[ 10 ];
        int y[] = { 1, 3, 5, 7, 9, 11 };

        foo( n );
        foo( x );
        foo( y );

        return 0;
    }
```
>- type `T`와 크기 `N` 을 가지는 `trait`과 type `T[ ]` 를 가지는 `trait`을 추가한다.


<p>
___
<p>
### 스마트 포인터( smart pointer )
1. 개념
	- 임의의 객체가 다른 타입의 포인터 역할을 하는 것.
2. 장점
	- 진짜 포인터가 아니라 객체이다.
	- 생성/복사/대입/소멸의 모든 과정을 다양하게 활용할 수 있다.
	- 대표적 활용법은 소멸자에서 자동 삭제하는 것이다.
3. 구현 방법
	- `->` 와 `*` 연산자를 재정의하여 구현한다.

- 다음 코드를 보자.
```
    // file : SmartPointer01.cpp

    class Car
    {
    public :
        void Go( void ) { cout << “Car go.” << endl; }
    };

    class ptr
    {
    Car* m_ptr;

    public :
        ptr( Car* car )
            : m_ptr( car )
        {
        }

        ~ptr( )
        {
            delete m_ptr;
        }

        inline Car* operator->( ) { return this->m_ptr; }
    };

    int main( )
    {
    	ptr p = new Car;
    	p->Go( );

        return 0;
    }
```
>- `ptr` 클래스의 `->` 연산자를 overriding 해서 `Car`의 포인터를 반환하도록 한다.
>- `operator->( )` 의 사용은 다음과 같아야 한다.
>```
	( p.operator->( ) )->Go( );
	// 그러나 이것을 다음처럼 사용하게 해준다.
	p->Go();
>```
>-  진짜 포인터처럼 보이게 하려면 ????? `*p` 이게 되야 하지 않을까 ?

- 다음 코드를 보자.( SmartPointer01.cpp 파일을 수정한다. )
```
    // file : SmartPointer02.cpp

    class  Car
    {
    public :
        void Go( void ) { cout << “Car go.” << endl; }
    };

    class ptr
    {
    Car* m_ptr;

    public :
        ptr( Car* car )
            : m_ptr( car )
        {
        }

        ~ptr( )
        {
            delete m_ptr;
        }

        inline Car* operator->( ) { return this->m_ptr; }
        inline Car& operator*( ) { return *m_ptr; }
    };

    int main( )
    {
	    ptr p = new Car;
    	p->Go( );
	    (*p).Go( );

        return 0;
    }
```
>- `operator*( )` 연산자를 overriding한다.
>- `*` 를 사용하여 연산한 결과가 유지되려면 임시 객체가 사용되어서는 안되기 때문에 참조리턴을 사용해야 하는 것이 중요하다.

- 임의의 클래스에 대해서 스마트 포인터를 지원하려면 ???
>- 그렇다. `template`을 사용하면 다양한 타입을 지원할 수 있다..
>- `template`의 타입으로 지점되는 클래스를 포인터로 지정하면 가능하다…

- 다음 코드를 보자. ( SmartPointer02.cpp 에서 수정하자. )
```
    // file : SmartPointer03.cpp

    template< typename T >
    class  ptr
    {
        T* m_ptr;

    public :
        ptr( T* p )
            : m_ptr( p )
        {
        }

        ~ptr( )
        {
            delete m_ptr;
        }

        inline T* operator->( ) { return this->m_ptr; }
        inline T& operator*( ) { return *( this->m_ptr ); }
    };

    int main( )
    {
        ptr< int > p1 = new int;
        *p1 = 2;
        cout << *p1 << endl;
    }
```
>- 깔끔하게 스마트 포인터를 만들 수 있다….!!!

- 복사 생성자를 기억하고 있는가 ??
>- 클래스 내부에 포인터 변수가 있으면 기본 복사 생성자에서 얕은 참조 문제가 발생할 수 있다는 사실을 기억하고 있는가 ??

- 다음 코드를 보자.( SmartPointer03.cpp 에서 main함수에 다음을 추가. )
```
    // file : SmartPointer04.cpp

    template< typename T >
    class  ptr
    {
        T* m_ptr;

    public :
        ptr( T* p )
            : m_ptr( p )
        {
        }

        ~ptr( )
        {
            delete m_ptr;
        }

        inline T* operator->( ) { return this->m_ptr; }
        inline T& operator*( ) { return *( this->m_ptr ); }
    };

    int main( )
    {
        ptr< int > p1 = new int;
        *p1 = 2;
        cout << *p1 << endl;

        ptr< int > p2 = p1; // ptr 클래스의 복사 생성자를 호출한다..
    }
```
>- `ptr` 클래스의 복사 생성자를 호출하면, `m_ptr` 변수가 앝은 참조가 된다.
>- 함수가 끝날 때, `m_ptr`이 두 번 `delete` 되므로 run-time에 crash 발생한다.
>- 진짜 그런지 확인해 보자.
>```
   	$ ulimit –Sa
   	. . .
   	. . .
   	$ ulimit –c unlimited
    $ ./SmartPointer04
    . . .
    중지됨 (core dumped)
    $ gdb ./SmartPointer04 ./core
    . . .
    Program terminated with signal 6, Aborted
    #0 0xxxx .. from /lib/x86_64-linux-gnu/libc.so.6
    (gdb) where
    . . .
    . . .
    #4 0x0000xxx in ptr<int>::~ptr() ()
    #5 0x0000xxx in main ()
    (gdb)
>```
>- 해결하자.!!!

- 이미 복사 생성자를 다룰 때 해결 방안을 찾았었다.
>- 깊은 복사( Deep copy ) – 거의 사용되지 않는다. ( 널리 알려졌지만, 나쁜 방법이다. )
>- 참조 계수( Reference count ) – 가장 많이 사용하는 방법. Copy on write는 주의해야 한다.
>- 소유권 이전( Ownership transfer ) – C+ + 표준의 `auto_ptr`
>- 복사 금지( Copy prohibit ) – 참조 계수 다음으로 많이 사용된다. ( `unique_ptr` )

- 다음 코드를 보자. 참조 계수 기반의 스마트 포인터이다..( SmartPointer04.cpp에서 직접 수정 )
```
    // file : SmartPointer05.cpp

    template< typename T >
    class  ptr
    {
        T* m_ptr;
        int* m_ref;

    public :
        ptr( T* p )
            : m_ptr( p )
        {
            this->m_ref = new int( 1 );
        }

        ptr( const ptr& p )
            : m_ptr( p.m_ptr ), m_ref( p.m_ref )
        {
            ++( *m_ref );
        }

        ~ptr( )
        {
            if( --( *m_ref ) <= 0 ) {
	            delete m_ptr;
    	        delere m_ref;
            }
        }

        inline T* operator->( ) { return this->m_ptr; }
        inline T& operator*( ) { return *( this->m_ptr ); }
    };

    int main( )
    {
        ptr< int > p1 = new int;
        *p2 = 2;
        cout << *p1 << endl;

        ptr< int > p2 = p1; // ptr 클래스의 복사 생성자를 호출한다..
        cout << *p2 << endl;
    }
```
>- 이미 C+ + 표준에 있다. `shared_ptr` 이 그것이다.<br>
>- C+ + 11 에서 정식으로 추가됨. g++ 4.xx 이상에서는 사용가능.
>```
        // file : SmartPointer06.cpp
        #include <memory>
        int main( )
        {
            shared_ptr< int > p1 ( new int( 1 ) );
            // shared_ptr< int > p2 = new int( 2 );   // 이건 error…
            *p1 = 2;
            shared_ptr< int > p3 = p1;
            cout << *p1 << endl;
            cout << *p3 << endl;
        }
>```
>>- 빌드 command는 다음과 같다.
>>```
		$ g++ –std=c++0x -o SmartPointer06  SmartPointer06.cpp
>>```
>>- sconscript는 다음과 같다.
>>```
		env = Environment( CCFLAGS = “-std=c++0x” )
		env.Program( ‘SmartPointer06’, ‘SmartPointer06.cpp’ )
>>```

- 여기서 질문.. 왜 스마트 포인터에 안에 reference를 두어야 하는가 ??
- 스마트 포인터를 쓸 수록 오버헤드가 생기게 된다..
- 논리적으로도 참조된 `count`는 객체가 가지고 있는 게 맞지 않나 ??
- 다음 코드를 보자.
```
    // file : SmartPointer07.cpp

    class  Car
    {
        int m_count;

    public :
        Car( )
            : m_count( 0 )
        {
            cout << “Car created..” << endl;
        }

        ~Car( )
        {
            cout << “Car destroyed..” << endl;
        }

        void IncStrong( ) { ++m_count; }
        void DecStrong( ) { if( --m_count <= 0 ) delete this; }
    };

    int main( )
    {
        Car* p1 = new Car( );
        p1->IncStrong( ); // 규칙 1 – 객체를 만들면 참조 계수 증가시킨다.

        Car* p2 = p1;
        p2->IncStrong( );  // 규칙 2 – 포인터 복사 시 참조 계수 증가시킨다.

        p2->DecStrong( );  // 규칙 3 – 포인터 사용이 끝나면 참조 계수 감소시킨다. 
        p1->DecStrong( );
    }
```
>- 참조 계수 증가/감소의 규칙을 정하여 `IncStrong( )` 과 `DecStrong( )` 함수를 호출한다.
>- 사용하기 불편하다..

- 다음 코드를 보자. ( SmartPointer07.cpp 파일에서 수정 )
```
    // file : SmartPointer08.cpp

    class  Car
    {
        int m_count;

    public :
        Car( )
            : m_count( 0 )
        {
            cout << “Car created..” << endl;
        }

        ~Car( )
        {
            cout << “Car destroyed..” << endl;
        }

        void IncStrong( ) { ++m_count; }
        void DecStrong( ) { if( --m_count <= 0 ) delete this; }
    };

    template< typename T >
    class sp
    {
        int m_ptr;

    public :
        sp( T* pt = 0 )
            : m_ptr( pt )
        {
            if( m_ptr ) m_ptr->IncStrong( );
        }

        sp( const sp& ptr )
            : m_ptr( ptr.m_ptr )
        {
            if( m_ptr ) m_ptr->IncStrong( );
        }

        ~sp( )
        {
            if( m_ptr ) m_ptr->DecStrong( );
        }
    };

    int main( )
    {
        sp< Car > p1 = sp< Car >( new Car( ) );
        sp< Car > p2 = p1;

    }
```
>- 포인터는 참조 계수에 관여하지 않고, 객체에서 직접 카운팅 한다.
>- 근데,, 모든 객체에 참조 계수 관리하도록 만들어야 하나 ????
>- 참조 계수 관리하는 클래스만 별도로 뽑자..

- 다음 코드를 보자. ( SmartPointer08.cpp 파일에서 수정 )
```
    // file : SmartPointer09.cpp

    class RefBase
    {
	    int m_count;
    public :
        RefBase( )
    		: m_count( 0 )
        {
        }

        virtual ~RefBase( )
        {
        }

    	void IncStrong( ) { ++m_count; }
        void DecStrong( ) { if( --m_count <= 0 ) delete this; }
    };

    class  Car : public RefBase
    {
    public :
        Car( )
    	{
            cout << “Car created..” << endl;
        }

        ~Car( )
        {
            cout << “Car destroyed..” << endl;
        }

        void Go( ) { cout << “Car go..” << endl; }
    };

    template< typename T >
    class sp
    {
        int m_ptr;
    public :
        sp( T* pt = 0 )
            : m_ptr( pt )
        {
            if( m_ptr ) m_ptr->IncStrong( );
        }

        sp( const sp& ptr )
            : m_ptr( ptr.m_ptr )
        {
            if( m_ptr ) m_ptr->IncStrong( );
        }

        ~sp( )
        {
            if( m_ptr ) m_ptr->DecStrong( );
        }
    };

    int main( )
    {
        sp< Car > p1 = sp< Car >( new Car( ) );
        sp< Car > p2 = p1;

        p1->Go( );
        p2->Go( );
    }
```
>- reference count만을 관리하는 클래스를 `RefBase`로 따로 뽑자
>- 스마트 포인터로 관리하고 싶은 클래스는 모두 `RefBase`를 상속하게 하자.
>- 안드로이드에 `RefBase`가 있다. 또한, `sp`를 사용하여 관리하고 있다.

- 이제 조금 어려운 얘기를 할 건데… 이런게 있다…는 것만 기억하고 있어도 된다.
- 참조 계수의 스마트 포인터 상호 참조 문제인데, Life cycle에 관련된 참조 계수를 증가시키는 스마트 포인터인 Strong Pointer, 그리고 참조 계수를 증가시키지 않는 스마트 포인터인 Weak Pointer가 있다..
	- Strong Pointer 
		- c+ + : `shared_ptr`
		- Android : `sp`
	- Weak Pointer
		- c+ + : `weak_ptr`
		- Android : `wp`

- 다음 코드를 보자.
```
    // file : SmartPointer10.cpp

    #include <memory>

    struct Node {
        int data;
        shared_ptr< Node > next;

        ~Node( )
        {
            cout << “Node destroyed..” << endl;
        }
    };

    int main( )
    {
        shared_ptr< Node > p1 ( new Node );
        shared_ptr< Node > p2 ( new Node );

        p1->next = p2;  // 이 순간 대입 연산자(=)가 호출되면서 참조 계수가 증가
        p2->next = p1;  // 이 순간 대입 연산자(=)가 호출되면서 참조 계수가 증가.
    }
```
>- 구조체 `Node`내에 다음 `Node`를 가리키는 포인터를 스마트 포인터로 하고 싶다. 왜 ?? 자원관리를 해주니까…
>- 근데… 다음 연산을 할 때 대입 연산자가 호출되면서 참조 계수가 증가한다.<br>
>>- `p1->next = p2;`
>>- `p2->next = p1;`
>
>- 프로그램이 종료될 때 `Node` 객체가 파괴되지 않는다.. 스마트 포인터를 사용하는 이유가 사라졌다.!

- 다음 코드를 보자.( SmartPointer10.cpp 파일에서 한 줄 바꿔준다. )
```
    // file : SmartPointer11.cpp

    #include <memory>

    struct Node {
        int data;
        weak_ptr< Node > next;

        ~Node( )
        {
            cout << “Node destroyed..” << endl;
        }
    };

    int main( )
    {
        shared_ptr< Node > p1 ( new Node );
        shared_ptr< Node > p2 ( new Node );

        p1->next = p2;
        p2->next = p1;
    }
```
>- 다음을 가리키는 포인터로 `weak_ptr< >` 스마트 포인터를 사용하여 대입 연산시 참조 계수가 증가하지 않도록 한다.
>- 프로그램이 종료될 때, `Node` 객체개 파괴되는 것을 볼 수 있다.

- 다음은 C+ + 11 의 스마트 포인터 활용 예이다…
```
    // file : SmartPointer12.cpp

    #include <memory>

    struct Node {
        int data;
        weak_ptr< Node > next;

        ~Node( )
        {
            cout << “Node destroyed..” << endl;
        }
    };

    int main( )
    {
        shared_ptr< Node > sp1 ( new Node );
        weak_ptr< Node > wp2 = sp1; 

        {
            shared_ptr< Node > sp2 = wp1.lock( ); // create  a new shared_ptr
            if( sp2 ) {
                cout << “sp2 has copy of sp1..” << endl;
            }
        }

        sp1.reset( ); // release the ownership of the managed object to by ptr
        shared_ptr< Node > sp3 = wp1.lock( );
        if( sp3 ) {
            cout << “It’s impossible to reach here..” << endl;
        }
    }
```
>- 다음 페이지를 참조하면 스마트 포인터에 대해 좀 더 많이 알아볼 수 있다.
>>- [http://en.cppreference.com/w/cpp/memory](http://en.cppreference.com/w/cpp/memory)

- 이 정도면 될 것 같은데… 오픈 소스들을 보면 더 복잡하다..왜 그럴까 ??
- 다음 코드를 보자.
```
    // file : SmartPointer13.cpp

    class RefBase
    {
	    int m_count;

    public :
        RefBase( )
    : m_count( 0 )
        {
        }

        virtual ~RefBase( )
        {
        }

        void IncStrong( ) { ++m_count; }
        void DecStrong( ) { if( --m_count <= 0 ) delete this; }
    };

    class  Point : public RefBase
    {
        int x, y;

    public :
        Point( int a = 0, int b = 0 )
            : x( a ), y( b )
    	{
    	}

        void Print( ) const
      	{
    	}
    };

    int main( )
    {
        const Point p( 1, 2 );
        p.Print( );    // okay.. no problem
        p.IncStrong( );   // Q ? is it acceptable ??
	}
```
>- `const`로 생성된 객체에 대해서 살펴보자.
>- `Print` 멤버 함수는 `const`로 선언되었기 때문에 사용에 문제가 없다.
>- 참조 계수를 증가시키기 위한 `IncStrong( )`을 써야 하는데,, 내부의 멤버 변수 값을 변경하기 때문에 `const`로 선언할 수 없다 !!
- 이럴 땐 어떻게 해야 할 까 ?

- 다음 코드를 보자. 첫 번째 방법이다.. ( SmartPointer13.cpp 파일에서 수정 )
```
    // file : SmartPointer13.cpp

    class RefBase
    {
    	mutable int m_count;

    public :
        RefBase( )
    		: m_count( 0 )
        {
        }

        virtual ~RefBase( )
        {
        }

    	void IncStrong( ) const { ++m_count; }
        void DecStrong( ) const { if( --m_count <= 0 ) delete this; }
    };

    class  Point : public RefBase
    {
        int x, y;

    public :
        Point( int a = 0, int b = 0 )
            : x( a ), y( b )
    	{
    	}

        void Print( ) const
      	{
    	}
    };

    int main( )
    {
        const Point p( 1, 2 );
        p.Print( );    // okay.. no problem
        p.IncStrong( );   // Q ? is it acceptable ??
    }
```
>- `IncStrong( )`, `DecStrong( )` 함수를 `const`로 선언하고
>- `m_count` 변수를 `mutable`로 선언한다.

- 다음 코드는 두 번째 해결 방법이다. ( SmartPointer13.cpp 파일에서 수정 )
```
    // file : SmartPointer15.cpp

    struct weakref_impl {
        int m_count;    // sp로 관리되는 참조 계수
        int m_weak;     // wp로 관리되는 참조 계수
    };

    class RefBase
    {
    	weakref_impl* m_refs;

    public :
        RefBase( )
    	{
        	m_refs = new weakref_impl;
        }

        virtual ~RefBase( )
        {
        }

    	void IncStrong( ) const
    	{
    		++m_refs->m_count;
    	}

        void DecStrong( ) const
    	{
    		if( --m_refs->m_count <= 0 ) {
        		delete m_refs;
    			delete this;
    		}
        }
    };

    class  Point : public RefBase
    {
        int x, y;

    public :
        Point( int a = 0, int b = 0 )
            : x( a ), y( b )
        {
	    }

        void Print( ) const
    	  {
    	}
    };

    int main( )
    {
        const Point p( 1, 2 );
        p.Print( );    // okay.. no problem
        p.IncStrong( );   // Q ? is it acceptable ??
    }
```
>- 참조 계수만 관리하는 객체를 별도로 두어 해결한다.
>- `RefBase` 클래스의 `IncStrong( )`, `DecStrong( )` 에서는 `m_ref` 자체는 변경없고(주소가 그대로이고) `m_ref` 내의 변수 값이 변한다. 이것은 문제 없다.

- 정리하자..
- 안드로이드와 C+ + 표준에서 사용되는 스마트 포인터들은 다음과 같다..
	- 안드로이드
		- `sp` : 참조 계수 기반, `RefBase`의 child만 관리가 가능하다.
		- `wp` : 상호 참조 문제 때문에 사용, `RefBase`의 child만 관리가 가능하다.
		- `UniquePtr` : 복사 금지, 모든 타입에 대하여 사용 가능하다. 자원 관리 위해 만든 것이다.
	- C+ + 표준
		- `auto_ptr< >` : 소유권 이전
		- `shared_ptr< >` : 참조 계수 기반
		- `weak_ptr< >` : 상호 참조 문제 해결을 위해 사용.
		- `unique_ptr< >` : 복사 금지

- 복사 금지를 알아보자.
```
    // file : SmartPointer16.cpp

    template< typename T >
    class ptr
    {
        T* m_ptr;

    public :
        ptr( T* tp = 0 )
            : m_ptr( tp )
        {
        }

        ~ptr( )
        {
            delete m_ptr;
        }

        inline T* operator->( ) { return this->m_ptr; }
        inline T& operator*( ) { return *(this->m_ptr); }

    private :
        ptr( const ptr& p );
        void operator=( const ptr& p );
    };

    int main( )
    {
        ptr< int > p1 ( new int );
        *p1 = 10;
    }
```
>- 단지 자원 관리 용도로만 사용하고 복사/대입을 하지 않을 거라면 참조 계수는 필요 없다.
>- 대신 사용자가 실수 할 수 없도록 하자. ( 복사를 금지시켜 버리자.. )
>- boost에는 `scoped_ptr< >` 이 있다..
>- 배열을 사용하고 싶으면 어떡하지 ????
> `ptr< int > p3 ( new int[ 10 ] );`
>- 삭제할 때 배열인지 아닌지 구분해서 해야 한다.

- 다음 코드를 보자. 복잡해도 천천히 이해해보자.
```
    // file : SmartPointer17.cpp

    template< typename T >
    struct DefaultDelete
    {
        inline void operator( )( T* p )
        {
            delete p;
            cout << “delete pointer..” << endl;
        }
    };

    // partial specialization for array.
    template< typename T >
    struct DefaultDelete< T[ ] >
    {
        inline void operator( )( T* p )
        {
            delete[ ] p;
            cout << “delete array..” << endl;
        }
    };

    template< typename T, typename D = DefaultDelete< T > >
    class ptr
    {
        T* m_ptr;

    public :
        ptr( T* tp = 0 )
            : m_ptr( tp )
        {
        }

        ~ptr( )
        {
            D del;
            del( m_ptr );
        }

        inline T* operator->( ) { return this->m_ptr; }
        inline T& operator*( ) { return *(this->m_ptr); }

    private :
        ptr( const ptr& p );
        void operator=( const ptr& p );
    };

    // partial specialization
    template< typename T, typename D >
    class ptr< T[ ], D >
    {
        T* m_ptr;

    public :
        ptr( T* tp = 0 )
            : m_ptr( tp )
        {
        }

        ~ptr( )
        {
            D del; // D는 함수 객체이다. () 연산자를 호출하여 삭제한다.
            del( m_ptr );
            // del은 임시 객체 이므로 위 두 라인을 다음과 같이 사용할 수 있다.
            // D( )( m_ptr );
        }

        // array 연산자를 재정의한다.
        inline T& operator[ ]( int n ) { return *(this->m_ptr + n ); }

    private :
        ptr( const ptr& p );
        void operator=( const ptr& p );
    };

    int main( )
    {
        ptr< int > p1 ( new int );
        *p1 = 10;

        ptr< int[ ] > p2 ( new int[ 10 ] );
    }
```
>- 삭제 방법을 전략 패턴화 하자.
>- 기본 삭제를 위한 `template` 구조체 `DefaultDelete`를 만든다..
>- 배열 삭제을 위한 템플릿 전문화 구조체를 정의한다.
>- 기본 삭제를 지원하는 스마트 포인터 템플릿 `ptr`을 만든다.
>- 배열 사용을 위한 템플릿 전문화 스마트 포인터를 정의한다.
>>- 이때 `operator[ ]` 연산자를 재정의하는 것을 주의한다.
>
>```
	D del;
	del( m_ptr );
>```
>- 이 두 라인은 다음과 같이 한 줄로 표현 가능하다.
>```
	D( )( m_ptr );
>```
>- `del`은 함수 객체이자 임시 객체 이므로..


<p>
___
<p>
### 변환
1. 객체의 변환에 관련한 이야기이다..
2. 다음에 대하여 얘기할 건데,,,
	- 변환 연산자 : 객체( `Point` ) => 다른 객체 타입 ( `int` )
	- 변환 생성자 : 다른 타입 ( `int` ) => 객체 ( `Point` )

-	다음 코드를 보자.
```
    // file : Explicit01.cpp

    class Point
    {
    public :
        Point( )
            : x( 0 ), y( 0 )
        {
        }

        Point( int a, int b )
            : x( a ), y( b )
        {
        }

    private :
        int x, y;
    };

    int main( )
    {
        double d = 4.4;
        int n = d;    // okay, double  int 암시적 변환 허용

        Point p1;     // 파라미터가 없는 생성자 호출
        Point p2( 2, 1 );  // 파라미터가 두 개인 생성자 호출

        int n2 = p1; /// ???   Point  int ???
        p2 = n;       /// ???   int  Point ???
    }
```
>- primitive 타입은 암시적 변환을 허용한다.
>- custom class의 타입 변환을 위해서는 변환 생성자와 변환 연산자를 사용해야 한다..

- 다음 코드를 보자. ( Explicit01.cpp 에서 수정 )
```
    // file : Explicit02.cpp

    class Point
    {
    public :
        Point( )
            : x( 0 ), y( 0 )
        {
        }

        Point( int a, int b )
            : x( a ), y( b )
        {
        }

        // int를 Point로 바꾸기 위한 변환 생성자.
        Point( int a )
            : x( a ), y( 0 )
        {
        }

        // Point를 int로 바꾸기 위한 변환 연산자
        // 객체를 다른 타입이 되도록 한다.
        // 선언할 때 리턴 타입을 표시하지 않는다…
        operator int( ) { return this->x; }

    private :
        int x, y;
    };

    int main( )
    {
        double d = 4.4;
        int n = d;    // okay, double  int 암시적 변환 허용

        Point p1;     // 파라미터가 없는 생성자 호출
        Point p2( 2, 1 );  // 파라미터가 두 개인 생성자 호출

        int n2 = p1; /// ???   p1.operator int( ) 호출
        p2 = n;       /// ???   n.operator Point( ) 는 없다..그래서 변환 생성자를 만든다.
    }
```
>- 변환 생성자.
>>-	다른 타입을 해당 객체로 만들고자 할 때,, 주로 primitive 타입을…
>
>- 변환 연산자
>>- 객체를 다른 타입으로 바꿀 때.
>>- 선언할 때 리턴 타입을 표시하지 않는다.

- 객체를 변환 할 수 있으면 뭐가 좋을까 ?? 왜 이걸 알아야 할까 ??
- 자원 관리를 생성자/소멸자가 하게 하자… RAII 라는 기술인데…
	- RAII – Resource Acquisition Is Initialization.

- 다음 코드를 보자.
```
    // file : Explicit03.cpp

    #include <stdio.h>

    class OFile
    {
    public :
        OFile( const char* name, const char* mode = “wt” )
    	{
        	fp = fopen( name, mode );
        }

        ~OFile( )
    	{
        	fclose( fp );
        }

        // operator FILE*( ) { return fp; }

    private :
        FILE* fp;
    };

    int main( )
    {
        OFile f( “a.txt” );
        // 다음과 같이 f를 일반 FILE descriptor 처럼 활용하고 싶은데…
        fputs( “hello\n”, f );
        fprintf( f, “%d\n”, 10 );
        // 가능할까 ???
        // OFile  FILE* 라면 되지 않을까 ????
    }
```
>- `OFile` 객체가 생성될 때 파일을 열고 객체가 소멸될 때 자동으로 파일을 닫히게 한다.
>- 목적하는 바(자원 관리, RAII )는 이루었으나, `FILE` descriptor를 사용하기 위해 추가로 멤버함수를 추가해야 한다. 근데 이게 귀찮으니,,,
>- `OFile`을 `FILE*` 로 변환할 수 있으면 되지 않을까 ??
>- 주석 처리한 변환 연산자를 사용하면 가능하다.
>>- `operator FILE*( ) { return fp; }`

- 이게 좋기만 할까 ?? 그럼 막 쓰면 좋겠네 ???
- 다음 코드를 보자.( Explicit03.cpp에서 수정  )
```
    // file : Explicit04.cpp

    #include <stdio.h>

    class OFile
    {
    public :
        OFile( const char* name, const char* mode = “wt” )
        {
            fp = fopen( name, mode );
        }

        ~OFile( )
        {
            fclose( fp );
        }

        operator FILE*( ) { return fp; }

    private :
        FILE* fp;
    };

    void foo( OFile f )
    {
    }

    int main( )
    {
        OFile f( “a.txt” );
        fputs( “hello\n”, f );
        fprintf( f, “%d\n”, 10 );

        foo( f ); // okay. but, double free error…
        foo( “hello” ); // ?????
    }
```
>- `Ofile`을 인자로 하는 함수 `foo`를 선언하였고
>- `Ofile` 객체 `f`를 인자로 하는 `foo` 함수 호출 한 번과 `“hello”`를 인자로 하는 `foo` 함수 호출 한 번 했다.
>- `foo( f );` 는 당연히 문제 없겠지만 ( `fp`의 `double free` 에러가 run-time에 발생한다. )
>- `foo( “hello” )`에서 `“hello”`가 `OFile` 객체로 변환되고 있다.. 즉, `const char*` => `OFile` 되었다..헉.!!
>- 이러한 암시적 변환을 막는 방법 중 하나가 `explicit` 생성자이다..

- 다음 코드를 보자.( explicit04.cpp 에서 수정 )
```
    // file : Explicit05.cpp

    #include <stdio.h>

    class OFile
    {
    public :
        explicit
        OFile( const char* name, const char* mode = “wt” )
        {
            fp = fopen( name, mode );
        }

        ~OFile( )
        {
            fclose( fp );
        }

        operator FILE*( ) { return fp; }

    private :
        FILE* fp;
    };

    void foo( OFile f )
    {
    }

    int main( )
    {
        OFile f( “a.txt” );
        fputs( “hello\n”, fp );
        fprintf( f, “%d\n”, 10 );

        foo( “hello” ); // compile-time error !!!!!
    }
```
>- `OFile` 생성자 앞에 `explicit` 키워드를 추가하여 인자가 하나뿐인 생성자가 암시적 변환을 일으키는 것을 막아준다.

- 다음 코드를 보자.
```
    // file : Explicit06.cpp

    class Test
    {
    public :
        explicit
        Test( int n = 0 )
            :  value( n )
        {
        }

        operator int( ) { return value; }

    private :
        int value
    };

    int main( )
    {
        Test t1( 5 ); // 인자가 하나인 생성자 호출
        Test t2 = 5;  // ㄱ. 5를 변환 생성자를 통해서 Test 객체로 변환해서 임시 객체 생성
                         // ㄴ. 그리고 임시 객체를 복사 생성자를 통해서 t2에 복사.
    }
```
>- 다음 두 코드의 차이를 알아야 한다.
>```
	Test T1( 5 );
	Test t2 = 5;
>```
>- `Test` 생성자에 `explicit`을 선언하여 `int`가 `Test` 객체가 되는 것을 막는다.!!

- 정리하면
	- 변환 연산자는 편리할 때가 많다.
	- 변환 연산자는 위험할 때가 많다.. – 되도록 막자.
