# alternatives

* `variant`: 지정된 선택지 중 하나를 표현한다. (`#include <variant>`)
* `optional`: 지정된 type의 값이나 값이 없음을 표현한다. (`#include <optional>`)
* `any`: 크기에 제한이 없는 type의 집합 중 하나를 표현한다. (`#include <any>`)

## variant

`variant`는 `union`을 명시적으로 사용하는 것보다 안전하고 간편하다.

## optional

`optional`은 `variant`의 특수한 경우로 볼 수도 있고, 객체를 가리키거나 `nullptr`일 수 있다는 점을 표현한 것으로 볼 수도 있다.

## any

`any`는 임의의 type을 저장할 수 있으며, 그 type을 알고 있다. 기본적으로는 제약을 제거한 `variant`로 볼 수 있다.
