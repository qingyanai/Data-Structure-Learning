#pragma once
#include <iostream>

template<class A>
struct DblNode
{
    A data;
    DblNode<A>* back;
    DblNode<A>* next;

    DblNode();
    DblNode(const A& a,DblNode<A>* linkback,DblNode<A>* linknext);
};

template<class A>
class SimpleDblLinkList
{
    protected:
    DblNode<A>* head;

    DblNode<A>* GetPoint(int position) const;

    public:
    SimpleDblLinkList();
    ~SimpleDblLinkList();
    int GetLength() const;
    bool isEmpty() const;
    void Clear();

    template<class B>
    void Traverse(B visit) const;

    bool GetElem(int position,A& a) const;
    bool SetElem(int position,const A& a);
    bool Delete(int position);
    bool Insert(int position,const A& a);

    SimpleDblLinkList(const SimpleDblLinkList<A>& source);
    SimpleDblLinkList<A>& operator=(const SimpleDblLinkList<A>& source);
};

template<class A>
DblNode<A>::DblNode()
{
    back=next=NULL;
}

template<class A>
DblNode<A>::DblNode(const A& a,DblNode<A>* linkback,DblNode<A>* linknext)
{
    data=a;
    back=linkback;
    next=linknext;
}

template<class A>
DblNode<A>* SimpleDblLinkList<A>::GetPoint(int position) const
{
    DblNode<A>* temp=head;
    int temPos=0;
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
        return head;
    }
}

template<class A>
SimpleDblLinkList<A>::SimpleDblLinkList()
{
    head=new DblNode<A>;
    head->back=head;
    head->next=head;
}

template<class A>
SimpleDblLinkList<A>::~SimpleDblLinkList()
{
    Clear();
    delete head;
}

template<class A>
int SimpleDblLinkList<A>::GetLength() const
{
    int count=0;
    for(DblNode<A>* temp=head->next;temp!=head;temp=temp->next)
    {
        count++;
    }
    return count;
}

template<class A>
bool SimpleDblLinkList<A>::isEmpty() const
{
    return (head->next==head&&head->back==head);
}

template<class A>
void SimpleDblLinkList<A>::Clear()
{
    DblNode<A>* temp=head->next;
    while(temp!=head)
    {
        DblNode<A>* toDelete=temp;
        temp=temp->next;
        delete toDelete;
    }
    head->next=head;
    head->back=head;
}

template<class A>
template<class B>
void SimpleDblLinkList<A>::Traverse(B visit) const
{
    for(DblNode<A>* temp=head->next;temp!=head;temp=temp->next)
    {
        visit(temp->data);
    }
}

template<class A>
bool SimpleDblLinkList<A>::GetElem(int position,A& a) const
{
    if(position<1||position>GetLength())
    {
        return false;
    }
    else
    {
        DblNode<A>* temp=GetPoint(position);
        a=temp->data;
        return true;
    }
}

template<class A>
bool SimpleDblLinkList<A>::SetElem(int position,const A& a)
{
    if(position<1||position>GetLength())
    {
        return false;
    }
    else
    {
        DblNode<A>* temp=GetPoint(position);
        temp->data=a;
        return true;
    }
}

template<class A>
bool SimpleDblLinkList<A>::Delete(int position)
{
    if(position<1||position>GetLength())
    {
        return false;
    }
    else
    {
        DblNode<A>* temp=GetPoint(position);
        temp->back->next=temp->next;
        temp->next->back=temp->back;
        delete temp;
        return true;
    }
}

template<class A>
bool SimpleDblLinkList<A>::Insert(int position,const A& a)
{
    if(position<1||position>GetLength()+1)
    {
        return false;
    }
    else
    {
        DblNode<A>* temp1=GetPoint(position-1);
        DblNode<A>* temp2=temp1->next;
        DblNode<A>* temp3=new DblNode<A>(a,temp1,temp2);
        temp1->next=temp3;
        temp2->back=temp3;
        return true;
    }
}

template<class A>
SimpleDblLinkList<A>::SimpleDblLinkList(const SimpleDblLinkList<A>& source)
{
    head=new DblNode<A>;
    head->next = head;
    head->back = head;

    DblNode<A>* tail=head;
    DblNode<A>* srcCur=source.head->next;
    while(srcCur!=source.head)
    {
        DblNode<A>* temp=new DblNode<A>;
        temp->data=srcCur->data;
        temp->next=head;
        temp->back=tail;
        tail->next=temp;
        tail=temp;
        srcCur=srcCur->next;
    }
    head->back = tail;
}

template<class A>
SimpleDblLinkList<A>& SimpleDblLinkList<A>::operator=(const SimpleDblLinkList<A>& source)
{
    if(this!=&source)
    {
        Clear();
        head->next = head;
        head->back = head;

        DblNode<A>* tail=head;
        DblNode<A>* srcCur=source.head->next;
        while(srcCur!=source.head)
        {
           DblNode<A>* temp=new DblNode<A>;
           temp->data=srcCur->data;
           temp->next=head;
           temp->back=tail;
           tail->next=temp;
           tail=temp;
           srcCur=srcCur->next;
        }
        head->back = tail;
    }
    return *this;
}