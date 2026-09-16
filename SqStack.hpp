#pragma once
#include <iostream>

template<class A>
class SqStack
{
    protected:
    A *point;
    int maxsize;
    int count;

    public:
    SqStack(int size);
    ~SqStack();
    int GetLength() const;
    bool isEmpty() const;
    void Clear();

    template<class B>
    void Traverse(B visit) const;

    bool Push(const A& a);
    bool Top(A& a) const;
    bool Pop(A& a);
    bool Pop();

    SqStack(const SqStack<A>& source);
    SqStack<A>& operator=(const SqStack<A>& source);
};

template<class A>
SqStack<A>::SqStack(int size)
{
    maxsize=size;
    point=new A[maxsize];
    count=0;
}

template<class A>
SqStack<A>::~SqStack()
{
    delete []point;
}

template<class A>
int SqStack<A>::GetLength() const
{
    return count;
}

template<class A>
bool SqStack<A>::isEmpty() const
{
    return count==0;
}

template<class A>
void SqStack<A>::Clear()
{
    count=0;
}

template<class A>
template<class B>
void SqStack<A>::Traverse(B visit) const
{
    for(int i=0;i<GetLength();i++)
    {
        visit(point[i]);
    }
}

template<class A>
bool SqStack<A>::Push(const A& a)
{
    if(count==maxsize)
    {
        return false;
    }
    else
    {
        point[count]=a;
        count++;
        return true;
    }
}

template<class A>
bool SqStack<A>::Top(A& a) const
{
    if(isEmpty())
    {
        return false;
    }
    else
    {
        a=point[count-1];
        return true;
    }
}

template<class A>
bool SqStack<A>::Pop(A& a)
{
    if(isEmpty())
    {
        return false;
    }
    else
    {
        a=point[count-1];
        count--;
        return true;
    }
}

template<class A>
bool SqStack<A>::Pop()
{
    if(isEmpty())
    {
        return false;
    }
    else
    {
        count--;
        return true;
    }
}

template<class A>
SqStack<A>::SqStack(const SqStack<A>& source)
{
    maxsize=source.maxsize;
    count=source.count;
    point=new A[maxsize];
    for(int i=0;i<count;i++)
    {
        point[i]=source.point[i];
    }
}

template<class A>
SqStack<A>& SqStack<A>::operator=(const SqStack<A>& source)
{
    if(this!=&source)
    {
        maxsize=source.maxsize;
        delete []point;
        count=source.count;
        point=new A[maxsize];
        for(int i=0;i<count;i++)
        {
            point[i]=source.point[i];
        }
    }
    return *this;
}