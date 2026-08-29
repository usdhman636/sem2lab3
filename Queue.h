#ifndef QUEUE_H
#define QUEUE_H

#include "ArraySequence.h"
#include <functional>

template<class T>
class Queue
{
private:

    Sequence<T>* sequence;

public:

    Queue();

    ~Queue();

    int GetLength() const;

    void Enqueue(const T& item);

    T Dequeue();

    T Front() const;

    Queue<T> Concat(const Queue<T>& other) const;

    Queue<T> GetSubQueue(int start, int end) const;

    int FindSubQueue(const Queue<T>& sub) const;

    Queue<T> Map(std::function<T(T)> func) const;

    Queue<T> Where(std::function<bool(T)> predicate) const;

    T Reduce(std::function<T(T,T)> func, T startValue) const;

    void Split(
        std::function<bool(T)> predicate,
        Queue<T>& trueQueue,
        Queue<T>& falseQueue
    ) const;

    Queue(const Queue<T>& other);

    Queue<T>& operator=(const Queue<T>& other);
};

template<class T>
Queue<T>::Queue(const Queue<T>& other)
{
    sequence = new ArraySequence<T>();

    for (int i = 0; i < other.GetLength(); i++)
    {
        sequence->Append(other.sequence->Get(i));
    }
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
    if (this == &other)
        return *this;

    delete sequence;

    sequence = new ArraySequence<T>();

    for (int i = 0; i < other.GetLength(); i++)
    {
        sequence->Append(other.sequence->Get(i));
    }

    return *this;
}

template<class T>
Queue<T>::Queue()
{
    sequence = new ArraySequence<T>();
}

template<class T>
Queue<T>::~Queue()
{
    delete sequence;
}

template<class T>
int Queue<T>::GetLength() const
{
    return sequence->GetLength();
}

template<class T>
void Queue<T>::Enqueue(const T& item)
{
    sequence->Append(item);
}

template<class T>
T Queue<T>::Front() const
{
    if (GetLength() == 0)
        throw std::runtime_error("Queue is empty");

    return sequence->Get(0);
}

template<class T>
T Queue<T>::Dequeue()
{
    if (GetLength() == 0)
        throw std::runtime_error("Queue is empty");

    T value = sequence->Get(0);

    ArraySequence<T>* newSequence =
        new ArraySequence<T>();

    for (int i = 1; i < GetLength(); i++)
    {
        newSequence->Append(
            sequence->Get(i)
        );
    }

    delete sequence;
    sequence = newSequence;

    return value;
}

template<class T>
Queue<T> Queue<T>::Concat(const Queue<T>& other) const
{
    Queue<T> result;

    for (int i = 0; i < GetLength(); i++)
        result.Enqueue(sequence->Get(i));

    for (int i = 0; i < other.GetLength(); i++)
        result.Enqueue(other.sequence->Get(i));

    return result;
}

template<class T>
Queue<T> Queue<T>::GetSubQueue(int start, int end) const
{
    if (start < 0 || end >= GetLength() || start > end)
        throw std::runtime_error("Invalid indices");

    Queue<T> result;

    for (int i = start; i <= end; i++)
        result.Enqueue(sequence->Get(i));

    return result;
}

template<class T>
int Queue<T>::FindSubQueue(const Queue<T>& sub) const
{
    if (sub.GetLength() == 0)
        return 0;

    for (int i = 0; i <= GetLength() - sub.GetLength(); i++)
    {
        bool found = true;

        for (int j = 0; j < sub.GetLength(); j++)
        {
            if (sequence->Get(i + j) != sub.sequence->Get(j))
            {
                found = false;
                break;
            }
        }

        if (found)
            return i;
    }

    return -1;
}

template<class T>
Queue<T> Queue<T>::Map(std::function<T(T)> func) const
{
    Queue<T> result;

    for (int i = 0; i < GetLength(); i++)
        result.Enqueue(func(sequence->Get(i)));

    return result;
}

template<class T>
Queue<T> Queue<T>::Where(std::function<bool(T)> predicate) const
{
    Queue<T> result;

    for (int i = 0; i < GetLength(); i++)
    {
        T value = sequence->Get(i);

        if (predicate(value))
            result.Enqueue(value);
    }

    return result;
}

template<class T>
T Queue<T>::Reduce(std::function<T(T,T)> func,
                   T startValue) const
{
    T result = startValue;

    for (int i = 0; i < GetLength(); i++)
        result = func(sequence->Get(i), result);

    return result;
}

template<class T>
void Queue<T>::Split(
    std::function<bool(T)> predicate,
    Queue<T>& trueQueue,
    Queue<T>& falseQueue
) const
{
    for (int i = 0; i < GetLength(); i++)
    {
        T value = sequence->Get(i);

        if (predicate(value))
            trueQueue.Enqueue(value);
        else
            falseQueue.Enqueue(value);
    }
}

#endif
