# Smart Pointer

C++17에서는 `auto_ptr`이 폐기 되었으므로, `unique_ptr`로 사용해야 한다.

## unique_ptr

`unique_ptr`은 빠르고, 효율적이며, 다리키는 객체를 독점한다는 의미의 독점 소유권(exclusive ownership)을 제공한다. 독점 소유권으로 인해 소멸자가 호출될 때, null이 아닌 객체를 가리키고 있다면 객체를 파괴한다. 객체를 독점하므로 복사할 수도 없다. 따라서 복사 생성자와 복사 할당자가 없다. 이동 생성자와 이동 할당자는 제공하므로 이동은 가능하다.

다음과 같이 사용할 수 있다.

```cpp
auto up1 = std::unique_ptr{};
auto up2 = std::unique_ptr{ nullptr };
auto up3 = std::unique_ptr{ new int { 1234 } };
auto up4 = std::make_unique(1234);
```
## shared_ptr

`shared_ptr`은 공유 소유권(shared ownership)을 구현하므로 복사 생성자와 복사 할당자를 제공한다. `unique_ptr`에 참조 횟수가 추가된 것이 `shared_ptr`라고 볼 수 있다. Member 함수 `use_count()`를 호출하면 `shared_ptr`가 참조된 횟수를 알 수 있다. `shared_ptr`를 다른 `shared_ptr` 변수에 복사하면 참조 횟수가 하나 증가하고, `shared_ptr` 객체가 파괴되면 소멸자가 참조 횟수를 하나 감소시킨다. 참조 횟수가 0이되면 객체가 삭제된다.

`shared_ptr`는 논리적으로 관리 대상 객체와 counter 객체의 2개를 가리키기 때문에 무거운 pointer이다. 모든 `shared_ptr`는 기본적으로 강한 참조 횟수와 약한 참조 횟수를 가진다. 강한 참조 횟수는 객체가 삭제되는 것을 방지하는 데 사용하지만, 약한 참조 횟수는 객체의 삭제 여부에 영향을 미치지 않는다.

```cpp
auto sp1 = std::shared_ptr{};
auto sp2 = std::make_shared(1234);
// 실제로 사용할 때는 make_shared를 사용해야 한다. 객체를 저장할 memory 공간과 참조 횟수를 유지하는 데 필요한 공간을 한꺼번에 할당하기 때문에 속도가 훨씬 빠르기 때문이다.
```

## weak_ptr

`weak_ptr`는 `shared_ptr`가 관리하는 객체를 참조하는 데 이때는 약한 참조 횟수가 증가한다. `weak_ptr`의 장점은 가리키는 객체가 유효한 경우만 접근할 수 있기 때문에 강한 참조 횟수가 0이 됐을 때 객체가 삭제되는 걸 막지 않는다.
