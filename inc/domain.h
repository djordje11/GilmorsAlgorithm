#ifndef __DOMAIN_H__
#define __DOMAIN_H__

#include <set>


template <typename T>
class Domain
{
public:
    virtual bool has_value(T value) const = 0;
    virtual void add_value(T value) = 0;
};


template <typename T>
class FiniteDomain : public Domain<T>
{
    std::set<T> m_values;
public:
    FiniteDomain(const std::set<T>& values) : m_values(values) {} 
    bool has_value(T value) const override;
    void add_value(T value) override;
};

template <typename T>
bool FiniteDomain<T>::has_value(T value) const
{
    return m_values.find(value) != m_values.end();
}

template <typename T>
void FiniteDomain<T>::add_value(T value) 
{
    m_values.insert(value);
}



template <typename T>
class InfiniteDomain : public Domain<T>
{
public:
    InfiniteDomain() {} 
    bool has_value(T value) const override;
    void add_value(T value) override;
};

template <typename T>
bool InfiniteDomain<T>::has_value(T value) const
{
    return true;
}

template <typename T>
void InfiniteDomain<T>::add_value(T value) 
{
}


#endif // __DOMAIN_H__