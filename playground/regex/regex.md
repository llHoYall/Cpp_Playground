# regex

Pattern을 표현할 때는 보통 다음과 같이 raw 문자열 literal을 사용한다. 정규 표현식은 backslash를 많이 포함하므로 유용하다.

> R"(...)"

## Method

* `regex_match()` : 정규 표현식을 길이를 알고 있는 문자열에 matching한다.
* `regex_search()` : 임의의 길이의 data stream에서 정규 표현식에 matching되는 문자열을 찾는다.
* `regex_replace()` : 임의의 길이의 data stream에서 정규 표현식에 matching되는 문자열을 찾아 교체한다.
* `regex_iterator` : Match와 submatch를 찾아 순회한다.
* `regex_token_iterator` : Match되지 않는 부분을 순회한다.

## Notation

ECMA 표준을 기본 표기법으로 사용한다.

Character | Description
----------|------------
. | 모든 문자 하나
[ | 문자 class 시작
] | 문자 class 끝
{ | counting 시작
} | counting 끝
( | grouping 시작
) | grouping 끝
\ | 다음 문자를 특수 문자로 인식
* | 0번 이상
+ | 1번 이상
? | 0번이나 1번
\| | or
^ | 행의 시작
$ | 행의 끝

반복 표기법은 다음과 같다.

Pattern | Description
--------|------------
{ n } | n번
{ n, } | n번 이상,
{ n, m } | n번 이상, m번 이하
* | { 0, }과 동일
+ | { 1, }과 동일
? | { 0, 1 }과 동일

Pattern matcher는 기본적으로 가장 긴 match를 찾는다. 하지만, `?`를 사용하면 가장 짧은 match를 찾는다.

정규 표현식에서 문자 class 이름은 `[: :]`로 둘러싸야 한다. 그리고 문자 class 정의를 뜻하는 `[ ]` 안에 써야 한다.

Character Class | Description
----------------|------------
alnum | alphabet or number
alpha | alphabet
blank | 행 구분자를 제외한 공백 문자
cntrl | control character
d | 10진 숫자
digit | 10진 숫자
graph | graphic character
lower | 소문자
print | printable character
punct | 문장 부호
s | 공백 문자
space | 공백 문자
upper | 대문자
w | alphabet, number, underscore
xdigit | 16진 숫자

단축 표기법 | Description | Character Class 표기법
------------|-------------|-----------------------
\d | 10진 숫자 | [[:digit:]]
\s | 공백 문자 | [[:space:]]
\w | alphabet, number, underscore | [_[:alnum:]]
\D | \d가 아닌 문자 | [^[:digit]]
\S | \s가 아닌 문자 | [^[:space:]]
\W | \w가 아닌 문자 | [^_[:alnum:]]

언어에서 자체 제공하는 정규 표현식은 다음과 같다.

단축 표기법 | Description | Character Class 표기법
------------|-------------|-----------------------
\l | 소문자 | [[:lower:]]
\u | 대문자 | [[:upper:]]
\L | \l이 아닌 문자 | [^[:lower:]]
\U | \u가 아닌 문자 | [^[:upper:]]
