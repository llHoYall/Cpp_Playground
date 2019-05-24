# except

예외를 던지지 않는 함수는 다음과 같이 `noexcept`로 선언할 수 있다.

```cpp
void func(int param) noexcept {
	std::cout << "func" << std::endl;
}
```
