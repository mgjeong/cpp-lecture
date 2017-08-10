# C++ Lecture 

___
## Day 1
### Synopsis
- Creation : 2015. 06. 04
- Last Modified : 2017. 07. 18
- Version : 1.1
- Author : MJ( mg.jeong )
___
### Contents
- 함수 오버로딩
- 함수 오버로딩
- 함수 템플릿
- 인라인 함수
- 참조 리턴
- 멤버함수 포인터
- 상수함수
- 복사생성자
- 싱글톤

<p>
___
<p>
### 함수 오버로딩( overloading )
1. 개념 : parameter의 수, 타입이 다르면 같은 이름의 함수를 2개 이상 만들 수 있다.
2. 장점 : 일관성 있는 라이브러리를 개발할 수 있다.. 사용자는 함수가 한 개 있는 것처럼 보인다.
3. 원리 : 컴파일 시간에 함수 이름을 변경한다. --> name mangling
4. 강의 내용
- Overloading 사용법 - 우선 다음과 같은 코드를 보자.
```
    // file : Overloading01.c
    #include <iostream>
    using namespace std;
    
    int square( int a )  // 컴파일러가 보면 square_int( int a )
    {
    	return a*a;
    }

	double square( double d ) // square_double( double d )
	{
		return d*d;
	}

	int main( )
	{
		int n = square(3);
		double d = square(3.3);

		return 0;
	}
```
>- `square` 라는 이름의 함수가 두 개가 존재한다.<br>
하나는 `int` 타입을 파라미터로 하고 다른 하나는 `double` 타입을 파라미터로 하고 있다.
>- `main` 함수에서는 동일한 이름의 함수를 구분 없이 사용하고 있다.<br>
리턴 변수에 대한 저장은 함수를 사용하는 개발자가 구분하여야 한다.
- 이게 가능한 이유는 C+ + 컴파일러가 컴파일 시간에 함수 이름을 변경하기 때문이다.<br>
이것을 name mangling이라고 한다.
- 컴파일러가 보면 `int square( int a )` 는 `square_int( int a )` 이고,
`double square( double d )` 는 `square_double( double b)` 이다.
즉 다른 함수로 보인다.. ( 실제 mangled name은 이렇지 않다. )
- 여기까지는 C+ + 개발자들은 이미 알고 있는 내용이다. 
- 이걸 라이브러리로 만드는 건 다음과 같이 하자.<br> 
( c/c++을 동시 지원하려면 name mangling을 막아야 해서 overloading이 안된다. )
```
	// file : square.h
	#ifdef __cplusplus
	extern "C"
	{
	#endif

	int square( int a );

	#ifdef __cplusplus
	}
	#endif
```
```
	// file : square.c
	#include "square.h"

	int square( int a )
	{
    	return a * a;
	}
```
```
	// file : Overloading02.c
	#include <iostream>
	#include "square.h"
	using namespace std;

	int main( )
	{
    	cout << square( 3 ) << endl;

    	return 0;
	}
```
>- `extern “C”` 는 C+ + 컴파일러에게 C 처럼 컴파일 해달라는 지시어로 name mangling을 막아준다.
>- 모든 c++ compiler는 `__cplusplus` 라는 매크로를 제공한다.
>- 컴파일러 예약어는 `_` 또는 `__` 로 시작한다
- overloading을 하고 싶은데, c/c++ 동시 지원하려면 name mangling 문제로 호환성의 문제가 있다.
- c/c++ 모두 지원하는 라이브러리를 만드려면, 
    - **library 자체는 .c 파일로 만들어 name mangling을 막고,**
    - **header 파일은 조건부 컴파일을 하도록 한다.**

<p>
___
<p>
### 함수 템플릿 ( Function Template )
1. 코드 생성기를 이용한 함수의 템플릿화와 컴파일러에서 지원하는 코드 템플릿을 알아보자..
2. 부제 : `template` 어렵지 않아요~
3. 강의 내용
- 기본적인 overloading 방법은 다음과 같다.
```
    // file : FunctionTemplate01.cpp
    int Max( int a, int b )
    {
        return a < b ? b : a;
    }

    double Max( double a, double b )
    {
        return a < b ? b : a;
	}

	int main( )
	{
		int n = Max( 1, 2 );
    	double d = Max( 3.1, 4.5 );
	}
```
>- type이 계속 늘어난다면 ??? 계속 overloading 하면 된다.
>- 유사한 코드가 반복된다면, 코드 생성기를 활용하자.<br>
( 아래 참고 사항 먼저 설명하자. )
- 매크로를 이용한 코드 생성방법은 다음과 같다…
```
    // file : FunctionTemplate02.cpp
	#define MAKE_MAX( T )    \
	T    Max( T a, T b )    { return a < b ? b : a; }

	MAKE_MAX( int )
	MAKE_MAX( double )

	int main( )
	{
		int n = Max( 1, 2 );
		double d = Max( 3.1, 4.5 );
	}
```
>- 위 방법의 단점은 컴파일러는 타입을 알지만 매크로는 타입을 모른다.( 문자 치환만 하니까 )
>- 그래서 어떤 타입에 대한 함수가 필요한지 꼭 미리 선언해야 한다.
>`MAKE_MAX( int )`, `MAKE_MAN( double )` 처럼.
>- 참고로 간단하게 다음과 같이 할 수도 있지만, 함수 템플릿을 설명하는 거니까 주제에 맞지 않고 또한 secure 하지도 않다.

```
	#include <iostream>
    using namespace std;
    
	#define MAX( a, b ) ( (a) > (b) ? (a) : (b) )
	int main( )
	{
    	char c = 'a';
    	cout << "MAX( c, 2 ) = " << MAX( c, 2 ) << endl;  // ?????

	return 0;
	}
```

- 미리 선언하지 않고 사용할 수 있는 방법은 없을까 ??<br>
--> **컴파일러에 의한 코드 생성 기술인 `template` 이 있다.**
- 다음 코드를 보자.
```
	// file : FunctionTemplate03.cpp
	template< typename T >
	T Max( T a, T b ) { return a < b ? b : a; }

	int main( )
	{
		int n = Max( 1, 2 );
		double d = Max( 3.1, 4.5 );
	}
```
>- `template` 만드는 방법은 코드 생성을 위한 `macro`를 복사하고, 앞 부분만 `template`로 바꾼다.
>- 코드 생성은 컴파일 시간에 이루어진다.
>- `int n = Max( 1, 2 );`  // 이 때, `int Max( int, int )` 함수를 생성한다.
>- `double d = Max( 3.1, 4.5 );`  // 이 때, `double Max( double, double )` 함수를 생성한다.
>- 기계어로 바꾸어서 한 번 봐보자.
>- `$ g++ -S ftemplate03.cpp` // `-S` 옵션으로 기계어 생성
- `template` 창시자…. “`macro`를 컴파일 타임에 해석하고 싶었다.”

- 다음은 어떻게 될까 ??
```
	// file : FunctionTemplate03.cpp
	template< typename T >
	T Max( T a, T b ) { return a < b ? b : a; }

	int main( )
	{
		int n = Max( 1, 2 );
		double d = Max( 3.1, 4.5 );
    	// ---- 아래 부분 추가
		short s1=3, s2=4;
    	Max(s1, s2);  // <Quiz>
		Max<int>(s1, s2);
	}
```
>- 보기 )
>>1. `Max( int, int )` 버전을 사용할 것이다.
>>2. `Max( short, short )` 버전을 만들 것이다..

>- 정답은 2.
>- 이것을 암시적 추론이라고 한다.. 
- 이것 ( Code Bloat )을 예방하기 위해 명시적으로 타입을 결정할 수 도 있다.
	>>- `Max< int >(s1, s2);`
	>>- 무조건 타입 `T` 를 `int`로 해달라고 하는 것.

>- 명시적 추론으로 사용자가 결정한다.

- Code Bloat
	- `template`을 잘못 사용하면 너무 많은 함수, 클래스가 생성되어 메모리 오버헤드를 발생시키는 것으로 막기 위한 다양한 기술들이 있다…<br>
다음 강의 때 설명하자.
- `template` 인스턴스화는
	- 암시적 방법 : 컴파일러가 결정하는 방법
	- 명시적 방법 : 사용자가 직접 결정하는 방법<br>
	방법이 있다.

<p>
___
<p>
### 인라인 함수( Inline Function )
1. 함수 호출의 원리
	1. 마지막 파라미터부터 스택에 넣고 해당하는 함수로 jump한다.
	2. 그래서 함수 호출에는 약간의 오버헤드가 있다.
	3. 빈번하게 호출되는 함수의 오버헤드를 줄일 수 있다면 ??? 수행 시간이 줄어들겠지.
2. 인라인 함수 개념
	1. 함수 호출을 기계어 코드로 치환한다.
	2. 장점은 빠르다.
	3. 단점은 object code의 크기가 커질 수 있다. 그리고 디버깅이 어렵다.
		- 작은 함수의 인라인 치환은 object code의 크기를 줄이기도 한다.
3. 개발시에는 인라인 치환하지 않고 릴리즈 때 하는게 좋다.
4. 디버그 모드에서는 인라인 치환이 안된다.
5. 강의 내용
- 인라인 함수 사용법
```
	// file : Inline01.cpp
	int Add1( int a, int b )
	{
		return a + b;
	}

	inline int Add2( int a, int b )
	{
		return a + b;
	}

	int main( )
	{
		int n1 = Add1( 1, 2 );
		int n2 = Add2( 1, 2 );
	}
```
>- 함수 선언 앞에 `inline` 이라고 명시한다.
>- `int n1 = Add1( 1, 2 );` 부분을 기계어로 보면 ( `$ g++ -S inline01.cpp` )
```
	push 2
	push 1
	call ?Add@@xx…
```
> 와 같은 코드로 해석되어 있다.
>- `Add2`도 동일하게 보인다.
>- 최적화 option을 주면 `Add2는` 보이지 않는다. ( `$ g++ -O3 -S inline01.cpp` )

- **인라인 함수와 함수 포인터** – 중요하고도 어렵습니다.
	- 인라인 함수는 컴파일 타임에 적용되는 문법이다.
	- 아무리 인라인 함수라도 함수 포인터를 사용하여 호출하면 인라인 치환될 수 없다.
	- 이 사실이 왜 중요하다고 하는가 ???
	- 라이브러리 설계자를 생각해 보자.
- 다음 코드를 보자.
```
	// file : Inline02.cpp
	inline void swap( int& a, int& b )    // #include <algorhthm>으로 대신해도 된다.
	{
		int tmp = a;
		a = b;
		b= tmp;
	}

	void sort( int* x, int n )
	{
		for( int i=0; i<n; i++ ) {
			for( int j=i+1; j<n; j++ ) {
				if( x[i] > x[j] )             // criteria는 변경될 수 있다.
    				swap( x[i], x[j] );
			}
		}
	}

	int main( )
	{
		int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
		sort( x, 10 );
	}
```
>- 라이브러리 설계자가 중요하게 생각해야 하는 것은.
>>- 성능 : 빨라야 한다.
>>- 유연성 : 정책 변경이 가능해야 한다.

>- 위 코드에서 `sort` 함수의 성능은 빨라야 하고 정책이 되는 criteria,<br>
즉 `if( x[i] > x[j] )` 부분은 변경이 가능해야 한다.

- 변하지 않는 전체적인 알고리즘과 변해야 하는 세부 정책은 분리되어야 한다.
	- c 에서는 변하는 것을 “function parameter”로 만들면 된다.
- 다음 코드를 보자. ( inline02.cpp 파일을 수정해서 )
```
	// file : Inline03.cpp
	inline void swap( int& a, int& b )
	{
		int tmp = a;
		a = b;
		b= tmp;
	}

	void sort( int* x, int n, bool ( *cmp )( int, int ) )
	{
		for( int i=0; i<n; i++ ) {
			for( int j=i+1; j<n; j++ ) {
            	if( cmp( x[i], x[j] ) )
    				swap( x[i], x[j] );
			}
		}
	}

	bool cmp1( int a, int b )    { return a < b; }
	bool cmp2( int a, int b )    { return a > b; }

	int main( )
	{
		int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
		sort( x, 10, cmp1 );
	}
```
>- 기존 `sort` 함수에서 criteria가 변경 가능하도록 함수를 파라미터로 전달하도록 변경하였다.
>- 이 때, `cmp` 함수는 빈번하게 호출되는 것을 볼 수 있다.
>- 성능 향상을 위해서 `cmp` 의 implementation 함수를 `inline`으로 선언하자..<br>
그럼 빨라지겠지…
```
    inline bool cmp1( int a, int b )    { return a < b; }
    inline bool cmp2( int a, int b )    { return a > b; }
```
>- 정말 빨라질까 ????

- 다음 코드를 보자.
```
	// file : Inline04.cpp
	void foo( int a ) { }
	inline void goo( int b) { }

	int main( )
	{
		foo( 1 );	// 호출 !!
		goo( 1 );	// 치환 !!

		void ( *f ) ( int );
		int n = 0;
		cin >> n;
		if( n == 0 )
			f = &goo;
		else
			f = &foo;

		f(1);
	}
```
>- `foo( 1 )`, `goo( 1 )` 은 명확하게 구분할 수 있다.
>- 그러나 `f( 1 )` 이 호출될 때 `foo`가 될지, `goo`가 될지 알 수 없다.<br>
즉, `goo`로 치환될 수 없다

- **함수보다 빠른 함수 객체**
	- 객체의 `operator( )`연산자를 재정의하여 함수처럼 사용하는 것.
	- 왜 이걸 사용하는가 ???
		- 모든 함수 객체는 자신만의 타입이 있다.
		- singnature( 리턴 타입, 파라미터의 수와 타입 )가 동일한 함수는 모두 같은 타입이지만 함수 객체는 signature가 같아도 다른 타입이다..<br>
          이게 무슨 소리냐면,,,
- 다음 코드를 보자. ( inline03.cpp 에서 `LESS`, `GREATER` 추가, `sort` 함수 선언 변경 )
```
	// file : Inline05.cpp
	inline void swap( int& a, int& b )
	{
		int tmp = a;
		a = b;
		b= tmp;
	}

	struct LESS
	{
    	inline bool operator( )( int a, int b )    { return a < b; }
	};

	struct GREATOR
	{
    	inline bool operator( )( int a, int b )    { return a > b; }
	};

	void sort( int* x, int n, LESS cmp )
	{
		for( int i=0; i<n; i++ ) {
			for( int j=i+1; j<n; j++ ) {
       	     if( cmp( x[i], x[j] ) )
    				swap( x[i], x[j] );
			}
		}
	}

	int main( )
	{
    	LESS cmpl;
		int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

		sort( x, 10, cmpl );
	}
```
>- 먼저 객체의 선언( 여기서는 구조체)에 연산자( )를 정의한다.<br>
`LESS`와 `GREATER` 구조체 두 개를 선언하였고 각 각의 ( ) 연산자에는 크기 비교 결과를 반환하도록 정의하였다.
>>- 여기서 잠깐, c++에서 구조체 `struct`나 `class`는 동일하다. 아래와 같이 선언해도 동일하다.
```
	class Less
	{
	public : 
    	inline bool operator( )( int a, int b )    { return a < b; }
	}
```
>>- `struct` 선언 내에 구현까지 포함되어 있으면 자동적으로 `inline` 이다.

>- `sort` 함수의 정의에 `LESS` 또는 `GREATER` 타입을 파라미터로 한다.<br>
>함수 포인터가 아니므로( 타입이 결정되어 있으므로 ) `inline` 치환이 가능해진다.
>- 그러나 criteria가 고정되게 된다. `LESS` 또는 `GREATER`를 선택하거나 두 개의 `sort` 함수를 만들어야 한다.
>-	두 개의 `sort` 함수의 코드는 반복된다.. 이럴 때 무엇을 사용한다 ??  코드 생성기.!!!<br>
매크로는 건너뛰고 `template`로 가보자

- 다음 코드를 보자. ( inline05.cpp에서 sort 함수의 선언을 template로 변경 )
```
	// file : Inline06.cpp
	inline void swap( int& a, int& b )
	{
		int tmp = a;
		a = b;
		b= tmp;
	}

	struct LESS
	{
    	inline bool operator( )( int a, int b )    { return a < b; }
	};

	struct GREATOR
	{
    	inline bool operator( )( int a, int b )    { return a > b; }
	};

	template< typename T >
	void sort( int* x, int n, T cmp )
	{
		for( int i=0; i<n; i++ ) {
			for( int j=i+1; j<n; j++ ) {
            	if( cmp( x[i], x[j] ) )
    				swap( x[i], x[j] );
			}
		}
	}

	int main( )
	{
    	LESS cmpl;
    	GREATER cmpg;

		int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

		sort( x, 10, cmpl );
		sort( x, 10, cmpg );
	}
```
>- `sort` 함수 선언에 변경이 가능한 criteria 파라미터를 `template`로 처리
>- `sort` 함수가 사용될 때 인자인 compare criteria에 따라 해당하는 타입을 가지는 코드가 생성.
>- 코드가 생성되는 건 컴파일 타임이다.. 즉 인라인 치환이 가능하게 되고 반복되는 코드의 수행 속도를 향상시킬 수 있다.
>- 함수 객체에 대해선 다음에 좀 더 자세히 알아보자.

- 위에서 살펴본 코드들은 이미 다 표준 헤더 파일에 구현되어 있다. 수십 개의 함수 객체가 이미 C++ 표준에 들어가 있다.. `less`, `greater` 이미 있다.
- `algorithm`, `functional` 헤더를 `include` 하면 사용 가능하다.
```
	// file : Inline07.cpp
	#include <algorithm>
	#include <functional>

	bool cmp1( int a, int b ) { return a < b; }
	bool cmp2( int a, int b ) { return a > b; }

	int main( )
	{
		int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

		sort( x, x+10, cmp1 );  // sort( int*, int*, bool(*cmp)(int, int) ) 함수 생성
		sort( x, x+10, cmp2 );  // 마지막 인자가 T 로 되어 있어서.

		less< int > f1;
		greater< int > f2;

		sort( x, x+10, f1 );  // sort( int*, int*, less ) 함수 생성
		sort( x, x+10, f2 );  // sort( int*, int*, greater ) 함수 생성

	}
```

<p>
___
<p>
### 참조 리턴
1. 객체( 구조체, 클래스 )를 값으로 리턴하면 '임시 객체'가 생성된다.
	1. 리턴하고자 하는 객체와 동일하게 생긴 '임시 객체'가 생성되어서 리턴된다.
	2. '임시 객체'가 없으면 지역 변수를 절대 리턴할 수 없다.
	3. '임시 객체'는 성능 저하의 원인이 된다.
2. '임시 객체'를 제거하고자 참조를 리턴하는 경우가 많다.
3. 강의 내용
- 참조( Reference ) : 기존 메모리에 별명( 또 다른 이름 )을 부여하는 것.
```
	#include <iostream>
    using namespace std;
    
	int main( )
	{
    	int n = 10;		// declaration & initialization
                   		// 메모리 할당됨, 타입과 크기가 필요
    	int* p = &n;	// p도 변수이고 n의 주소를 담기 위한 메모리 공간이 할당된다.
    	int& r = n;		// 기존 메모리(n)에 대한 별명, r을 위한 메모리 공간은 할당되지 않는다.

		r = 20;
    	cout << “n = “ << n << endl; // 20

		//------------------------------------------------------------------------

    	int& r2;		// ERROR !!, 참조 변수(객체)를 선언할 때는 초기화 함께 해야한다.
                  		// error: ‘r2’ declared as reference but not initialized

    	int*& rp = p;	// 포인터 변수 p의 별명. rp is reference of pointer to int.
                        // 원하는 값(value)은 *rp에 있다.

    	int&* pr = &r;  // 참조 변수의 포인터. r의 포인터, pr is pointer to reference of int
                        // ERROR !!, reference는 주소 공간이 없기 때문에 포인터로 가리킬수 없다
                        // error: cannot declare pointer to ‘int&’

    	int( *f )( void ) = main;  // 함수의 포인터 
    	int( &r )( void ) = main;  // 함수의 별명도 가능하다…

	}
```
- 다음 코드를 보자
```
	// file : ReferenceReturn01.cpp
	#include <iostream>
	using nemestace std;

	struct Point {
    	int x;
	    int y;
	};

	Point p = { 1, 2 };

	Point foo( )
	{
    	return p;    // 전역 변수로 선언되었지만 값으로 리턴한다.
	}

	int main( )
	{
		foo().x = 10;   // ????
		// 임시 객체는 여기서 파괴된다..
		cout << “p.x = “ << p.x << endl;  // ???
	}
```
>- 함수 `foo( )` 에서는 `p`를 값으로 반환한다.
>- `foo()`의 리턴인 `p`의 `x`에 `10`을 대입한다…
>>-	C 에서는 error 발생, C++은 error 발생하지만 빌드는 된다.

>- 출력되는 `p.x` 의 값은 ???
>>	- `1` 나온다… 왜냐면..

>- `foo( )`를 호출하여 반환된 ‘임시 객체’는 곧바로 파괴된다

- 다음 코드를 보자 ( ReferenceReturn01.cpp 파일에서 수정)
```
	// file : ReferenceReturn02.cpp
	#include <iostream>
    using namespace std;

	struct Point {
    	int x;
    	int y;
	};

	Point p = { 1, 2 };

	Point& foo( )    // foo함수의 반환 타입이 바뀌었다.
	{
    	return p;    // 전역 변수로 선언되었지만 값으로 리턴한다.
	}

	int main( )
	{
		foo().x = 10;   // ????
		cout << “p.x = “ << p.x << endl;  // ???
	}
```
>- '임시 객체'를 만들지 말고 p의 별칭(참조, reference, aliasing)을 리턴해 달라.
>- 	출력되는 p.x의 값은 ??
>>- 10 이다…

- 정리하면,
	- 임의의 함수가 값을 리턴하면,
		- primitive type의 경우, (eg. `int foo( )` )는 상수로 리턴된다.
		- user defined type의 경우, (eg. `Point foo( )` )는 임시 객체가 리턴된다.
	- 함수의 리턴이 참조라면 
		- primitive type의 경우는 함수 호출을 lvalue에 놓겠다는 의미이다.( eg. `foo( ) = 10;` )
		- user defined type의 경우는 임시 객체를 제거하겠다는 의미이다.

- 다음 코드를 보자. 
```
	// file : ReferenceReturn03.cpp

	void foo( int n )	{ ++n; }
	void goo( int* p )	{ ++( *p ); }
	void hoo( int& r )	{ ++r; }

	int main( )
	{
    	int x=1, y=1, z=1;
    	foo( x );    // call by value          x = 1
    	goo( &y );   // call by pointer       y = 2
    	hoo( z );    // call by reference     z = 2

    	return 0;
	}
```
>- reference로 파라미터 설정하는게 좋은 거 아닌가 ? 복잡성, 메모리 효율 측면에서..
>- 그러나 코드의 가독성은 포인터가 더 좋다…
>>- `goo( &y );` 를 보면 `y` 값이 변할 것을 안다.
>>- `hoo( z );` 는 `z`가 변할지 아닐 지 모른다

- Reference를 써야 하는 상황은 무엇인가 ??? 다음 코드를 보자.
```
	// file : ReferenceReturn04.cpp

	struct Data {
    	int buf[ 1000 ];
	};

	void foo( Data a )
	{
    	// a 는 바꾸지 않는다..!!!
	}

	int main( )
	{
    	Data x;
    	x.buf[ 0 ] = 10;
    
    	foo( x );
	}

	// ----------------  TO-BE -----------------------

	void foo( const Data& a )
	{
	}
```
>- `void foo( Data a )` 는 절대 인자값을 바꾸지 않을 것이라는 약속이다.<br>
하지만 메모리를 두 배로 사용하게 된다. ( 임시 객체 )
>- `void foo( Data& a )`는 임시 객체를 만들지 안아 메모리를 낭비하지는 않는다.<br>
그러나 인자값이 바뀔 수 있다.
>- `void foo( const Data& a )` … 인자 값이 바뀌지 않고, 메모리도 낭비하지 않는다.
>- 다음 중 어떤 것이 좋은 가 ?
>>- `void foo( int a )`
>>- `void foo( const int& a )`
>>- 답은 위에 것… primitive 타입은 overhead가 크지 않다. 그리고 `const T&`로 하면 컴파일러가 최적화 할 수 없다.

>-	정리해서, 함수가 인자 값을 변경하지 않는다면,
>>-	**primitive type은 call by value가 좋고**
>>- **user type은 const T&를 사용하자.**

- 다음 코드를 보자
```
	// file : ReferenceReturn05.cpp

	template< typename T >
	class Stack
	{
	public :
    	Stack( ) : index( -1 ) { }
    	void push( const T& a ) { buff[ ++index ] = a; }
    	void pop( ) { --index; }
    	T& top( ) { return buff[ index ]; }

	private :
    	T buff[ 10 ];
    	int index;
	};

	int main( )
	{
    	Stack< int > s;
    	s.push( 10 );
    	s.push( 20 );

    	int& r = s.top( );	// buff[1] == r
    	s.pop( );			// r = 20
    	s.pop( );
	}
```
>- `template` 기반의 컨테이너 성능 최적화 이야기 인데, `T`가 객체일 수 있으니 최적화 하자…
>- `push` 함수는 call by value 보다 `const T&` 가 좋다.
>- `pop` 함수가 제거와 리턴을 동시에 하면 최적화 할 수 없다.
>- 제거한 후 리턴하면 참조를 시킬 방법이 없어, 리턴하면 제거할 방법이 없다.
>- 제거와 리턴을 분리하여 `pop`, `top` 함수를 별도로 만든다.
>- STL의 구현이 이와 같다.

<p>
___
<p>
### 멤버 함수 포인터
1. 일반적으로 멤버 함수를 가리키기 위해서 `this`를 사용하는데,,,
- 다음 코드를 보자
```
	// file : MemberFunctionPointer01.cpp

	class Point
	{
    	int x;
    	int y;

	public :
    	void set( int a, int b ) {	// 컴파일하면, set( Point* const this, int a, int b);
 			x = a;    // this->x = a;
 			y = b;    // this->y = b;
 		}

    	static void foo( int a ) {	// 컴파일 하면, void foo( int a );
 			// x = a;         // ????? this->x =a 가 되어야 하는데, this가 없다. 
		}
	};

	int main( )
	{
    	Point p1;
    	p1.set( 10, 20 );
    	p1.foo( 20 );

    	Point::foo( 10 );
	}
```
>- 중요한 건데, C+ + 개발자는 반드시 알고 있어야 한다.<br>
> C+ +의 일반 멤버 함수는 첫 번째 인자로 `this`가 추가된다. 즉, 
```
	void set( int a, int );
	// -> void set( Point* const this, int a, int b );
```
> `Point* const this` 가 컴파일러에 의해 추가된다.

>- 멤버 변수에 접근하는 코드는 다음과 같이 된다. 
```
	x = a;	// this->x = a;
	y = b;	// this->y = b;
```
>- `static` 멤버 함수 `foo`는 컴파일 될 때 `this`가 추가되지 않는다.<br>
그래서 멤버 변수에 접근할 수 없다. 
>- 함수가 호출되는 `p1.set( 10, 20);` 은 컴파일하면 다음과 같이 된다. 
```
    p1.set( 10, 20 );   // 컴파일하면  set( &p1, 10, 20 ) 으로 바뀐다…
						// push    20
						// push    10
						// mov     ecx, &p1  // <- 객체 주소는 레지스터로 전달
						// call    ?set@@xx….
```

- 멤버 함수 포인터 이야기..
	- 일반 함수 포인터에 멤버 함수의 주소를 담을 수 없다.
	- 일반 함수 포인터에 `static` 멤버 함수의 주소를 담을 수 있다.
	- 멤버 함수 포인터 만드는 법과 사용하는 법.
```
	void( Dialog::*f )( ) = &Dialog::Close:
	Dialog dlg;
	(dlg.*f)( );  // dlg.close() 와 같다.
```
- 다음 코드를 보자.
```
	// file : MemberFunctionPointer02.cpp
	#include <iostream>
    using namespace std;

	class Dialog
	{
	public :
    	void Close( )
 		{
			cout << “Close dialog..” << endl;
		}
    	static void Close2( )
		{
			cout << “Close dialog 2” << endl;
		}
	};

	void foo( )
	{
    	cout << “foo” << endl;
	}

    int main( )
    {
        void( *f1 )( ) = &foo;
        void( *f2 )( ) = &Dialog::Close;   // 될까 ?? error !! 
        void( *f3 )( ) = &Dialog::Close2;
    }
```
>- `f1`은 ok, `f2`는 error, `f3`는 ok
>- `Dialog::Close`는 컴파일 될 때 `this` 가 추가된다, 따라서 `f2`는 signature가 달라서 안된다.
>>- compile error를 보면 사용법을 유추할 수 있다.<br>
`error: cannot convert ‘void (Dialog::*)()’ to ‘void(*)()’ in initialization`
>>- `Dialog::*` 를 이용하자.

- 다음 코드를 보자. ( MemeberFunctionPointer02.cpp에서 수정 )
```
	// file : MemberFunctionPointer03.cpp
	#include <iostream>
    using namespace std;

	class Dialog
	{
	public :
    	void Close( )
 		{
			cout << “Close dialog..” << endl;
		}

    	static void Close2( )
		{
			cout << “Close dialog 2” << endl;
		}
	};

	void foo( )
	{
    	cout << “foo” << endl;
	}

    int main( )
    {
        void( *f1 )( ) = &foo;
        void( Dialog::*f2 )( ) = &Dialog::Close;

        Dialog dlg;
        ( dlg.*f2 )( );
    }
```
>- 멤버 함수의 포인터를 지정하는 방법은 `< classtype T > T::*` 를 이용하자.
>- C++ 에서 새로 나온 연산자 `.*` 를 이용하여 함수 포인터를 호출한다.<br>
> `( dlg.*f2 )( ); // ==dlg.Close( );`

- C의 멀티스레드 개념을 C+ + 클래스로 wrapping 해보자.<br>
대부분의 C++ 라이브러리에서 사용하고 있다. ( Android도. )
- 다음은 전통적인 `thread` 생성 코드이다.
```
	// file : MemberFunctionPointer04.cpp
	#include <iostream>
	#include <pthread.h>
    using namespace std;

    void* thread_loop( void* arg )
    {
        cout << “thread_loop” << endl;
    }

    int main( )
    {
        pthread_t thread;
        int status;

        pthread_create( &thread, NULL, &thread_loop, (void *) 10 );
        cout << “main loop” << endl;
        cin >> status;
    }
```
- `thread`를 접해봤으니 다음 코드를 보자.
```
	// file : MemberFunctionPointer05.cpp
	#include <iostream>
    #include <pthread.h>
	using namespace std;
    
    //// for library provider
    class Thread
    {
    public :
        void run( void ) {
            pthread_t thread;
            pthread_create( &thread, 0, _ThreadLoop, this ); // < --- (1)
        }

        static void* _ThreadLoop( void* p ) {                 // < --- (2)
            Thread* const self = static_cast< Thread* >( p ); // < --- (3)
            self->ThreadLoop( );
            return 0;
        }

        virtual bool ThreadLoop( ) {
            return false;
        }
    };

    //// for library user
    class MyThread : public Thread
    {
    public :
        virtual bool ThreadLoop( )
        {
            for( int i=0; i< 10; i++ ) {
                cout << “MyThread : “ << i << endl;
                sleep( 1 );
            }
            return true;
        }
    };

    int main( )
    {
        int status;
        MyThread t;

        t.run( );

        cin >> status;
        return 0;
    }
```
>- 중요한 것들.
>- (1) 컴파일 할 때 `run` 함수 안에 `this`가 전달되므로, C 함수의 인자로 `this`를 넘긴다.
>- (2) 왜 이 함수는 `static` 함수이어야 하나 ??? 꼭 `static` 함수일 수 밖에 없는 이유를 알자.<br>
> `pthread_creat`e 함수는 c library 함수이다. 이 함수에서 멤버함수를 호출할 방법이 없다.<br>
> 따라서 `static` 함수로 선언하고 전달 받은 파라미터( `this` )를 `Thread` 객체로 casting 하여<br>
> 멤버 가상 함수인 `ThreadLoop`을 호출한다.
>- (3) type casting은 후에 자세히 살펴보자.. 지금은 이렇게 할 수 있다 정도만…

<p>
___
<p>
### 상수함수
1. 모든 멤버를 상수 취급하는 함수
2. 상수 객체는 상수 멤버 함수만 호출 가능.
3. 멤버의 값을 변경하지 않는 모든 함수는 반드시 상수 함수로 해야 한다.<br>
무슨 얘기냐면,,,
```
    void foo( const Rect& r )
    {
		r.xxx( );	// r은 상수이므로 상수 함수만 호출 가능..
					// xxx 함수 내에서 멤버의 값을 변경하는 게 있으면 안된다는 뜻.
    }
```
- 다음 코드를 보자.
```
    // file : ConstFunction01.cpp
	#include <iostream>
    using namespace std;

    class Point
    {
    public :
        Point( int a = 0, int b = 0 )
        	: x(a), y(b)
        {
        }
        void Set( int a, int b )
		{
            x = a;
            y = b;
        }
        void Print( void )
        {
            cout << “x = “ << x << “, y = “ << y << endl;
            x = 10; // error !!! 상수 함수 안에서는 멤버 data 값을 변경할 수 억다.
        }

    public :
        int x;
        int y;
    };

    int main( )
    {
		const Point p1( 1, 2 );	// const로 생성하면
		p1.x = 10;				// error !!!
		p1.Set( 10, 20 );		// error !!!
		p1.Print( );			// error !!!
    }
```
>- `p1`이 `const` 한정자를 이용하여 생성되었으므로, 모든 함수에 접근이 불가능하다.
>- 멤버의 값을 바꾸지 않는 함수 `Point::Print`는 `const` 키워드를 이용하여 접근 가능하게 한다… <br>
> 보기만 하는 건 허락해야 하지 않을까 ??<br>
> 다음과 같이 변경한다.
```
	void Print( void ) const
```
- 혹시 `const`에 대해서 잘 모르면,, 다음을 구분해보자..
````
    char* p1 = “Hello, world”;  // 비상수 데이터, 비상수 포인터
    const char* p2 = “Hello, world”; // 상수 데이터, 비상수 보인터
    char* const p3 = “Hello, world”;  // 비상수 데이터, 상수 포인터
    const char* const p4 = “Hello, world”; // 비상수 데이터, 비상수 포인터
````
>- `p1`이 가리키는 address, 그 address에 있는 데이터인 `“Hello, world”`도 바뀔 수 있다.
>- `p2`가 가리키는 address는 바뀔 수 있다, 그 address에 있는 데이터는 바뀔 수 없다.
>- `p3`가 가리키는 address는 바뀔 수 없다, 그 address에 있는 데이터는 바뀔 수 있다.
>- `p4`가 가리키는 address, 그 address에 있는 데이터 모두 바뀔 수 없다.

- 다음 코드를 보자.
```
    // file : ConstFunction02.cpp
    class Rect
    {
    public :
        int GetArea( )
		{
            return w * h;
        }

    private :
        int x, y, z, w;
    };

    void foo ( const Rect& r )  // call by value에 의한 메모리 낭비를 막기 위한 테크닉
    {
        int n = r.GetArea( )  // ???  GerArea는 상수 함수이어야 한다.
    };

    int main( )
    {
        Rect r; // 초기화 했다 치고…
        int n = r.GetArea( );  // 함수 직접 사용.
        foo( r ); // r을 const 파라미터로 foo에 전달
    }
```
>- 메모리 낭비를 막기 위한 call by reference에 의한 함수 파라미터 전달 
>- `foo` 내부의 `r`은 상수이다. 즉 `r`의 멤버 중 상수 함수만 접근 가능
>- `getArea`의 선언에 `const` 가 추가되어야 한다.
```
	int GetArea( ) const { return w*h; }
```
- 다음은 논리적 상수형 문제
	- 해결책 1 : `mutable`
	- 해결책 2.: 변하지 않는 것과 변하는 것은 분리되어야 한다.<br>
                상수 함수 안에서 변경하고 싶은 멤버가 있다면 클래스 외주에 뽑아서..
- 무슨 소리 냐면 ?? 다음 코드를 보자..
```
    // file : ConstFunction03.cpp
	#include <iostream>
    using namespace std;

    class Point
    {
    public :
        Point( int a = 0, int b = 0 )
            : x( a ), y( b ), cache_valid( false )
        {
        }

        const char* toString( ) const
		{
            if( cache_valid == false ) {
                sprintf( cache, “$d, $d”, x, y );
                cache_valid = true;
            }
            return cache;
        }

    private :
        int x, y;
        char cache[32];
        bool cache_valid;
    };

    int main( )
    {
        Point p( 1, 2 );
        cout << p.toString( ) << endl;
    }
```
>- `toString()` 은 객체를 문자열로 변환해 주는 함수
>- Java, C#의 모든 클래스에는 `toString()`함수가 이미 있음.
>- 함수 선언에 `const`를 해주었기 때문에, 멤버 변수인 `cache`에 데이터를 바꾸려 할 때 오류가 발생한다.

- `mutable`을 사용하는 해결책… ( ConstFunction03.cpp에서 수정 )
```
    // file : ConstFunction04.cpp
	#include <iostream>
    #include <cstdio>
    using namespace std;

    class Point
    {
    public :
        Point( int a = 0, int b = 0 )
            : x( a ), y( b ), cache_valid( false )
        {
        }

        const char* toString( ) const
     	{
            if( cache_valid == false ) {
                sprintf( cache, “$d, $d”, x, y );
                cache_valid = true;
            }
            return cache;
        }

    private :
        int x, y;
        mutable char cache[32];     // mutable …
        mutable bool cache_valid;   // mutable …
    };

    int main( )
    {
        Point p1( 1, 2 );
        cout << p.toString( ) << endl;
    }
```
>- 상수 함수 안에서도 변경할 수 있는 멤버 변수를 만들 때 `mutable` 선언

- 또 다른 해결책은.. 변하는 부분과 변하지 않는 부분을 분리하는 것…<br>
다음 코드를 보자.
```
    // file : ConstFunction05.cpp
	#include <iostream>
    #include <cstdio>
    using namespace std;

    struct Cache
    {
        char data[ 32 ];
        bool valid;
    };

    class Point
    {
    public :
        Point( int a = 0, int b = 0 )
            : x( a ), y( b )
        {
            pCache = new Cache;
            pCache->valid = false;
        }

        ~Point( )
        {
             delete pCache;
        }

        const char* toString( ) const
     	{
            if( pCache->valid == false ) {
                sprintf( pCache->data, “$d, $d”, x, y );
                pCache->valid = true;
            }
            return pCache->data;
        }

        void Set( int a, int b )
        {
            x = a;
            y = b;
            pCache->valid = false;
        }

    private :
        int x, y;
        Cache* pCache;
    };

    int main( )
    {
        Point p1( 1, 2 );
        cout << p.toString( ) << endl;

        p.Set( 10, 20 );
    	cout << p.toString( ) << endl;
    }
```
>- 상수 함수인 `toString( )` 내부에서 변화가 발생하는 변수를 별도의 클래스로 뽑자.
>>- `cache`와 `cache_valid` 두 변수를 다른 클래스인 `Cache`로 구조화했다.
>
>- `Point` 클래스의 인스턴트가 만들어질 때 `Cache`를 하나 할당하고, 삭제될 때 할당된 `Cache`를 지우도록 한다.
>- `Point`가 가리키는 `Cache`는 변함이 없고,, `Cache` 내부의 값은 변화가 발생하게 하여 문제를 해결한다.


<p>
___
<p>
### 복사생성자
1. 말 그대로 복사를 하는 생성자이다..
- 다음 코드를 보자…
```
    // file : CopyConstructor01.cpp
    #include <iostream>
    using namespace std;

    class Point
    {
    public :
        Point( ) // 1st constructor
            : x( 0 ), y( 0 )
        {
        }

        Point( int a, int b )  // 2nd constructor
            : x( a ), y ( b )
        {
        }

        // 사용자가 만들지 않으면, Compiler가 아래 모양의 복사 생성자를 제공한다.
        // 기본적으로 모든 멤버 변수의 값을 대입해준다.
        Point( const Point& r )  // 3rd constructor == copy constructor
            : x( r.x ), y( r.y )
        {
        }

    public :
        int x, y; // 출력을 위해 public으로 선언
    };

    int main( )
    {
        Point p1;    // 1st constructor
        Point p2( 1, 2 );  // 2nd constructor
        Point p3( p2 );  // 3rd constructor == copy constructor

        cout << p3.x << “ : “ << p3.y << endl;
    }
```
>- 세 번째 생성자가 기본적인 복사 생성자이며 사용자가 선언하지 않으면 컴파일러에 의해 자동적으로 제공되며 모든 멤버 변수 값을 lvalue 의 값으로 대입한다.

- 이제 중요한 이야기를 할 건데,,, 반드시 알아야 하는 내용이다.
- 바로 객체의 얕은 복사 이야기인데.. ( shallow copy <----> deep copy )
	1.  임의의 클래스가 내부적으로 포인터 멤버가 있다면, 디폴트 복사 생성자는 얕은 복사 문제가 있다.
	2. 사용자가 복사 생성자를 제공해서 해결해야 한다.
	3. 해결책은 4가지 정도가 된다.
		- 깊은 복사 ( deep copy ) – 가장 널리 알려짐.. 별로 좋지 않음.
		- 참조 계수 ( reference count ) – 가장 많이 사용.. 가장 좋음.
		- 소유권 이전 ( ownership transfer ) – 잘 쓰이진 않지만 swap 등에 좋음. 
		- 복사 금지 ( copy prohibit ) 

- 다음 코드를 보자. 깊은 복사의 경우이다. 
```
    // file : CopyConstructor02.cpp
    #include <iostream>
    #include <cstring>
    using namespace std;

    class Cat
    {
    public :
        Cat( const char* n, int a ) // 1st constructor
            : age( a )
        {
            name = new char[ strlen( n ) ];
            strcpy( name, n );
        }

        // Deep copy
        Cat( const Cat& r )  // copy constructor
            : age( r.age ) // 포인터가 아닌 경우는 그냥 복사.
        {
            name = new char[ strlen( r.name ) ];  // 포인터는 메모리 할당 후
            strcpy( name, r.name );   // 메모리 통째로 복사
        }

        ~Cat( )
        {
            delete [] name;  // 소멸자에서 메모리 삭제.. 어디선가는 해주어야 한다…
        }

    public :
        char* name;
    	int age;
    };

    int main( )
    {
    	Cat c1( “neo”, 2 );
        Cat c2( c1 );  // copy constructor

        cout << c2.name << endl;
    }
```
>- 얕은 복사를 하면 runtime에 segmentation fault가 발생한다.
>>- `c1`이 제거될 때 `name` 지우고, `c2`가 제거될 때 `name`을 또 지우려 하기 때문이다.

>- 포인터가 아닌 변수는 그대로 복사하고
>- 포인터 변수는 메모리 할당 후 메모리 전체를 lvalue로부터 복사한다.
>- 어디선가 할당된 메모리를 없애야 한다..소멸자를 참조하자.

- 다음 코드를 보자.. 참조 계수를 사용하는 방법이다…( CopyConstructor 02.cpp에서 수정 )
```
    // file : CopyConstructor03.cpp
    #include <iostream>
    #include <cstring>
    using namespace std;

    class Cat
    {
    public :
        Cat( const char* n, int a )
            : age( a )
        {
            name = new char[ strlen( n ) ];
            strcpy( name, n );
            ref = 1;
        }

    	Cat( const Cat& r )  // copy constructor
            : name( r.name ), age( r.age )
        {
            ++ref;
    	}

        ~Cat( )
        {
            if( --ref == 0 ) {
                delete [] name;
            }
        }

    public :
        char* name;
    	int age;
    	static int ref; // reference count
    };

    int Cat::ref = 0; // static 멤버 변수 초기화는 클래스 선언 외부에서 한다.

    int main( )
    {
        Cat c1( “neo”, 2 );
        Cat c2( c1 );
        Cat c3( c2 );

        cout << c3.name << endl;
     	cout << c2.name << endl;
    }
```
>- 참조 계수로 전역변수 `ref`를 선언하고 
>- 복사 생성자가 호출될 때 마다 `ref`를 증가시킨다. 
>- 복사될 때 `name`이 가리키는 포인터의 위치는 항상 동일하다..
>- 소멸자에서 참조 계수 값을 확인하고 이 값이 `0`이 되면 메모리를 제거한다.
>- 이 코드의 치명적인 문제점은 ???
>>- 참조 계수로 `static` 변수를 사용하면 안된다.
>>- 전혀 다른 객체가 이 값을 참조할 수 있기 때문이다..
>>- heap 영역에 참조 계수를 써야한다.

- 	다음 코드를 보자…
```
    // file : CopyConstructor04.cpp
	#include <iostream>
    #include <cstring>
    using namespace std;

    class Cat
    {
    public :
        Cat( const char* n, int a )
            : age( a )
        {
            name = new char[ strlen( n ) ];
            strcpy( name, n );
            ref = 1;
        }

    	Cat( const Cat& r )  // copy constructor
            : age( r.age ), name( r.name )
        {
            ++ref;
    	}

        ~Cat( )
        {
            if( --ref == 0 ) {
                delete [] name;
            }
        }

    public :
        char* name;
    	int age;
    	static int ref; // reference count
    };

    int Cat::ref = 0; // static 멤버 변수 초기화는 클래스 선언 외부에서 한다.

    int main( )
    {
        Cat c1( “neo”, 2 );
        Cat c2( c1 );
        Cat c3( c2 );
        Cat c4( “bella”, 1 );
        Cat c5( c4 );

        cout << c5.name << endl;
        cout << c4.name << endl;
    	cout << c3.name << endl;
    	cout << c2.name << endl;
    }
```
>- 위 코드에서 실제 메모리가 지워지는 횟수는 ????
>>- `1`회이다..
>>- `c4`를 만들 때 `ref`가 다시 1로 설정되기 때문이다.

>- 참조 계수를 `static` 변수로 만들면 메모리 누수가 발생할 수 있다.

- 다음 코드를 보자. 
```
    // file : CopyConstructor05.cpp
	#include <iostream>
    #include <cstring>
    using namespace std;

    class Cat
    {
    public :
        Cat( const char* n, int a )
            : age( a )
        {
            name = new char[ strlen( n ) ];
            strcpy( name, n );
            ref = new int( 1 ) // 1로 초기화한다. [ ] 가 아니라 ( ) 이다.
        }

    	Cat( const Cat& r )  // copy constructor
            : age( r.age ), name( r.name ), ref( r.ref ) // ref가 가리키는 곳을 같이 가리키고
        {
            ++(*ref); // 값을 증가시킨다..
    	}

        ~Cat( )
        {
            if( --(*ref) == 0 ) {
                delete [] name;
                delete ref;
            }
        }

    public :
        char* name;
    	int age;
    	int* ref; // reference count
    };

    int main( )
    {
        Cat c1( “neo”, 2 );
        Cat c2( c1 );
        Cat c3( “bella”, 1 );
        Cat c4( c3 );

        cout << c4.name << endl;
     	cout << c2.name << endl;
    }
```
>- heap에 참조 계수를 선언하고,
>- 객체가 복사될 때 같은 참조 계수를 가리키도록 만든 다음에
>- 그 값을 증가시키고
>- 소멸자가 호출 될 때 참조 값을 감소 시킨 뒤에 더 이상 참조가 안되면 메모리 제거한다.
>- 이 코드의 문제점은 무엇일까 ??
>>- COW( Copy on Write )를 고려해야 한다.
>>- `Cat`이 복사된 뒤에 이름을 바꾼다면 ???
>>- 이 내용은 복잡하니까 심화 과정에서 배우자…

- 다음 코드를 보자.. 소유권 이전이다.
```
    // file : CopyConstructor06.cpp
	#include <iostream>
    #include <cstring>
    using namespace std;

    class Cat
    {
    public :
        Cat( const char* n, int a )
            : age( a )
        {
            name = new char[ strlen( n ) ];
            strcpy( name, n );
    	}

    	Cat( Cat& r )  // move constructor. const 가 없다.!!!
            : age( r.age ), name( r.name )
    	{
            r.age = 0;
    	r.name = 0;
    	}

        ~Cat( )
        {
    		delete [] name;
        }

    public :
        char* name;
    	int age;
    };

    int main( )
    {
        Cat c1( “neo”, 2 );
        Cat c2( c1 );

        cout << c2.name << endl;
     	cout << c1.name << endl;
    }
```
>- 자원의 복사가 아니라 자원을 전달(Move)했다.
>- c+ + 2.0 에서는 이러한 기술을 move 생성자라 한다.
>>- 파고들어가야 할 내용은… 이동 생성자, 그리고 이동 할당 연산자.
>>- 이동 생성자에서는 rvalue 참조 선언자 `&&` 가 나온다..
>>>- lvalue ?? rvalue ??
>>>>- lvalue는 단일 식을 넘어 지속되는 개체를 참조한다. lvalue는 이름이 있는 개체로 생각하면 됨. <br>
>>>> `const` 변수를 포함한 모든 변수가 lvalue임
>>>>- rvalue는 rvalue를 사용하는 식 외에서는 유지되지 않는 임시 값을 나타냄.

>> 자세한 건 고급과정에서…

>- `swap` 할 때 `tmp` 만드는 대신 쓰면 유용할 수 있다. ????
>- c+ +의 `auto_ptr` 이 이 기술을 쓰고 있다.
>- 복사 생성자에 `const` 키워드가 없음을 주의하자.
>- 복사 될 때 lvalue에 있는 값이 복사되는 객체로 초기화에 쓰이고 
>- lvalue의 값은 `0`로 바뀐다.

-	다음 코드를 보자…복사 금지 방법이다. ( 종교적인 이유로도.. Cat을 복사하면 안되다~!! )
```
    // file : CopyConstructor07.cpp
	#include <iostream>
    #include <cstring>
    using namespace std;

    class Cat
    {
    public :
        Cat( const char* n, int a )
            : age( a )
        {
            name = new char[ strlen( n ) ];
            strcpy( name, n );
    	}

        ~Cat( )
        {
    		delete [] name;
        }

    public :
    	char* name;
    	int age;

    private :
        Cat( const Cat& c );
        void operator=( const Cat& );
    };

    int main( )
    {
        Cat c1( “neo”, 2 );
        Cat c2( c1 );

        cout << c2.name << endl;
     	cout << c1.name << endl;
    }
```
>- 복사 생성자를 `private` 속성으로 선언만 한다.
>>- 복사 생성자의 구현을 작성하면 class내부의 함수에서 복사 생성자를 활용할 수 있게 된다.
>>- 즉, 선언만 해라.

>- 복사가 금지되면 보통 대입도 금지된다.( `operator=` 참조할 것)
>>- c+ + 2.0에서는 복사 금지가 문법화 되었다. `delete` function으로 문법이다.
```
	Cat( const Cat& c ) = delete;
	void operator=( const Cat& c) = delete;
```

-	복사 금지 기술을 매크로화 하자.
```
    // file : CopyConstructor08.cpp

	#ifdef SUPPORT_CPP0X
	#define  MAKE_NON_COPYABLE(classname)                        \
		private : classname( const classname& ) = delete;        \
				  void operator=( const classname& ) = delete;
	#else /* SUPPORT_CPP0X */
	#define  MAKE_NON_COPYABLE(classname)                        \
		private : classname( const classname& );                 \
				  void operator=( const classname& ); 
	#endif /* SUPPORT_CPP0X else */

    class Cursor
    {
        MAKE_NON_COPYALBE( Cursor )
    };
```
>- 클래스 선언부에 매크로 적용. 끝~!.


<p>
___
<p>
### 싱글톤
1. 오직 한 개의 객체만 만들 수 있는 디자인 기술
2. GoF의 Design Pattern에도 소개되어 있다.
3. Effective C++의 저자인 Scott Meyer가 처음 만들어서 Meyer의 싱글톤 이라고도 한다.
-	다음 코드를 보자.
```
    // file : Singleton01.cpp

    class Cursor
    {
    private :
        Cursor( )    // 규칙 1. private 생성자
        {
        }

        Cursor( const Cursor& c );            // 규칙 3. 복사와 대입 금지
        void operator=( const Cursor& c );

    public :
        static Cursor& GetInstance( )    // 규칙 2. 오직 한 개의 객체만 만들어 리턴하는 멤버 함수
        {                                //         static 함수로 선언해야 한다…
            static Cursor instance;
            return instance;
        }
    };

    int main( )
    {
    	Cursor& c1 = Cursor::GetInstance( );
    	Cursor& c2 = Cursor::GetInstance( );
    }
```
>- 규칙 1 : private한 생성자를 선언해야 한다. 다른 곳에서 instance를 생성하지 못하도록.
>- 규칙 2 : 오직 한 개의 객체만을 만들어서 리턴하는 멤버 함수를 제공해야 하며, 그 함수는 static 함수로 선언해야 한다.
>- 규칙 3 : 복사와 대입을 금지해야 한다.<br>
`Cursor c = Cursor::GetInstance( ); //  대입이 안되기 때문에 에러.`

- 다음 코드를 보자.. Heap 영역에 singleton을 만드는 방법이다...( SIngleton01.cpp 파일을 수정한다. )
```
    // file : Singleton02.cpp
	#include <iostream>
    using namespace std;

    class Mutex
    {
    public :
        void Lock( )
        {
            cout << “Mutex lock” << endl;
        }

        void Unlock( )
        {
            cout << “Mutex unlock” << endl;
        }
    };

    class Cursor
    {
    private :
        Cursor( )
        {
            cout << “Cursor created” << endl;
        }

        Cursor( const Cursor& c );
        void operator=( const Cursor& c );

        static Cursor* pInstance;
        static Mutex sLock;

        int a;
        int b;
        double d;

    public :
        static Cursor& GetInstance( )
        {
            sLock.Lock( );

            if( pInstance == 0 )
                pInstance = new Cursor( );

            sLock.Unlock( );

            return *pInstance;
        }

        ~Cursor( )
        {
            cout << “delete cursor” << endl;
        }
    };

    // 모든 static 멤버 데이터는 반드시 클래스 외부 선언이 있어야 한다.
    Cursor* Cursor::pInstance = NULL;
    Mutex Cursor::sLock;

    int main( )
    {
        void foo( Cursor& cursor );

        Cursor& c1 = Cursor::GetInstance( );
        Cursor& c2 = Cursor::GetInstance( );

        cout << “&c1 = “ << &c1 << endl;   // 0x12345678
        cout << “&c2 = “ << &c2 << endl;   // 0x12345678

        Cursor* p = &c1;

        cout << “sizeof c1 = “ << sizeof c1 << endl;    // 16
        cout << “sizeof p = “ << sizeof p << endl;      // 8

        foo( *p );
    }

    void foo( Cursor& cursor )
    {
        cout << “&cursor = “ << &cursor << endl; // 0x12345678
    }
```
>- Heap 영역에 Singleton을 만들기 위해 `pInstance`를 `static`한 포인터 타입으로 선언한다.
>- 동시에 여러 곳에서 `GetInstance( )` 가 호출될 때, context switching에 의해 두 번 이상 메모리가 할당되는 것을 방지하기 위해 `Lock`을 사용한다. 이것이 Synchronization 이다.
>- 여기서 문제가 되는 것은 ????
>- 만일, `Lock( )`과 `UnLock( )` 사이에서 exception이 발생하면, `catch`로 뛰어넘게 되어 unlock할 방법이 없다. deadlock을 발생시키게 된다..
>- 어떻게 하면 좋을까 ???? 바로 자원 관리 객체, RAII 기술을 사용한다.

- 다음 코드를 보자… ( Singleton02.cpp 파일에서 수정한다. )
```
    // file : Singleton03.cpp
    #include <iostream>
    using namespace std;
    class Mutex
    {
    public :
        Lock( )
        {
            cout << “Mutex lock” << endl;
        }

        Unlock( )
        {
            cout << “Mutex unlock” << endl;
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
        }
    };

    class Cursor
    {
    private :
        Cursor( )
        {
            cout << “Cursor created” << endl;
        }

        Cursor( const Cursor& c );
        void operator=( const Cursor& c );

        static Cursor* pInstance;
        static Mutex sLock;

        int a;
        int b;
        double d;

    public :
        static Cursor& GetInstance( )
        {
            Mutex::Autolock autolock( sLock );

            if( pInstance == 0 )
                pInstance = new Cursor( );

            return *pInstance;
        }

        ~Cursor( )
        {
            cout << “delete cursor” << endl;
        }
    };

    // 모든 static 멤버 데이터는 반드시 클래스 외부 선언이 있어야 한다.
    Cursor* Cursor::pInstance = NULL;
    Mutex Cursor::sLock;

    int main( )
    {
        void foo( Cursor& cursor );

        Cursor& c1 = Cursor::GetInstance( );
        Cursor& c2 = Cursor::GetInstance( );

        cout << “&c1 = “ << &c1 << endl;   // 0x12345678
        cout << “&c2 = “ << &c2 << endl;   // 0x12345678

        Cursor* p = &c1;

        cout << “sizeof c1 = “ << sizeof c1 << endl;    // 16
        cout << “sizeof p = “ << sizeof p << endl;      // 8

        foo( *p );
    }

    void foo( Cursor& cursor )
    {
        cout << “&cursor = “ << &cursor << endl; // 0x12345678
    }
```
>- 동기화 자원을 사용할 때는 그냥 사용하지 말고 자원 관리 객체를 사용하자.
>- RAII( Resource Acquisition In Initialization ) 기술이다.
>- 예외 발생 시, 해당 함수의 지역변수는 안전하게 파괴되면서 소멸자가 호출되는 것을 보장한다.
>- Singleton 자원 해지에 관한 좋은 서적은 Modern C+ + Design이다.

- 다음 코드를 보자. ( Singleton03.cpp 파일에서 수정한다. )<br>
많은 singleton을 만들어야 할 때, `template`을 사용하며, 자신의 클래스 이름을 전달하는 방법이다.
```
    // file : Singleton04.cpp
	#include <iostream>
    using namespace std;

    class Mutex
    {
    public :
        Lock( )
        {
            cout << “Mutex lock” << endl;
        }

        Unlock( )
        {
            cout << “Mutex unlock” << endl;
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
        }
    };

    template< typename T >
    class Singleton
    {
    protected :
        Singleton( )
        {
            cout << “Singleton created.” << endl;
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

            if( pInstance == NULL )
                pInstance = new T( );

            return *pInstance;
        }
    };

    // 모든 static 멤버 데이터는 반드시 클래스 외부 선언이 있어야 한다.
    template<typnname T>
    T* Singleton<T>::pInstance = NULL;
    template<typename T>
    Mutex Singleton<T>::sLock;

    class DoorService : public Singleton< DoorService >
    {
    };

    class CateringService : public Singleton< CateringService >
    {
    };

    int main( )
    {
        DoorService& d1 = DoorService::GetInstance( );
        CateringService& c1 = CateringService::GetInstance( );
    }
```
>- 다수의 Singleton을 만들 때 code 생성기인 `template`을 이용하는 방법이다..
>- 상속을 해주는 부모 클래스는 `template`으로 만든다.
>- 자신의 클래스 이름을 부모 클래스 `template`으로 전달한다.
>- 원래는 이런 모양으로 코드를 만들었을 것이다..
```
    class DoorService
    {
    	// ..
    };
    int main ( )
    {
        DoorService& door = Singleton< DoorService >::GetInstance( );
    }
```
