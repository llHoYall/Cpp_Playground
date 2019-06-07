# iostream

## Formatter

* `defaultfloat` : 현재 사용할 수 있는 공간에서 주어진 값을 가장 잘 보존하는 style을 구현체가 알아서 선택한다. 이 경우에 정밀도는 최대 자리수를 나타낸다.
* `scientific` : 소수점 앞의 한 자리와 지수로 값을 표현한다. 이 경우에 정밀도는 소수점 다음의 최대 자리수를 말한다.
* `fixed` : 정수부와 소수점, 소수 부분으로 값을 표현한다. 여기서 정밀도는 소수점 다음의 최대 자리수를 말한다.

부동 소수점 값은 버림이 아니라 반올림이 적용되며, `precision()`은 정수 부분의 출력에는 영향을 주지 않는다. 또한, 지속적(sticky)이다. 즉, 뒤에 이어지는 부동 소수점 관련 연산에 영향을 준다.

## C Style Input/Output

C++ standard library는 `printf()`와 `scanf()`를 비롯한 C standard library 입출력도 지원하지만, 대부분의 경우에 이러한 library의 사용은 type과 보안 측면에서 안전하지 않으므로 추천하지 않는다. 특히 안전하고 편리한 입력을 구현하기 어렵고, 사용자 정의 type도 지원하지 않는다.

C style 입출력을 사용하지 않는 상황에서 입출력 성능을 고려해야 한다면 다음 함수를 사용한다.

```cpp
ios_base::sync_with_stdio(false);
```

이 함수를 호출하지 않으면 C style 입출력과 호환성을 유지하기 위해 `iostream`이 매우 느려질 수 있다.
