#ifndef __QUEUE_H__
#define __QUEUE_H__

template <typename T>
struct TNode
{
    T Value;
    TNode* pNext;
};

template <class T>
class TQueue
{
    TNode<T>* pFirst;
    size_t count;
public:
    TQueue();
    TQueue(T &node);
    void InsFirst(T &node);
    void InsLast(T &node);
    void Insert(T &node, size_t pos);
    void Delete(size_t pos);
};

template <class T>
TQueue<T>::TQueue() : pFirst(nullptr), count(0)
{
}

template <class T>
TQueue<T>::TQueue(T &node)
{
    pFirst = new TNode<T>;
    pFirst->Value = node;
    pFirst->pNext = nullptr;
    count = 1;
}

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


#endif