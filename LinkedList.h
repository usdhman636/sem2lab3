#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdexcept>

template<class T>
class LinkedList
{
private:

    struct Node
    {
        T data;
        Node* next;

        Node(const T& value)
        {
            data = value;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;

    int size;

public:

    LinkedList();

    LinkedList(const LinkedList<T>& other);

    ~LinkedList();

    int GetLength() const;

    T Get(int index) const;

    void Append(const T& item);

    void Prepend(const T& item);

    void InsertAt(const T& item, int index);
};

template<class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
    head = nullptr;
    tail = nullptr;
    size = 0;

    for (int i = 0; i < other.size; i++)
        Append(other.Get(i));
}

template<class T>
LinkedList<T>::~LinkedList()
{
    Node* current = head;

    while (current)
    {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

template<class T>
int LinkedList<T>::GetLength() const
{
    return size;
}

template<class T>
T LinkedList<T>::Get(int index) const
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");

    Node* current = head;

    for (int i = 0; i < index; i++)
        current = current->next;

    return current->data;
}

template<class T>
void LinkedList<T>::Append(const T& item)
{
    Node* node = new Node(item);

    if (!head)
    {
        head = tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }

    size++;
}

template<class T>
void LinkedList<T>::Prepend(const T& item)
{
    Node* node = new Node(item);

    node->next = head;
    head = node;

    if (!tail)
        tail = head;

    size++;
}

template<class T>
void LinkedList<T>::InsertAt(const T& item, int index)
{
    if (index < 0 || index > size)
        throw std::out_of_range("Index out of range");

    if (index == 0)
    {
        Prepend(item);
        return;
    }

    if (index == size)
    {
        Append(item);
        return;
    }

    Node* current = head;

    for (int i = 0; i < index - 1; i++)
        current = current->next;

    Node* node = new Node(item);

    node->next = current->next;
    current->next = node;

    size++;
}

#endif
