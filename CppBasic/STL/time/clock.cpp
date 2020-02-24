#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <thread>

/*
 * 编译：gcc clock -o clock.cpp
*/


/*
 * 
*/

using namespace std;

// 函数 f() 做一些耗时工作
void f()
{
    volatile double d = 0;
    for (int n = 0; n < 10000; ++n)
        for (int m = 0; m < 10000; ++m)
            d += d * n * m;
}

int main()
{
    std::clock_t c_start = std::clock();
    auto t_start = std::chrono::high_resolution_clock::now();

    std::thread t1(f);
    std::thread t2(f); // 在二个线程上调用 f()
    std::thread t3(f); // 在三个线程上调用 f()
    t1.join();
    t2.join();
    t3.join();

    std::clock_t c_end = std::clock();
    auto t_end = std::chrono::high_resolution_clock::now();

    std::cout << std::fixed << std::setprecision(2) << "CPU time used: "
              << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms\n"
              << "Wall clock time passed: "
              << std::chrono::duration<double, std::milli>(t_end - t_start).count()
              << " ms\n";
}
