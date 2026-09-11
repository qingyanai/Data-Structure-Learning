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
class SimpleCircLinkList
{
    protected:
    Node<A>* head;

    Node<A>* GetPoint(int position) const;

    public:
    SimpleCircLinkList();
    ~SimpleCircLinkList();
    int GetLength() const;
    bool isEmpty() const;
    void Clear();

    template<class B>
    void Traverse(B visit) const;

    bool GetElem(int position,A& a) const;
    bool SetElem(int position,const A& a);
    bool Delete(int position);
    bool Insert(int position,const A& a);

    SimpleCircLinkList(const SimpleCircLinkList<A>& source);
    SimpleCircLinkList<A>& operator=(const SimpleCircLinkList<A>& source);
};

template<class A>
Node<A>::Node()
{
    next=NULL;
}

template<class A>
Node<A>::Node(const A& a,Node<A>* link)
{
    data=a;
    next=link;
}

template<class A>
Node<A>* SimpleCircLinkList<A>::GetPoint(int position) const
{
    if(position==0)
    {
        return head;
    }
    Node<A>* temp=head->next;
    int temPos=1;
    while(temp!=head&&temPos<position)
    {
        temp=temp->next;
        temPos++;
    }
    if(temp!=head&&temPos==position)
    {
        return temp;
    }
    else
    {
        return NULL;
    }
}

template<class A>
SimpleCircLinkList<A>::SimpleCircLinkList()
{
    head=new Node<A>;
    head->next=head;
}

template<class A>
SimpleCircLinkList<A>::~SimpleCircLinkList()
{
    Clear();
    delete head;
}

template<class A>
int SimpleCircLinkList<A>::GetLength() const
{
    int count=0;
    for(Node<A>* temp=head->next;temp!=head;temp=temp->next)
    {
        count++;
    }
    return count;
}

template<class A>
bool SimpleCircLinkList<A>::isEmpty() const
{
    return head->next==head;
}

template<class A>
void SimpleCircLinkList<A>::Clear()
{
    Node<A>* temp=head->next;
    while(temp!=head)
    {
        Node<A>* toDelete=temp;
        temp=temp->next;
        delete toDelete;
    }
    head->next=head;
}

template<class A>
template<class B>
void SimpleCircLinkList<A>::Traverse(B visit) const
{
    for(Node<A>* temp=head->next;temp!=head;temp=temp->next)
    {
        visit(temp->data);
    }
}

template<class A>
bool SimpleCircLinkList<A>::GetElem(int position,A &a) const
{
    if(position<1||position>GetLength())
    {
        return false;
    }
    else
    {
        Node<A>* temp=GetPoint(position);
        a=temp->data;
        return true;
    }
}

template<class A>
bool SimpleCircLinkList<A>::SetElem(int position,const A& a)
{
    if(position<1||position>GetLength())
    {
        return false;
    }
    else
    {
        Node<A>* temp=GetPoint(position);
        temp->data=a;
        return true;
    }
}

template<class A>
bool SimpleCircLinkList<A>::Delete(int position)
{
    if(position<1||position>GetLength())
    {
        return false;
    }
    else
    {
        Node<A>* temp1=GetPoint(position-1);
        Node<A>* temp2=temp1->next;
        temp1->next=temp2->next;
        delete temp2;
        return true;
    }
}

template<class A>
bool SimpleCircLinkList<A>::Insert(int position,const A&a)
{
    if(position<1||position>GetLength()+1)
    {
        return false;
    }
    else
    {
        Node<A>* temp1=GetPoint(position-1);
        Node<A>* temp2=new Node<A>(a,temp1->next);
        temp1->next=temp2;
        return true;
    }
}

template<class A>
SimpleCircLinkList<A>::SimpleCircLinkList(const SimpleCircLinkList<A>& source)
{
    head=new Node<A>;
    head->next=head;

    Node<A>* tail=head;
    Node<A>* srcCur=source.head->next;
    while(srcCur!=source.head)
    {
        Node<A>* temp=new Node<A>;
        temp->data=srcCur->data;
        temp->next=head;
        tail->next=temp;
        tail=temp;
        srcCur=srcCur->next;
    }
}

template<class A>
SimpleCircLinkList<A>& SimpleCircLinkList<A>::operator=(const SimpleCircLinkList<A>& source)
{
    if(this!=&source)
    {
        Clear();

        Node<A>* tail=head;
        Node<A>* srcCur=source.head->next;
        while(srcCur!=source.head)
        {
            Node<A>* temp=new Node<A>;
            temp->data=srcCur->data;
            temp->next=head;
            tail->next=temp;
            tail=temp;
            srcCur=srcCur->next;
        }
    }
    return *this;
}