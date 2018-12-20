# lambda

Lambda 표현식은 함수의 익명 표기법이다. 특히 함수형 programming에서 lambda 표현식은 first class function과 pure function을 만들 때 유용하다.

Lambda 표현식을 구성하는 3개의 핵심 부분은 다음과 같다.

* Capturing list: `[]`
* Parameter list: `()`
* Body: `{}`

Capturing list는 lambda 표현식 바깥의 변수를 lambda 본문에서 어떻게 접근하는지 나타낸다. 또, lambda 표현식의 시작을 나타내기 때문에 lambda 표현식을 식별하는 용도도 있다. Capturing list에 `&`를 쓰면 바깥 범위에 있는 변수를 참조로 capture하고, `=`을 쓰면 값으로 capture 한다.

Parameter list는 lambda 표현식을 사용할 때 넘겨줄 인수를 나타낸다.

Body는 함수의 실제 구현 부분이다.

## C++17

C++17 부터는 lambda 표현식에 2개의 새로운 기능이 추가되었다.

* Capture list에 `*this`를 사용해 객체의 복사본을 capture할 수 있다.
* Lambda 표현식을 사용해서 `constexpr` 객체를 compile time에 생성할 수 있다.
