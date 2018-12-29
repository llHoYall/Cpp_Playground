# Meta Programming

Meta programming은 compile time에 code를 생성하는 방법이다. 다시 말하면, code를 사용해서 code를 생성하는 기술이다.

다른 program을 제어하거나 data로 다룰 때 meta programming을 자주 활용한다. 특히 C++ meta programming은 turing-complete하다고 말한다.

Meta programming은 재귀를 많이 사용하고 불변 변수를 사용한다.

Meta programming의 장점은 다음과 같다.

* Template meta programming은 불변성이 있어 기존 type을 수정할 수 없다. 따라서 부작용도 없다.
* Meta programming으로 구현하면 가독성이 더 좋아진다.
* Code 반복을 줄일 수 있다.
* Compiler는 생성된 code에 inline을 적용하여 성능을 높일 수 있다.

단점은 다음과 같다.

* 구문이 복잡해질 수 있다.
* Compile time에 code를 실행하기 때문에 compile time이 길어진다.
* Template을 사용한 code는 debugging이 어렵다. Compile 시에 template에 기반한 code가 생성되므로 debugger가 runtime에 code를 찾기가 힘들다.

## Template Meta Programming

Template meta programming은 type, value, 조건, 재귀의 4가지 기본 요소로 구성된다.

Template meta programming은 가변 변수가 없으므로 초기화된 변수의 값을 바꿀 수 없다.
