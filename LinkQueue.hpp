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
class LinkQueue
{
    protected:
    Node<A>* front;
    Node<A>* rear;
    int count;

    public:
    LinkQueue();
    ~LinkQueue();
    int GetLength() const;
    bool isEmpty() const;
    void Clear();

    template<class B>
    void Traverse(B visit) const;

    bool OutQueue(A& a);
    bool OutQueue();
    bool GetHead(A& a) const;
    bool InQueue(const A& a);

    LinkQueue(const LinkQueue<A>& source);
    LinkQueue<A>& operator=(const LinkQueue<A>& source);
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
LinkQueue<A>::LinkQueue()
{
    front=rear=new Node<A>;
    count=0;
}

template<class A>
LinkQueue<A>::~LinkQueue()
{
    Clear();
    delete front;
}

template<class A>
int LinkQueue<A>::GetLength() const
{
    return count;
}

template<class A>
bool LinkQueue<A>::isEmpty() const
{
    return count==0;
}

template<class A>
void LinkQueue<A>::Clear()
{
    while(!isEmpty())
    {
        OutQueue();
    }
}

template<class A>
template<class B>
void LinkQueue<A>::Traverse(B visit) const
{
    for(Node<A>* temp=front->next;temp!=nullptr;temp=temp->next)
    {
        visit(temp->data);
    }
}

template<class A>
bool LinkQueue<A>::OutQueue(A& a)
{
    if(!isEmpty())
    {
        Node<A>* temp=front->next;
        a=temp->data;
        front->next=temp->next;
        if(rear==temp)
        {
            rear=front;
        }
        delete temp;
        count--;
        return true;
    }
    else
    {
        return false;
    }
}

template<class A>
bool LinkQueue<A>::OutQueue()
{
    if(!isEmpty())
    {
        Node<A>* temp=front->next;
        front->next=temp->next;
        if(rear==temp)
        {
            rear=front;
        }
        delete temp;
        count--;
        return true;
    }
    else
    {
        return false;
    }
}

template<class A>
bool LinkQueue<A>::GetHead(A& a) const
{
    if(!isEmpty())
    {
        Node<A>* temp=front->next;
        a=temp->data;
        return true;
    }
    else
    {
        return false;
    }
}

template<class A>
bool LinkQueue<A>::InQueue(const A& a)
{
    Node<A>* temp=new Node<A>(a,nullptr);
    if(temp==nullptr)
    {
        return false;
    }
    else
    {
        rear->next=temp;
        rear=temp;
        count++;
        return true;
    }
}

template<class A>
LinkQueue<A>::LinkQueue(const LinkQueue<A>& source)
{
    rear=front=new Node<A>;
    count=0;
    for(Node<A>* temp=source.front->next;temp!=nullptr;temp=temp->next)
    {
        InQueue(temp->data);
    }
}

template<class A>
LinkQueue<A>& LinkQueue<A>::operator=(const LinkQueue<A>& source)
{
    if(this!=&source)
    {
        Clear();
        for(Node<A>* temp=source.front->next;temp!=nullptr;temp=temp->next)
        {
            InQueue(temp->data);
        }
    }
    return *this;
}