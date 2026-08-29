#ifndef ARRAY_SEQUENCE_H
#define ARRAY_SEQUENCE_H

#include "Sequence.h"
#include "DynamicArray.h"

template<class T>
class ArraySequence : public Sequence<T>
{
private:
    DynamicArray<T> data;

public:

    ArraySequence();

    T Get(int index) const override;

    int GetLength() const override;

    void Append(const T& item) override;

    void Prepend(const T& item) override;

    void InsertAt(const T& item, int index) override;
};

template<class T>
ArraySequence<T>::ArraySequence()
{
}

template<class T>
T ArraySequence<T>::Get(int index) const
{
    return data.Get(index);
}

template<class T>
int ArraySequence<T>::GetLength() const
{
    return data.GetSize();
}

template<class T>
void ArraySequence<T>::Append(const T& item)
{
    int size = data.GetSize();

    data.Resize(size + 1);
    data.Set(size, item);
}

template<class T>
void ArraySequence<T>::Prepend(const T& item)
{
    int size = data.GetSize();

    data.Resize(size + 1);

    for (int i = size; i > 0; i--)
        data.Set(i, data.Get(i - 1));

    data.Set(0, item);
}

template<class T>
void ArraySequence<T>::InsertAt(const T& item, int index)
{
    int size = data.GetSize();

    if (index < 0 || index > size)
        throw std::out_of_range("Index out of range");

    data.Resize(size + 1);

    for (int i = size; i > index; i--)
        data.Set(i, data.Get(i - 1));

    data.Set(index, item);
}

#endif
