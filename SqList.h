#pragma once
#include <iostream>

template<class A>
class SqList
{
    protected:
    A *point;
    int count;
    int maxsize;

    public:
    SqList(int size);
    ~SqList();

    int GetLength() const;
    bool isEmpty() const;
    void Clear();

    template<class B>
    void Traverse(B visit) const;

    bool GetElem(int position,A &a) const;
    bool SetElem(int position,const A &a);
    bool Delete(int position);
};