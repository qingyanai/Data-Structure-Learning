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
class SimpleLinkList
{
    protected:
    Node<A>* head;

    Node<A>* GetPoint(int position) const;

    public:
    SimpleLinkList();
    ~SimpleLinkList();
    int GetLength() const;
    bool isEmpty() const;
    void Clear();

    template<class B>
    void Traverse(B visit) const;

    bool GetElem(int position,A& a) const;
    bool SetElem(int position,const A& a);
    bool Delete(int position);
    bool Insert(int position,const A& a);

    SimpleLinkList(const SimpleLinkList<A>& source);
    SimpleLinkList<A>& operator=(const SimpleLinkList<A>& source);
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
Node<A>* SimpleLinkList<A>::GetPoint(int position) const
{
    Node<A>* temp=head;
    int temPos=0;
    while(temp!=NULL&&temPos<position)
    {
        temp=temp->next;
        temPos++;
    }
    if(temp!=NULL&&temPos==position)
    {
        return temp;
    }
    else
    {
        return NULL;
    }
}

template<class A>
SimpleLinkList<A>::SimpleLinkList()
{
    head=new Node<A>;
}

template<class A>
SimpleLinkList<A>::~SimpleLinkList()
{
    Clear();
    delete head;
}

template<class A>
int SimpleLinkList<A>::GetLength() const
{
    int count=0;
    for(Node<A>* temp=head->next;temp!=NULL;temp=temp->next)
    {
        count++;
    }
    return count;
}

template<class A>
bool SimpleLinkList<A>::isEmpty() const
{
    return head->next==NULL;
}

template<class A>
void SimpleLinkList<A>::Clear()
{
    Node<A>* temp = head->next;
    while (temp != NULL) 
    {
        Node<A>* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    head->next = NULL;
}

template<class A>
template<class B>
void SimpleLinkList<A>::Traverse(B visit) const
{
    for(Node<A>* temp=head->next;temp!=NULL;temp=temp->next)
    {
        visit(temp->data);
    }
}

template<class A>
bool SimpleLinkList<A>::GetElem(int position,A& a)const
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
bool SimpleLinkList<A>::SetElem(int position,const A& a)
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
bool SimpleLinkList<A>::Delete(int position)
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
bool SimpleLinkList<A>::Insert(int position,const A& a)
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
SimpleLinkList<A>::SimpleLinkList(const SimpleLinkList<A>& source)
{
    head=new Node<A>;

    Node<A>* begin=source.head->next;
    Node<A>* end=head;
    while(begin!=NULL)
    {
        Node<A>* temp=new Node<A>;
        temp->data=begin->data;
        temp->next=NULL;
        end->next=temp;
        end=temp;
        begin=begin->next;
    }
}

template<class A>
SimpleLinkList<A>& SimpleLinkList<A>::operator=(const SimpleLinkList<A>& source)
{
    if(this!=&source)
    {
        Clear();
        Node<A>* begin=source.head->next;
        Node<A>* end=head;
        while(begin!=NULL)
        {
        Node<A>* temp=new Node<A>;
        temp->data=begin->data;
        temp->next=NULL;
        end->next=temp;
        end=temp;
        begin=begin->next;
        }
    }
    return *this;
}