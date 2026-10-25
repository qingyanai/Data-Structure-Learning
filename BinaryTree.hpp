#pragma once
#include <iostream>
#include "LinkQueue.hpp"

template<class A>
struct BinTreeNode
{
    A data;
    BinTreeNode<A>* leftChild;
    BinTreeNode<A>* rightChild;

    BinTreeNode();
    BinTreeNode(const A& a,BinTreeNode<A>* lChild,BinTreeNode<A>* rChild);
};

template<class A>
BinTreeNode<A>::BinTreeNode()
{
    leftChild=rightChild=nullptr;
}

template<class A>
BinTreeNode<A>::BinTreeNode(const A& a,BinTreeNode<A>* lChild,BinTreeNode<A>* rChild)
{
    data=a;
    leftChild=lChild;
    rightChild=rChild;
}

template<class A>
class BinaryTree
{
    protected:
    BinTreeNode<A>* root;

    BinTreeNode<A>* CopyTreeHelp(const BinTreeNode<A>* r);
    
    void DestroyHelp(BinTreeNode<A>* r);

    template<class B>
    void PreOrderHelp(const BinTreeNode<A>* r,B visit) const;

    template<class B>
    void InOrderHelp(const BinTreeNode<A>* r,B visit) const;

    template<class B>
    void PostOrderHelp(const BinTreeNode<A>* r,B visit) const;

    int HeightHelp(const BinTreeNode<A>* r) const;
    int NodeCountHelp(const BinTreeNode<A>* r) const;

    const BinTreeNode<A>* ParentHelp(const BinTreeNode<A>* r,const BinTreeNode<A>* cur) const;

    public:
    BinaryTree();
    ~BinaryTree();
    const BinTreeNode<A>* GetRoot() const;
    bool isEmpty() const;
    bool GetElem(const BinTreeNode<A>* cur,A& a) const;
    bool SetElem(BinTreeNode<A>* cur,const A& a);

    template<class B>
    void InOrder(B visit) const;

    template<class B>
    void PreOrder(B visit) const;

    template<class B>
    void PostOrder(B visit) const;

    template<class B>
    void LevelOrder(B visit) const;

    int NodeCount() const;

    const BinTreeNode<A>* LeftChild(const BinTreeNode<A>* cur) const;
    const BinTreeNode<A>* RightChild(const BinTreeNode<A>* cur) const;
    const BinTreeNode<A>* Parent(const BinTreeNode<A>* cur) const;

    void InsertLeftChild(BinTreeNode<A>* cur,const A& a);
    void InsertRightChild(BinTreeNode<A>* cur,const A& a);
    void DeleteLeftChild(BinTreeNode<A>* cur);
    void DeleteRightChild(BinTreeNode<A>* cur);

    int Height() const;

    BinaryTree(const A& a);
    BinaryTree(const BinaryTree<A>& source);
    BinaryTree(BinTreeNode<A>* r);
    BinaryTree<A>& operator=(const BinaryTree<A>& source);
};

template<class A>
BinTreeNode<A>* BinaryTree<A>::CopyTreeHelp(const BinTreeNode<A>* r)
{
    if(r==nullptr)
    {
        return nullptr;
    }
    else
    {
        BinTreeNode<A>* lChild=CopyTreeHelp(r->leftChild);
        BinTreeNode<A>* rChild=CopyTreeHelp(r->rightChild);
        BinTreeNode<A>* rt=new BinTreeNode<A>(r->data,lChild,rChild);
        return rt;
    }
}

template<class A>
void BinaryTree<A>::DestroyHelp(BinTreeNode<A>* r)
{
    if(r!=nullptr)
    {
        DestroyHelp(r->leftChild);
        DestroyHelp(r->rightChild);
        delete r;
    }
}

template<class A>
template<class B>
void BinaryTree<A>::PreOrderHelp(const BinTreeNode<A>* r,B visit) const
{
    if(r!=nullptr)
    {
        visit(r->data);
        PreOrderHelp(r->leftChild,visit);
        PreOrderHelp(r->rightChild,visit);
    }
}

template<class A>
template<class B>
void BinaryTree<A>::InOrderHelp(const BinTreeNode<A>* r,B visit) const
{
    if(r!=nullptr)
    {
        InOrderHelp(r->leftChild,visit);
        visit(r->data);
        InOrderHelp(r->rightChild,visit);
    }
}

template<class A>
template<class B>
void BinaryTree<A>::PostOrderHelp(const BinTreeNode<A>* r,B visit) const
{
    if(r!=nullptr)
    {
        PostOrderHelp(r->leftChild,visit);
        PostOrderHelp(r->rightChild,visit);
        visit(r->data);
    }
}

template<class A>
int BinaryTree<A>::HeightHelp(const BinTreeNode<A>* r) const
{
    if(r==nullptr)
    {
        return 0;
    }
    else
    {
        int lheight=HeightHelp(r->leftChild);
        int rheight=HeightHelp(r->rightChild);
        return (lheight>rheight?lheight:rheight)+1;
    }
}

template<class A>
int BinaryTree<A>::NodeCountHelp(const BinTreeNode<A>* r) const
{
    if(r==nullptr)
    {
        return 0;
    }
    else
    {
        return NodeCountHelp(r->leftChild)+NodeCountHelp(r->rightChild)+1;
    }
}

template<class A>
const BinTreeNode<A>* BinaryTree<A>::ParentHelp(const BinTreeNode<A>* r,const BinTreeNode<A>* cur) const
{
    if(r==nullptr||r==cur)
    {
        return nullptr;
    }
    if(r->leftChild==cur||r->rightChild==cur)
    {
        return r;
    }
    const BinTreeNode<A>* p=ParentHelp(r->leftChild,cur);
    if(p!=nullptr)
    {
        return p;
    }
    return ParentHelp(r->rightChild,cur);
}

template<class A>
BinaryTree<A>::BinaryTree()
{
    root=nullptr;
}

template<class A>
BinaryTree<A>::~BinaryTree()
{
    DestroyHelp(root);
}

template<class A>
const BinTreeNode<A>* BinaryTree<A>::GetRoot() const
{
    return root;
}

template<class A>
bool BinaryTree<A>::isEmpty() const
{
    return root==nullptr;
}

template<class A>
bool BinaryTree<A>::GetElem(const BinTreeNode<A>* cur,A& a) const
{
    if(cur==nullptr)
    {
        return false;
    }
    a=cur->data;
    return true;
}

template<class A>
bool BinaryTree<A>::SetElem(BinTreeNode<A>* cur,const A& a)
{
    if(cur==nullptr)
    {
        return false;
    }
    cur->data=a;
    return true;
}

template<class A>
template<class B>
void BinaryTree<A>::InOrder(B visit) const
{
    InOrderHelp(root,visit);
}

template<class A>
template<class B>
void BinaryTree<A>::PreOrder(B visit) const
{
    PreOrderHelp(root,visit);
}

template<class A>
template<class B>
void BinaryTree<A>::PostOrder(B visit) const
{
    PostOrderHelp(root,visit);
}

template<class A>
template<class B>
void BinaryTree<A>::LevelOrder(B visit) const
{
    LinkQueue<const BinTreeNode<A>*>q;
    const BinTreeNode<A>* cur;
    if(root!=nullptr)
    {
        q.InQueue(root);
    }
    while(!q.isEmpty())
    {
        q.OutQueue(cur);
        visit(cur->data);
        if(cur->leftChild!=nullptr)
        {
            q.InQueue(cur->leftChild);
        }
        if(cur->rightChild!=nullptr)
        {
            q.InQueue(cur->rightChild);
        }
    }
}

template<class A>
int BinaryTree<A>::NodeCount() const
{
    return NodeCountHelp(root);
}

template<class A>
const BinTreeNode<A>* BinaryTree<A>::LeftChild(const BinTreeNode<A>* cur) const
{
    if(cur==nullptr)
    {
        return nullptr;
    }
    return cur->leftChild;
}

template<class A>
const BinTreeNode<A>* BinaryTree<A>::RightChild(const BinTreeNode<A>* cur) const
{
    if(cur==nullptr)
    {
        return nullptr;
    }
    return cur->rightChild;
}

template<class A>
const BinTreeNode<A>* BinaryTree<A>::Parent(const BinTreeNode<A>* cur) const
{
    return ParentHelp(this->root,cur);
}

template<class A>
void BinaryTree<A>::InsertLeftChild(BinTreeNode<A>* cur,const A& a)
{
    if(cur==nullptr)
    {
        return;
    }
    DeleteLeftChild(cur);
    cur->leftChild=new BinTreeNode<A>(a,nullptr,nullptr);
}

template<class A>
void BinaryTree<A>::InsertRightChild(BinTreeNode<A>* cur,const A& a)
{
    if(cur==nullptr)
    {
        return;
    }
    DeleteRightChild(cur);
    cur->rightChild=new BinTreeNode<A>(a,nullptr,nullptr);
}

template<class A>
void BinaryTree<A>::DeleteLeftChild(BinTreeNode<A>* cur)
{
    if(cur==nullptr||cur->leftChild==nullptr)
    {
        return;
    }
    DestroyHelp(cur->leftChild);
    cur->leftChild=nullptr;
}

template<class A>
void BinaryTree<A>::DeleteRightChild(BinTreeNode<A>* cur)
{
    if(cur==nullptr||cur->rightChild==nullptr)
    {
        return;
    }
    DestroyHelp(cur->rightChild);
    cur->rightChild=nullptr;
}

template<class A>
int BinaryTree<A>::Height() const
{
    return HeightHelp(root);
}

template<class A>
BinaryTree<A>::BinaryTree(const A& a)
{
    root=new BinTreeNode<A>(a,nullptr,nullptr);
}

template<class A>
BinaryTree<A>::BinaryTree(const BinaryTree<A>& source)
{
    root=CopyTreeHelp(source.root);
}

template<class A>
BinaryTree<A>::BinaryTree(BinTreeNode<A>* r)
{
    root=r;
}

template<class A>
BinaryTree<A>& BinaryTree<A>::operator=(const BinaryTree<A>& source)
{
    if(&source!=this)
    {
        DestroyHelp(root);
        root=CopyTreeHelp(source.root);
    }
    return *this;
}