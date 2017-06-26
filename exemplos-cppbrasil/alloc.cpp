#include <cstdint>
#include <iostream>
#include <memory>
#include <cassert>

using namespace std;

template<typename T>
class line
{
    size_t _size;
    T *_data;

public:
    line(size_t sz) :
        _size(sz),
        _data(reinterpret_cast<T*>(&this->_data)) {}

    ~line()
    {
        _size = 0;
        _data = nullptr;
    }

    void set(size_t idx, T value)
    {
        assert(idx < _size);
        *(_data + 1 + idx) = value;
    }

    T get(size_t idx)
    {
        assert(idx < _size);
        return *(_data + 1 + idx);
    }

    size_t size() const
    {
        return _size;
    }

    static void *operator new(size_t sz, size_t len)
    {
        return static_cast<T*>(malloc(sz + len * sizeof(T)));
    }

    static void operator delete(void* ptr) noexcept
    {
        free(ptr);
    }
};

template<typename T>
std::unique_ptr<T> make_line(size_t size)
{
    return std::unique_ptr<T>(new(size) T(size));
}

int main()
{
    using line_d = line<double>;
    size_t line_len = 5;

    unique_ptr<line_d> l = make_line<line_d>(line_len);
    l->set(0, 1.2);
    l->set(1, 2.3);
    l->set(2, 3.4);
    l->set(3, 4.5);
    l->set(4, 5.6);

    for (size_t i = 0; i < l->size(); ++i) {
        cout << l->get(i) << endl;
    }

    return 0;
}
