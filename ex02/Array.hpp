
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <initializer_list>
#include <iostream>

template <typename T>
class Array
{

public:
    Array(void) noexcept;
    Array(unsigned int n);
    Array(std::initializer_list<T> list);
    Array(const Array &arr);
    ~Array(void);
    Array &operator=(const Array &arr);
    const T &operator[](unsigned int idx) const;
    T &operator[](unsigned int index);
    Array operator+(const Array &other) const;
    size_t size(void) const noexcept;
    T* begin() noexcept { return t; }
    T* end() noexcept { return t + n; }
    const T* begin() const noexcept { return t; }
    const T* end() const noexcept { return t + n; }

    enum Status
    {
        SUCCESS = 0,
        ERR_OUT_OF_BOUNDS,
        ERR_NULL_POINTER
    };

    Status get(unsigned int idx, T &out) const noexcept;

    class ExceptionOutOfBounds : public std::exception
    {
        public:
        virtual const char* what() const noexcept
        {
            return "---- Index OUT ----";
        }
    };
    
private:
    T *t;
    size_t n;   
};


template <typename T>
Array<T>::Array(void) noexcept : t(nullptr), n(0)
{

}

template <typename T>
Array<T>::Array(unsigned int n) : t(new T[n]()), n(n)
{
    
}

template <typename T>
Array<T>::Array(std::initializer_list<T> list) : t(new T[list.size()]()), n(list.size())
{
    size_t i = 0;
    for (const auto &item : list)
    {
        this->t[i++] = item;
    }
}

template <typename T>
Array<T>::Array(const Array &arr) : t(nullptr), n(0)
{
    this->n = arr.size();
    this->t = new T[this->n]();
    for (size_t i = 0; i < this->n; i++)
    {
        this->t[i] = arr[i];
    }
}

template <typename T>
Array<T>::~Array(void)
{
    if (this->t && this->n > 0)
        delete[] this->t;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &arr)
{
    if (this == &arr)
        return *this;
    delete[] this->t;
    this->n = arr.size();
    this->t = new T[this->n]();
    for (size_t i = 0; i < this->n; i++)
    {
        this->t[i] = arr[i];
    }
    return *this;

}

//Read only
template <typename T>
const T &Array<T>::operator[](unsigned int idx) const
{
    if (idx >= n)
    {
        throw ExceptionOutOfBounds();
    }
    return t[idx];
}

//Read and write
template <typename T>
T &Array<T>::operator[](unsigned int idx)
{
    if (idx >= n)
    {
        throw ExceptionOutOfBounds();
    }
    return t[idx];
}

template <typename T>
typename Array<T>::Status Array<T>::get(unsigned int idx, T &out) const noexcept
{
    if (this->t == nullptr)
        return ERR_NULL_POINTER;
    if (idx >= this->n)
        return ERR_OUT_OF_BOUNDS;
    out = this->t[idx];
    return SUCCESS;
}

template <typename T>
size_t Array<T>::size(void) const noexcept
{
    return this->n;
}


template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        os << arr[i] << " ";
    }
    return os;
}

template <typename T>
Array<T> Array<T>::operator+(const Array &other) const
{
    Array<T> new_arr(this->n + other.n);
    for(size_t i = 0; i < this->n; i++)
    {
        new_arr[i] = this->t[i];
    }
    for (size_t i = 0; i < other.n; i++)
    {
        new_arr[this->n + i] = other.t[i];
    }
    return new_arr;
}
#endif