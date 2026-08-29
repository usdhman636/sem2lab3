#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdexcept>

template <class T>
class DynamicArray
{
private:
    T* data;
    int size;

public:
    DynamicArray();
    DynamicArray(int size);

    DynamicArray(const DynamicArray<T>& other);

    ~DynamicArray();

    int GetSize() const;

    T Get(int index) const;

    void Set(int index, const T& value);

    void Resize(int newSize);
};

template<class T>
DynamicArray<T>::DynamicArray()
{
    size = 0;
    data = nullptr;
}

template<class T>
DynamicArray<T>::DynamicArray(int size)
{
    if (size < 0)
        throw std::invalid_argument("Negative size");

    this->size = size;
    data = new T[size];
}

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other)
{
    size = other.size;

    data = new T[size];

    for (int i = 0; i < size; i++)
        data[i] = other.data[i];
}

template<class T>
DynamicArray<T>::~DynamicArray()
{
    delete[] data;
}

template<class T>
int DynamicArray<T>::GetSize() const
{
    return size;
}

template<class T>
T DynamicArray<T>::Get(int index) const
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");

    return data[index];
}

template<class T>
void DynamicArray<T>::Set(int index, const T& value)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");

    data[index] = value;
}

template<class T>
void DynamicArray<T>::Resize(int newSize)
{
    if (newSize < 0)
        throw std::invalid_argument("Negative size");

    T* newData = new T[newSize];

    int minSize = (size < newSize) ? size : newSize;

    for (int i = 0; i < minSize; i++)
        newData[i] = data[i];

    delete[] data;

    data = newData;
    size = newSize;
}

#endif
