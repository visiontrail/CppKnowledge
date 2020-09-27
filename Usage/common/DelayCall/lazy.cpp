#include "Optional.hpp"
#include <memory>
#include <functional>


template <typename T>
struct Lazy
{
    Lazy(){};
    // 保存需要延迟执行的函数
    template <typename Func, typename... Args>
    Lazy(Func &f, Args &&... args)
    { 
        // 给出需要调用的函数和参数，封装起来。等待之后被调用
        m_func = [&f, &args...] { return f(args...); };
    }
    // 延迟执行，将结果放到optional中缓存起来，下次不用重新计算可以直接得到结果
    T &Value()
    {
        if (!m_value.IsInit())
        {
            m_value = m_func();
        }
        return *m_value;
    }

    bool IsValueCreated() const
    {
        return m_value.IsInit();
    }

private:
    std::function<T()> m_func; // 返回值类型为T的无参可调用对象 m_func
    Optional<T> m_value;
};

// 定义一个模板函数，返回值类型为 Lazy
template <class Func, typename... Args>
Lazy<typename std::result_of<Func(Args...)>::type> lazy(Func &&fun, Args &&... args)
{
    return Lazy<typename std::result_of<Func(Args...)>::type>(std::forward<Func>(fun), std::forward<Args>(args)...);
}

struct BigObject
{
    BigObject()
    {
        cout << "lazy load big object" << endl;
    }
};

struct MyStruct
{
    MyStruct()
    {
        m_obj = lazy([] { return std::make_shared<BigObject>(); });
    }
    void Load()
    {
        m_obj.Value();
    }
    Lazy<std::shared_ptr<BigObject>> m_obj;
};

int Foo(int x)
{
    return x * 2;
}

void TestLazy()
{

    // 带参数的普通函数
    int y = 4;
    auto lazyer1 = lazy(Foo, y);
    cout << lazyer1.Value() << endl;

    // 不带参数的lambda
    Lazy<int> lazyer2 = lazy([] { return 12; });
    cout << lazyer2.Value() << endl;

    // 带参数的function
    std::function<int(int)> f = [](int x) { return x + 3; };
    auto lazyer3 = lazy(f, 3);
    cout << lazyer3.Value() << endl;

    // 延迟加载大对象
    MyStruct t;
    t.Load();
}

int main()
{
    TestLazy();
    return 0;
}