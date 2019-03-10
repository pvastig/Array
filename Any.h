
struct ICloneable
{
    virtual ICloneable* clone() const = 0;
    virtual ~ICloneable() { }
};

template <class T>
struct ValueHolder : public ICloneable
{
    ValueHolder(T const & data) : data_(data) {}
    ICloneable * clone() const override { return new ValueHolder(data_); }
    T data_;
};

class Any
{
public:
    Any()
    {
    }
    template<class T>
    Any(T value)
    {
        m_value = ValueHolder<T>(value).clone();
    }
    ~Any()
    {
        delete m_value;
    }

    Any(Any const & other)
    {
        if(other.m_value)
            m_value = other.m_value->clone();
    }
    Any & operator=(Any const & other)
    {
        if (this != &other)
        {
            delete m_value;
            m_value = other.m_value->clone();
        }
        return *this;
    }
    template<class T>
    T * cast()
    {
        if (ValueHolder<T>* val = dynamic_cast<ValueHolder<T>*>(m_value))
            return &val->data_;
        return nullptr;
    }

private:
    ICloneable * m_value = nullptr;
};
