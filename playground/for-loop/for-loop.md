# for-loop

기존의 C++은 어떤 sequence를 순회하려면 각 container의 `begin()`, `end()` member 함수를 호출하거나, 배열이라면 index를 사용하였다.

모던 c++에서는 같은 기능을 위해 non-member 함수 `begin()`, `end()` 함수를 사용할 수 있다.

또한, range 기반의 for loop를 사용할 수도 있다. Collection안의 element 개수를 신경쓰지 않고 작업을 하거나, 배열 index의 초과 여부를 걱정하지 않고 작업을 하고 싶을 때 사용한다.
