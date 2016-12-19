#ifndef __QUEUE_H__
#define __QUEUE_H__

const int MAX_SIZE = 999;

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
    size_t count; //��������� � �������
    size_t MaxCount; //�������� ���������
public:
    TQueue();
    TQueue(size_t max);
    TQueue(T &node);
    ~TQueue();
//insert 
    void InsFirst(T &node); //�������� � ������ �������
    void InsLast(T &node); //�������� � ����� �������
    void Insert(T &node, size_t pos); //�������� � ����������� ������� � �������
//delete
    void DelFirst(); //������� ������
    void DelLast(); //������� ���������
    void Delete(size_t pos); //������� ������� �� ������� pos
//operation with elements
    size_t GetCount(); //�������� ������ �������
    T GetElement(size_t pos); //������� �������
    void SetElement(T elem, size_t pos); //�������� �������
    unsigned int GetPriority(size_t pos); //�������� ��������� ��������
    void IncPriority(size_t pos); //��������� ��������� �������� �� 1
//Checking the status
    bool IsFull(); //��������� ������� �� �������������
    bool IsEmpty(); //��������� ������� �� �������
};

template <class T>
TQueue<T>::TQueue() : pFirst(nullptr), count(0)
{}

template <class T>
TQueue<T>::TQueue(size_t max) : pFirst(nullptr), count(0), MaxCount(max)
{}

template <class T>
TQueue<T>::TQueue(T &node)
{
    pFirst = new TNode<T>;
    pFirst->Value = node;
    pFirst->pNext = nullptr;
    MaxCount = MAX_SIZE;
    count = 1;
}

template <class T>
TQueue<T>::~TQueue()
{
    if (pFirst != nullptr)
    {
        TNode<T>* p;
        for (int i = 0; i < count; i++)
        {
            p = pFirst->pNext;
            delete pFirst;
            pFirst = p;
        }
        delete pFirst;
    }
}

//insert

template <class T>
void TQueue<T>::InsFirst(T &node)
{
    TNode<T> *p = new TNode<T>();
    p->priotiry = 0;
    p->Value = node;
    p->pNext = pFirst;
    pFirst = p;
    count++;
}

template <class T>
void TQueue<T>::InsLast(T &node)
{
    TNode<T>* p = pFirst;
    if (count == 0)
    {
        InsFirst(node);
        return;
    }
    for (int i = 0; i < count - 1; i++)
        p = p->pNext;
    TNode<T>* tmp = new TNode<T>;
    tmp->priotiry = 0;
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
        tmp->priority = 0;
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
        p = pFirst->pNext;
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
        TNode<T>* tmp = p->pNext->pNext;
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

template <class T>
bool TQueue<T>::IsFull()
{
    if (MaxCount == count)
        return 1;
    else
        return 0;
}

template <class T>
bool TQueue<T>::IsEmpty()
{
    if (0 == count)
        return 1;
    else
        return 0;
}

#endif
