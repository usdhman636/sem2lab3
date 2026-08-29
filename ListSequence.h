#ifndef LIST_SEQUENCE_H
#define LIST_SEQUENCE_H

#include "Sequence.h"
#include "LinkedList.h"

template<class T>
class ListSequence : public Sequence<T>
{
private:
    LinkedList<T> list;

public:

    ListSequence();

    T Get(int index) const override;

    int GetLength() const override;

    void Append(const T& item) override;

    void Prepend(const T& item) override;

    void InsertAt(const T& item, int index) override;
};

template<class T>
ListSequence<T>::ListSequence()
{
}

template<class T>
T ListSequence<T>::Get(int index) const
{
    return list.Get(index);
}

template<class T>
int ListSequence<T>::GetLength() const
{
    return list.GetLength();
}

template<class T>
void ListSequence<T>::Append(const T& item)
{
    list.Append(item);
}

template<class T>
void ListSequence<T>::Prepend(const T& item)
{
    list.Prepend(item);
}

template<class T>
void ListSequence<T>::InsertAt(const T& item, int index)
{
    list.InsertAt(item, index);
}

#endif
