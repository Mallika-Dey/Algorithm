#include<bits/stdc++.h>
using namespace std;
const int m=4;
//need to verify

class Node
{
public:
    int totalKeys;
    int keys[m-1];
    Node* child[m];
    bool isleaf;
    Node()
    {
        totalKeys=0;
        isleaf=false;
    }
    int insert(int key);
    int addKeys(int val);
    Node* splitNode(Node* nd, int *midValue);
    void addKeyChild(Node* right, int midValue);
};

class BTree
{
    Node *root;

public:
    BTree()
    {
        root=nullptr;
    }
    Node* getRoot() {
        return this->root;
    }
    void add(int val);
};

void BTree::add(int val)
{
    if(root==nullptr)
    {
        this->root=new Node();
        this->root->isleaf=true;
        this->root->keys[0]=val;
        this->root->totalKeys=1;
        return;
    }
    if(this->root->isleaf && this->root->totalKeys<m-1)
    {
        this->root->addKeys(val);
    }
    else
    {
        int split=root->insert(val);
        if(split)
        {
            int midValue;
            Node* newRoot=new Node();
            Node* newNode=root->splitNode(root, &midValue);
            newRoot->child[0]=root;
            newRoot->addKeyChild(newNode, midValue);
            this->root=newRoot;
        }
    }

}

int Node::insert(int val)
{
    if(this->isleaf)//need to check if full later
    {
        this->addKeys(val);
    }
    else
    {
        //find the position to add key
        int i;
        for(i=this->totalKeys-1; i>-1; i--)
        {
            if(val>this->keys[i])break;
        }
        int split=this->child[i+1]->insert(val);
        if(split)
        {
            int midValue;
            Node* newNode=this->splitNode(this->child[i+1], &midValue);
            this->addKeyChild(newNode, midValue);
        }
    }
    return (this->totalKeys>m-1) ? 1:0; //need to split or not
}

Node* Node::splitNode(Node* nd, int *midValue)
{
    Node* right=new Node();
    int mid=m/2;
    *midValue=nd->keys[mid];

    for(int j=mid+1; j<m; j++)
    {
        right->child[right->totalKeys++]=nd->child[j];
        right->keys[right->totalKeys]=nd->keys[j];
        nd->child[j]=nullptr;
        nd->totalKeys--;
    }
    right->isleaf=nd->isleaf;
    return right;
}

int Node::addKeys(int val)
{
    int i;
    for(i=this->totalKeys-1; i>-1; i--)
    {
        if(this->keys[i]>val)this->keys[i+1]=this->keys[i];
        else break;
    }
    this->keys[i+1]=val;
    this->totalKeys++;
    return i+1;
}

void Node::addKeyChild(Node* right, int midValue)
{
    for(int i=this->totalKeys-1; i>-1; i--)
    {
        if(midValue>this->keys[i])
        {
            this->keys[i+1]=midValue;
            this->child[i+2]=right;
            this->totalKeys++;
            return;
        }
        else
        {
            this->keys[i+1]=this->keys[i];
            this->child[i+2]=this->child[i+1];
        }
    }
    this->keys[0]=midValue;
    this->child[1]=right;
    this->totalKeys++;
}

int main()
{
    BTree bTree=BTree();
    bTree.add(2);
    bTree.add(1);
    bTree.add(4);
    bTree.add(-1);

    return 0;
}

