# string

`string_view`는 기본적으로 문자의 sequence를 나타내는 (pointer, length)의 쌍으로 볼 수 있다.

`string_view`를 이용하면 연속적인 문자들의 sequence에 접근할 수 있다. 이때 문자들은 `string`과 C style 문자열을 비롯한 다양한 방법으로 저장될 수 있다. `string_view`가 가리키는 문자들을 직접 소유하지 않는다는 점에서는 pointer나 참조와 비슷하며, STL의 반복자와도 유사하다.

`string_view`의 가장 큰 제약은 문자에 대한 읽기 전용 view만을 제공한다는 것이다. 예를 들어 주어진 인자를 소문자로 변경하는 함수에 `string_view`로 문자를 전달할 수 없다. 그런 용도라면 `gsl::span`이나 `gsl::string_span`을 사용하자.

`string_view`에 대한 구간 밖 접근의 결과는 예측할 수 없다. 구간 검사를 보장하려면 구간 밖 접근 시에 out_of_range 예외를 던지는 `at()`을 사용하거나 `gsl::string_span`을 사용하자.
