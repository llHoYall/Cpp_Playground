# Concurrency

C++11 이전에는 multi-threading 기술을 이용한 동시성 program을 만들기 위해서 `Boost::thread`를 사용했지만, C++11 이후부터는 `thread` class를 사용한다.

Thread 내에서 공유 객체를 사용하면 동기화(synchronization) 문제가 발생할 수 있다. 이것은 mutex를 사용하여 해결할 수 있다.

Mutex로 변수를 lock한 후 예외상황이 발생하면 unlock되지 않고, program도 동작하지 않게 된다. 이때, `lock_guard<mutex>`를 사용하면 code block을 빠져나갈 때 자동으로 unlock을 하므로 예외가 발생하더라도 문제 없다.

하나의 mutex로 여러 개의 lock_guard를 사용할 경우, 서로 unlock되기를 무한정 기다리는 deadlock이 발생할 수 있다. 이때, `lock_guard<recursive_mutex>`를 사용하여 해결할 수 있다.
