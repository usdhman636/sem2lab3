#ifndef SEQUENCE_H
#define SEQUENCE_H

template<class T>
class Sequence
{
public:

    virtual ~Sequence() {}

    virtual T Get(int index) const = 0;

    virtual int GetLength() const = 0;

    virtual void Append(const T& item) = 0;

    virtual void Prepend(const T& item) = 0;

    virtual void InsertAt(const T& item, int index) = 0;
};

#endif
