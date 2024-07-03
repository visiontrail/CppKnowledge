## mutex互斥锁


## condition条件变量

`std::condition_variable` 在 C++ 中和 `pthread_cond_t` 在 C 中起到的作用是类似的。它们都是用于线程间的同步，**尤其是实现线程间的等待和通知机制。**

### 与互斥锁之间的关系
在使用 condition_variable 或 pthread_cond_t 的 notify 或 signal 函数时，通常需要在之前使用互斥锁（mutex）加锁，主要是为了确保条件变量的使用是线程安全的，并避免竞争条件。以下是具体原因：

1. pthread_cond_wait 或 condition_variable::wait机制<br>
由于执行了wait后，对应的一个或多个线程会**释放锁**并处于阻塞状态，

1. 保护共享数据<br>
条件变量通常与共享数据一起使用。互斥锁用于保护对共享数据的访问，确保在条件变量的等待和通知之间没有竞争条件。例如，一个线程可能在检查条件之前被中断，而另一个线程则在修改共享数据。

2. 避免竞争条件<br>
在条件变量等待和通知之间存在一个潜在的竞争窗口。如果不使用互斥锁，可能会导致以下竞争条件：<br>
等待线程可能错过通知：如果一个线程在检查条件后但在进入等待状态之前被中断，而另一个线程在这时发出通知，等待线程将错过这次通知，从而可能永远等待下去。

3. 保证原子性<br>
加锁确保了对条件变量的操作是原子的，即在检查条件和等待之间不会有任何中断。这样可以避免由于竞争条件导致的死锁或数据不一致。


### C\C++当中的条件变量对比
1. **条件变量**：
   - `pthread_cond_t` 在 C 中用于线程间的等待和通知。
   - `std::condition_variable` 在 C++ 中提供了类似的功能，但更类型安全且接口更现代。

2. **等待与通知**：
   - 在 C 中，使用 `pthread_cond_wait` 和 `pthread_cond_signal` 或 `pthread_cond_broadcast`。
   - 在 C++ 中，使用 `std::condition_variable::wait` 和 `std::condition_variable::notify_one` 或 `std::condition_variable::notify_all`。

### 总结
`std::condition_variable` 和 `pthread_cond_t` 在各自的语言中起到相同的作用：协调多个线程的执行顺序，避免竞争条件和资源争用。C++ 提供的 `std::condition_variable` 更加类型安全并且利用了 C++ 的语言特性，例如 RAII 和 lambda 表达式，使得代码更加简洁和安全。


