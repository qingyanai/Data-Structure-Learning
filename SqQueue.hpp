#pragma once
#include <iostream>

template<class A>
class SqQueue
{
    protected:
    A* point;
    int maxsize;
    int front;
    int rear;
    int count;

    public:
    SqQueue(int size);
    ~SqQueue();
    int GetLength() const;
    bool isEmpty() const;
    void Clear();

    template<class B>
    void Traverse(B visit) const;
    
    bool OutQueue(A& a);
    bool OutQueue();
    bool GetHead(A& a) const;
    bool InQueue(const A& a);

    SqQueue(const SqQueue<A>& source);
    SqQueue<A>& operator=(const SqQueue<A>& source);
};

template<class A>
SqQueue<A>::SqQueue(int size)
{
    maxsize=size;
    point=new A[maxsize];
    rear=front=0;
    count=0;
}

template<class A>
SqQueue<A>::~SqQueue()
{
    delete[]point;
}

template<class A>
int SqQueue<A>::GetLength() const
{
    return count;
}

template<class A>
bool SqQueue<A>::isEmpty() const
{
    return count==0;
}

template<class A>
void SqQueue<A>::Clear()
{
    rear=front=0;
    count=0;
}

template<class A>
template<class B>
void SqQueue<A>::Traverse(B visit) const
{
    for (int i = 0; i < count; i++) 
    {
        visit(point[(front + i) % maxsize]);
    }
}

template<class A>
bool SqQueue<A>::OutQueue(A& a)
{
    if(!isEmpty())
    {
        a=point[front];
        front=(front+1)%maxsize;
        count--;
        return true;
    }
    else
    {
        return false;
    }
}

template<class A>
bool SqQueue<A>::OutQueue()
{
    if(!isEmpty())
    {
        front=(front+1)%maxsize;
        count--;
        return true;
    }
    else
    {
        return false;
    }
}

template<class A>
bool SqQueue<A>::GetHead(A& a) const
{
    if(!isEmpty())
    {
        a=point[front];
        return true;
    }
    else
    {
        return false;
    }
}

template<class A>
bool SqQueue<A>::InQueue(const A& a)
{
    if(count==maxsize)
    {
        return false;
    }
    else
    {
        point[rear]=a;
        rear=(rear+1)%maxsize;
        count++;
        return true;
    }
}

template<class A>
SqQueue<A>::SqQueue(const SqQueue<A>& source)
{
    maxsize=source.maxsize;
    point=new A[maxsize];
    front=source.front;
    rear=source.rear;
    count=source.count;
    for (int i = 0; i < count; i++) 
    {
        point[(front + i) % maxsize] = source.point[(source.front + i) % maxsize];
    }
}

template<class A>
SqQueue<A>& SqQueue<A>::operator=(const SqQueue<A>& source)
{
    if(this!=&source)
    {
        maxsize=source.maxsize;
        delete[]point;
        point=new A[maxsize];
        front=source.front;
        rear=source.rear;
        count=source.count;
        for (int i = 0; i < count; i++) 
        {
            point[(front + i) % maxsize] = source.point[(source.front + i) % maxsize];
        }
    }
    return *this;
}