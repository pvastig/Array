#include <cstddef>

template<class T>
void swap(T & a, T & b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <class T>
class Array
{
    friend void swap(Array & a, Array & b)
    {
        swap(a.m_size, b.m_size);
        swap(a.m_data, b.m_data);
    }
public:
    explicit Array(size_t size = 0, T const & value = T())
        : m_size(size), m_data(new T[size])
    {
        for (int i = 0; i < m_size; ++i)
            m_data[i] = value;

    }

    Array(Array const & other) : m_size(other.size()), m_data(new T[m_size])
    {
        for (int i = 0; i < m_size; ++i)
            m_data[i] = other[i];
    }

    ~Array()
    {
        delete[] m_data;
    }

    Array& operator=(Array other)
    {
        swap(*this, other);
        return *this;
    }

    size_t size() const
    {
        return m_size;
    }

    T& operator[](size_t index)
    {
        return m_data[index];
    }
    const T& operator[](size_t index) const
    {
        return m_data[index];
    }

private:
    size_t m_size;
    T * m_data;
};
