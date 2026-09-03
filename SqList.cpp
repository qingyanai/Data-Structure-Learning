#include "SqList.h"

template<class A>
SqList<A>::SqList(int size)
{
    maxsize=size;
    point=new A[maxsize];
    count=0;
}

template<class A>
SqList<A>::~SqList()
{
    delete[]point;
}

template<class A>
int SqList<A>::GetLength() const
{
    return count;
}

template<class A>
bool SqList<A>::isEmpty() const
{
    return count==0;
}

template<class A>
void SqList<A>::Clear()
{
    count=0;
}

template<class A>
template<class B>
void SqList<A>::Traverse(B visit) const
{
    for(int i=0;i<GetLength();i++)
    {
        visit(point[i]);
    }
}

template<class A>
bool SqList<A>::GetElem(int position,A &a) const
{
    if(position<1||position>GetLength())
    {
        return false;
    }
    else
    {
        a=point[position-1];
        return true;
    }
}

template<class A>
bool SqList<A>::SetElem(int position,const A &a)
{
    if(position<1||position>GetLength())
    {
        return false;
    }
    else
    {
        point[position-1]=a;
        return true;
    }
}

template<class A>
bool SqList<A>::Delete(int position)
{
    if(position<1||position>GetLength())
    {
        return false;
    }
    else
    {
        A temp;
        for(int i=position;i<GetLength();i++)
        {
            point[i-1]=point[i];
        }
        count--;
        return true;
    }
}