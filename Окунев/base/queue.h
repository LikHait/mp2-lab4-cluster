#ifndef __QUEUE_H__
#define __QUEUE_H__

template <typename T>
struct TNode
{
    T Value;
    TNode* pNext;
    unsigned int priotiry;
};

template <class T>
class TQueue
{
    TNode<T>* pFirst;
    size_t count;
public:
    TQueue();
    TQueue(T &node);
//insert
    void InsFirst(T &node);
    void InsLast(T &node);
    void Insert(T &node, size_t pos);
//delete
    void DelFirst();
    void DelLast();
    void Delete(size_t pos);
    size_t GetCount();
    T GetElement(size_t pos); 
    void SetElement(T elem, size_t pos);
    unsigned int GetPriority(size_t pos);
    void IncPriority(size_t pos);
};

template <class T>
TQueue<T>::TQueue() : pFirst(nullptr), count(0)
{}

template <class T>
TQueue<T>::TQueue(T &node)
{
    pFirst = new TNode<T>;
    pFirst->Value = node;
    pFirst->pNext = nullptr;
    count = 1;
}

//insert

template <class T>
void TQueue<T>::InsFirst(T &node)
{
    TNode<T> *p = new TNode<T>();
    p->Value = node;
    p->pNext = pFirst;
    pFirst = p;
    count++;
}

template <class T>
void TQueue<T>::InsLast(T &node)
{
    TNode<T>* p = pFirst;
    for (int i = 0; i < pos - 1; i++)
        p = p->pNext;
    TNode<T>* tmp = new TNode<T>;
    tmp->Value = node;
    tmp->pNext = nullptr;
    if (p != nullptr)
        p->pNext = tmp;
    else
        pFirst = tmp;
    count++;
}

template <class T>
void TQueue<T>::Insert(T &node, size_t pos)
{
    if (pos > count)
        throw("Incorrect position for insertion");
    if (pos == 0)
        InsFirst(node);
    else if (pos == count)
        InsLast(node);
    else
    {
        TNode<T>* tmp = new TNode<T>;
        tmp->Value = node;
        TNode<T>* p = pFirst;
        for (int i = 0; i < pos - 1; i++)
            p = p->pNext;
        tmp->pNext = p->pNext;
        p->pNext = tmp;
    }
}

//delete

template <class T>
void TQueue<T>::Delete(size_t pos)
{
    if (pos > count - 1)
        throw("Attempt to remove a non-existent element");
    TNode<T>* p = pFirst;
    for (int i = 0; i < pos - 1; i++)
        p->pNext;
    if (pos == 0)
    {
        p = p->pNext;
        delete pFirst;
        pFirst = p;
    }
    else if (pos == count - 1)
    {
        delete p->pNext;
        p->pNext = nullptr;
    }
    else
    {
        TNode<T> tmp = p->pNext->pNext;
        delete p->pNext;
        p->pNext = tmp;
    }
    count--;
}

template <class T>
void TQueue<T>::DelFirst()
{
    Delete(0);
}

template <class T>
void TQueue<T>::DelLast()
{
    Delete(count - 1);
}

template <class T>
size_t TQueue<T>::GetCount()
{
    return count;
}

template <class T>
T TQueue<T>::GetElement(size_t pos)
{
    if (pos > count - 1)
        throw("Attempt to get a non-existent element");
    TNode<T>* p = pFirst;
    for (int i = 0; i < pos; i++)
        p = p->pNext;
    return p->Value;
}

template <class T>
void TQueue<T>::SetElement(T elem, size_t pos)
{
    if (pos > count - 1)
        throw("Attempt to get a non-existent element");
    TNode<T>* p = pFirst;
    for (int i = 0; i < pos; i++)
        p = p->pNext;
    p->Value = elem;
}

template <class T>
unsigned int TQueue<T>::GetPriority(size_t pos)
{
    if (pos > count - 1)
        throw("Attempt to get a non-existent element");
    TNode<T>* p = pFirst;
    for (int i = 0; i < pos; i++)
        p = p->pNext;
    return p->priotiry;
}

template <class T>
void TQueue<T>::IncPriority(size_t pos)
{
    if (pos > count - 1)
        throw("Attempt to get a non-existent element");
    TNode<T>* p = pFirst;
    for (int i = 0; i < pos; i++)
        p = p->pNext;
    p->priotiry++;
}

#endif
