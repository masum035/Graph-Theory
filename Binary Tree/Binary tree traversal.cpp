/*
Auther: Abdullah Al Masum
*/
#include<bits/stdc++.h>
#define MAXX 50

using namespace std;
int N,vall;
char c;
vector<int> Array(MAXX);

char decode(int s)
{
    char val = 0;
    return val = s+97;
}
int encode(char s)
{
    int val;
    if(65<= s && s<=90)
    {
        return val = s-65;
    }
    if(97<= s && s<=122)
    {
        return val = s-97;
    }
}
void printResult(vector<int> Vec)
{
    for(int i=0; i<N+1; i++)
    {
        cout<<decode(Vec[i])<<" ";
    }
}

struct Node
{
    int key;
    Node *left,*right,*parent,*root=NULL;
};
Node *root = new Node;

void insertRoot(int val)
{
    root = new Node;
    root->key =val;
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;
}
Node* getRoot()
{
    return root;
}
void constructBinaryTree(int val)
{
    Node *temp = getRoot();
    Node *prev = NULL;
    while(temp != NULL)
    {
        prev = temp;
        if(val <= temp->key)
            temp = temp->left;
        else
            temp = temp->right;
    }
    Node *temp2 = new Node;
    temp2->key = val;
    temp2->left = NULL;
    temp2->right = NULL;
    temp2->parent = prev;
    if(val <= prev->key)
        prev->left = temp2;
    else
        prev->right = temp2;
}
void PreOrderTraversal(Node *temp)    ///nLR
{
    if(temp == NULL)
        return;
    cout<<decode(temp->key)<<" ";
    PreOrderTraversal(temp->left);
    PreOrderTraversal(temp->right);
}
void InOrderTraversal(Node *temp)    ///LnR
{
    if(temp == NULL)
        return;
    InOrderTraversal(temp->left);
    cout<<decode(temp->key)<<" ";
    InOrderTraversal(temp->right);

}
void PostOrderTraversal(Node *temp)    ///LRn
{
    if(temp == NULL)
        return;
    PostOrderTraversal(temp->left);
    PostOrderTraversal(temp->right);
    cout<<decode(temp->key)<<" ";
}
void LevelOrderTraversal(Node *temp)    ///BFS
{
    queue<Node*> Q;
    Q.push(temp);
    while(!Q.empty())
    {
       Node *node = Q.front();
       cout<<decode(node->key)<<" ";
       Q.pop();
       if(node->left != NULL)
            Q.push(node->left);
       if(node->right != NULL)
            Q.push(node->right);
    }

}

int main()
{
    cout<<"Insert Root : ";
    cin>>c;
    Array[0] = encode(c);
    insertRoot(encode(c));
    cout<<"Insert rest size of the array : ";
    cin>>N;
    Array.resize(N+1);
    cout<<"Enter the array : ";
    for(int i=1; i<N+1; i++)
    {
        cin>>c;
        vall = encode(c);
        Array[i] = vall;
        constructBinaryTree(vall);
    }
    cout<<endl<<"stored as array       :";
    printResult(Array); cout<<endl;
    cout<<"In-Order Traversal    :";
    InOrderTraversal(getRoot()); cout<<endl;
    cout<<"Pre-Order Traversal   :";
    PreOrderTraversal(getRoot()); cout<<endl;
    cout<<"Post-Order Traversal  :";
    PostOrderTraversal(getRoot()); cout<<endl;
    cout<<"Level-Order Traversal :";
    LevelOrderTraversal(getRoot());
    cout<<endl;

    return 0;
}
/*
H
12
P A S T Q E D X M R C F
*/
