#pragma once
#include <iostream>

template<class A>
struct Node
{
    A data;
    Node<A>* next;

    Node();
    Node(const A& a,Node<A>* link);
};

template<class A>
class LinkStack
{
    protected:
    Node<A>* top;
    int count;

    public:
    LinkStack();
    ~LinkStack();
    int GetLength() const;
    bool isEmpty() const;
    void Clear();

    template<class B>
    void Traverse(B visit) const;

    bool Push(const A& a);
    bool Top(A& a) const;
    bool Pop(A& a);
    bool Pop();

    LinkStack(const LinkStack<A>& source);
    LinkStack<A>& operator=(const LinkStack<A>& source);
};

template<class A>
Node<A>::Node()
{
    next=nullptr;
}

template<class A>
Node<A>::Node(const A& a,Node<A>* link)
{
    data=a;
    next=link;
}

template<class A>
LinkStack<A>::LinkStack()
{
    top=nullptr;
    count=0;
}

template<class A>
LinkStack<A>::~LinkStack()
{
    Clear();
}

template<class A>
int LinkStack<A>::GetLength() const
{
    return count;
}

template<class A>
bool LinkStack<A>::isEmpty() const
{
    return count==0;
}

template<class A>
void LinkStack<A>::Clear()
{
    while(!isEmpty())
    {
        Pop();
    }
}

template<class A>
template<class B>
void LinkStack<A>::Traverse(B visit) const
{
    Node<A>* temp1;
    LinkStack<A> temp2;
    for(temp1=top;temp1!=nullptr;temp1=temp1->next)
    {
        temp2.Push(temp1->data);
    }
    for(temp1=temp2.top;temp1!=nullptr;temp1=temp1->next)
    {
        visit(temp1->data);
    }
}

template<class A>
bool LinkStack<A>::Push(const A& a)
{
    Node<A>* newtop=new Node<A>(a,top);
    if(newtop==nullptr)
    {
        return false;
    }
    else
    {
        top=newtop;
        count++;
        return true;
    }
}

template<class A>
bool LinkStack<A>::Top(A& a) const
{
    if(isEmpty())
    {
        return false;
    }
    else
    {
        a=top->data;
        return true;
    }
}

template<class A>
bool LinkStack<A>::Pop(A& a)
{
    if(isEmpty())
    {
        return false;
    }
    else
    {
        Node<A>* oldtop=top;
        a=oldtop->data;
        top=oldtop->next;
        delete oldtop;
        count--;
        return true;
    }
}

template<class A>
bool LinkStack<A>::Pop()
{
    if(isEmpty())
    {
        return false;
    }
    else
    {
        Node<A>* oldtop=top;
        top=oldtop->next;
        delete oldtop;
        count--;
        return true;
    }
}

template<class A>
LinkStack<A>::LinkStack(const LinkStack<A>& source)
{
    if(source.isEmpty())
    {
        top=nullptr;
        count=0;
    }
    else
    {
        top=new Node<A>(source.top->data,nullptr);
        count=source.count;
        Node<A>* bottom=top;
        for(Node<A>* temp=source.top->next;temp!=nullptr;temp=temp->next)
        {
            bottom->next=new Node<A>(temp->data,nullptr);
            bottom=bottom->next;
        }
    }
}

template<class A>
LinkStack<A>& LinkStack<A>::operator=(const LinkStack<A>& source)
{
    if(this!=&source)
    {
        Clear();
        if(source.isEmpty())
        {
            top=nullptr;
            count=0;
        }
        else
        {
            top=new Node<A>(source.top->data,nullptr);
            count=source.count;
            Node<A>* bottom=top;
            for(Node<A>* temp=source.top->next;temp!=nullptr;temp=temp->next)
            {
                bottom->next=new Node<A>(temp->data,nullptr);
                bottom=bottom->next;
            }
        }
    }
    return *this;
}