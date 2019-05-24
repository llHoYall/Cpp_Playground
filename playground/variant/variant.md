# variant

표준 library인 `variant`는 대부분의 상황에서 `union`을 대체할 수 있다. 많은 경우에 `variant`를 사용하는 것이 더 간단하고 안전하다.

`variant`는 `union`과 같이 여러 type의 값 중 하나를 제공한다. 예를 들면 `variant<int, dounle>`은 int나 double을 저장할 수 있다.
