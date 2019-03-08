#include <cstddef>

template <class T>
class Array
{
public:
    explicit Array(size_t size, const T& value = T())
        : m_size(size)
        , m_data(static_cast<T*>(operator new [](m_size * sizeof(T))))
    {
        for (int i = 0; i != m_size; ++i)
            new (m_data + i) T(value);
    }
    Array()
    {

    }
    Array(Array const & other)
    {
        m_size = other.size();
        m_data = static_cast<T*>(operator new [](m_size * sizeof(T)));
        for (int i = 0; i != m_size; ++i)
            new (m_data + i) T(other[i]);
    }
    ~Array()
    {
        for (int i = 0; i != m_size; i++)
            m_data[i].~T();
        operator delete[] (m_data);
    }
    Array& operator=(Array const & other)
    {
        if (this != &other)
        {
            for (int i = 0; i != m_size; i++)
                m_data[i].~T();
            operator delete[] (m_data);

            m_size = other.size();
            m_data = static_cast<T*>(operator new [](m_size * sizeof(T)));
            for (int i = 0; i != m_size; ++i)
                new (m_data + i) T(other[i]);
        }

        return *this;
    }

    size_t size() const
    {
        return m_size;
    }
    T& operator[](size_t i)
    {
        return m_data[i];
    }
    const T& operator[](size_t i) const
    {
        return m_data[i];
    }
private:
    size_t m_size = 0;
    T * m_data = nullptr;
};
