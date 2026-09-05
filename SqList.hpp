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

    bool GetElem(int position, A &a) const;
    bool SetElem(int position, const A &a);
    bool Delete(int position);
    bool Insert(int position, const A &a);
    int Search(const A &a) const;

    SqList(const SqList<A> &source);
    SqList<A> &operator=(const SqList<A> &source);
};

template<class A>
SqList<A>::SqList(int size) {
    maxsize = size;
    point = new A[maxsize];
    count = 0;
}

template<class A>
SqList<A>::~SqList() {
    delete[] point;
}

template<class A>
int SqList<A>::GetLength() const {
    return count;
}

template<class A>
bool SqList<A>::isEmpty() const {
    return count == 0;
}

template<class A>
void SqList<A>::Clear() {
    count = 0;
}

template<class A>
template<class B>
void SqList<A>::Traverse(B visit) const {
    for (int i = 0; i < GetLength(); i++) {
        visit(point[i]);
    }
}

template<class A>
bool SqList<A>::GetElem(int position, A &a) const {
    if (position < 1 || position > GetLength()) {
        return false;
    } else {
        a = point[position - 1];
        return true;
    }
}

template<class A>
bool SqList<A>::SetElem(int position, const A &a) {
    if (position < 1 || position > GetLength()) {
        return false;
    } else {
        point[position - 1] = a;
        return true;
    }
}

template<class A>
bool SqList<A>::Delete(int position) {
    if (position < 1 || position > GetLength()) {
        return false;
    } else {
        for (int i = position; i < GetLength(); i++) {
            point[i - 1] = point[i];
        }
        count--;
        return true;
    }
}

template<class A>
int SqList<A>::Search(const A &a) const {
    for (int i = 0; i < count; i++) {
        if (point[i] == a) {
            return i + 1;
        }
    }
    return -1;
}

template<class A>
bool SqList<A>::Insert(int position, const A &a) {
    if (count == maxsize) {
        return false;
    } else if (position < 1 || position > GetLength() + 1) {
        return false;
    } else {
        for (int i = GetLength(); i >= position; i--) {
            point[i] = point[i - 1];
        }
        point[position - 1] = a;
        count++;
        return true;
    }
}

template<class A>
SqList<A>::SqList(const SqList<A> &source) {
    maxsize = source.maxsize;
    count = source.count;
    point = new A[maxsize];
    for (int i = 0; i < count; i++) {
        point[i] = source.point[i];
    }
}

template<class A>
SqList<A> &SqList<A>::operator=(const SqList<A> &source) {
    if (this != &source) {
        maxsize = source.maxsize;
        count = source.count;
        delete[] point;
        point = new A[maxsize];
        for (int i = 0; i < count; i++) {
            point[i] = source.point[i];
        }
    }
    return *this;
}