# module

`c++20`에서 추가된 기능이다. Program을 여러 부분으로 구성하기 위해 사용되며, `#include`와 혼용하여 사용할 수 있다.

`#include`는 포함 순서에 영향을 크게 받으며, 컴파일러가 매번 처리해야하여 에러의 가능성이 높고, 그에 따른 비용도 크다.

`module`은 한 번만 compile되며, 두 module을 import하는 순서가 code의 의미에 영향을 주지 않는다. 또, `import`에는 전이성이 없다.

```cpp
// xxx.cpp
module;		// define module

export module xxx;	// define module "xxx"

export class xxx {
};

export int func(void) {
	std::cout << "Test" << std::endl;
}

// yyy.cpp
import xxx;
```
