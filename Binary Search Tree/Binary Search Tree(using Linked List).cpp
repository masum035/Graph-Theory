///in BST or binary tree,what is left of the key value is her predecessor & what is right of the key value is her successor
/*
auther: Abdullah Al Masum
*/
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key, level;
    Node *left, *right, *parent;
};


class BST
{
private:
    Node *root;

public:
    BST()
    {
        root = NULL;
    }

    Node* getRoot()
    {
        return root;
    }

private:
    void insertRoot(int val)
    {
        ///Creates a node in the bst as root
        root           = new Node;
        root -> key    = val;
        root -> left   = NULL;
        root -> right  = NULL;
        root -> parent = NULL;
    }

    void insertOther(int val)
    {
        ///Creates a node in the bst which is not root
        Node *temp1 = root;
        Node *prev  = NULL;

        while(temp1 != NULL)    //this while block is to set parent in prev node
        {
            prev = temp1;//prev giye temp-ke point korbe
            if(val < temp1->key)
            {
                temp1 = temp1->left;  //pointer equality
            }
            else    //boro/equal holee
            {
                temp1 = temp1->right;  //pointer equality
            }
        }
        Node* temp2   = new Node;
        temp2->key    = val;
        temp2->left   = NULL;
        temp2->right  = NULL;
        temp2->parent = prev;
        //notun node ta right-e jabe naki left-e jabe,now we will decide comparing with parent's value
        if(val < prev->key)
        {
            prev->left = temp2;
        }
        if(val >= prev->key)
        {
            prev->right = temp2;
        }
    }

public:
    void insert(int val)
    {
        ///Creates a node in the bst
        if(root == NULL)
        {
            insertRoot(val);
        }
        else
        {
            insertOther(val);
        }
    }

    Node* findNode(int val)
    {
        ///Returns the reference of a node in the bst that contains the parameter as key
        Node *temp = new Node;
        temp=root;
        while(temp !=NULL)
        {
            if(temp->key == val)
            {
                return temp;
            }
            else if(val< temp->key )
            {
                temp = temp->left;
            }
            else if(val > temp->key)
            {
                temp = temp->right;
            }
        }
        return temp;//ekhane NULL return korbe jodi value khuje na pai
    }

    Node* findMaximum(Node *node)
    {
        ///Returns the reference of the maximum node in the bst which contains the parameter as root
        //in BST , possible Higest value should be at rightmost
        Node *temp = node;
        while(temp->right != NULL)
        {
            temp = temp->right;
        }
        return temp;
    }

    Node* findMinimum(Node *node)
    {
        ///Returns the reference of the maximum node in the bst which contains the parameter as root
        //in BST , possible lowest value should be at leftmost
        Node *temp = node;
        while(temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }

    void dfs(Node *node)
    {
        ///Prints the in order traversal of a bst which contains the parameter as root
        //this is for sorting the BST
        if(node->left != NULL)
        {
            dfs(node->left);
        }
        cout<<node->key<<"  ";
        if(node->right != NULL)
        {
            dfs(node->right);
        }
    }

private:
    Node* findSuccessor(Node *node)
    {
        ///Returns the reference of the in order successor of the parameter in the bst
        return findMinimum(node->right);
    }

    void delete0Child(Node *node)
    {
        ///Removes the parameter from the bst if the parameter is a leaf node
        if(node==root)
        {
            root=NULL;
            delete node;
        }
        else
        {
            Node *prevNode = node->parent;
            if(prevNode->left == node)
            {
                prevNode->left = NULL;
            }
            else
            {
                prevNode->right = NULL;
            }
            delete node;
        }
    }

    void delete1Child(Node *node)
    {
        ///Removes the parameter from the bst if the parameter has only one child
        Node *childnode = new Node;
        if(node->left != NULL)
        {
            childnode = node->left;
        }
        else
        {
            childnode = node->right;
        }

        Node *previousnode = node->parent;
        if(previousnode->left == node)
        {
            previousnode->left = childnode;
        }
        else
        {
            previousnode->right = childnode;
        }

        delete node;
    }

    void delete2Child(Node *node)
    {
        ///Removes the parameter from the bst if the parameter has 2 children
        ///_____________First Way______________
        Node *newKing = findSuccessor(node);
        node->key = newKing->key;
        //here is the trick:new King-r left always empty thakbe,cuz the left side was the node we want to delete
        //cause we are finding inorder successor
        if(newKing->right == NULL)
            delete0Child(newKing);
        else
            delete1Child(newKing);


        ///_____________Second Way_______________
//        Node *newRuler = findMinimum(node->right);
//        node->key = newRuler->key;
//        if(newRuler->left == NULL && newRuler->right == NULL)
//            delete0Child(newRuler);
//        else
//            delete1Child(newRuler);

        ///_____________Third Way______________
//        Node *newRuler = findMaximum(node->left);
//        node->key = newRuler->key;
//        if(newRuler->left == NULL && newRuler->right == NULL)
//            delete0Child(newRuler);
//        else
//            delete1Child(newRuler);
    }

public:
    bool deleteNode(int val)
    {
        ///Removes a node containing the parameter from the bst
        ///Returns true in case of successful deletion, otherwise returns false
        Node *temp = findNode(val);
        if(temp == NULL)
        {
            return false;
        }
        else
        {
            if(temp->left == NULL && temp->right == NULL)
            {
                delete0Child(temp);
            }
            else if(temp->left != NULL && temp->right != NULL)
            {
                delete2Child(temp);
            }
            else
            {
                delete1Child(temp);
            }
            return true;
        }
    }

    int height(Node *node)//if we want the full height,then we have to pass here the root node
    {
        ///returns the height of the bst
        ///Must develop a recursive solution
        int leftHeight=0,rightHeight=0;
        if(node==NULL)
        {
            return 0;
        }
        else
        {
            leftHeight  = height(node->left);
            rightHeight = height(node->right);
            return max(leftHeight,rightHeight)+1;
        }
    }

    void bfs()
    {
        //this is for level order traversal for BST
        queue<Node*> q;
        root->level = 0;
        int level = root->level;
        q.push(root);

        while(!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if(temp->level > level)
            {
                cout<<endl;
                level++;//for the first iteration,it will zero,then it will increase
            }
            cout<<temp->key<<" ";
            if(temp->left != NULL)
            {
                if(temp->left != root)
                    temp->left->level = temp->level + 1;
                q.push(temp->left);
            }
            if(temp->right != NULL)
            {
                if(temp->right != root)
                    temp->right->level = temp->level + 1;
                q.push(temp->right);
            }
        }
    }
};


int main(){
    BST b;

    while(1){
        cout<<"1. Insert    2. Sort      3. Level Order    4. Minimum\n5. Maximum   6. Delete    7. Height         8. End\n\n";
        int x;
        cin>>x;

        if(x==1){
            cout<<"Insert Value: ";
            int y;
            cin>>y;
            b.insert(y);
            cout<<y<<" is inserted in the tree"<<endl;
        }

        else if(x==2){
            if(b.getRoot()==NULL){
                cout<<"Tree is empty"<<endl;
                continue;
            }
            cout<<"Sorted List of the tree: ";
            b.dfs(b.getRoot());
            cout<<endl;
        }

        else if(x==3){
            if(b.getRoot()==NULL){
                cout<<"Tree is empty"<<endl;
                continue;
            }
            cout<<"Level Wise Traversal of the tree:"<<endl;
            b.bfs();
            cout<<endl;
        }

        else if(x==4){
            if(b.getRoot()==NULL){
                cout<<"Tree is empty"<<endl;
                continue;
            }
            cout<<"Minimum of the tree: ";
            Node *min = b.findMinimum(b.getRoot());
            cout<<min->key<<endl;
        }

        else if(x==5){
            if(b.getRoot()==NULL){
                cout<<"Tree is empty"<<endl;
                continue;
            }
            cout<<"Maximum of the tree: ";
            Node *max = b.findMaximum(b.getRoot());
            cout<<max->key<<endl;
        }

        else if(x==6){
            if(b.getRoot()==NULL){
                cout<<"Tree is empty"<<endl;
                continue;
            }
            cout<<"Delete Value: ";
            int y;
            cin>>y;
            bool test = b.deleteNode(y);
            if(test)   cout<<y<<" is deleted from the tree"<<endl;
            else    cout<<y<<" is not found in the tree"<<endl;
        }
        else if(x==7){
            if(b.getRoot()==NULL){
                cout<<"Tree is empty"<<endl;
                continue;
            }
            cout<<"Height of the tree: "<<b.height(b.getRoot())-1<<endl;
        }
        else if(x==8){
                cout<<"program is terminated..."<<endl;
            break;
        }
        else{
            cout<<"Invalid Choice"<<endl;
        }
        cout<<endl;
    }
}

/*
1
44

1
17

1
88

1
32

1
65

1
97

1
28

1
54

1
82

1
29

1
76

1
80
*/
/*
after deleting 28,the level order will be:
44
17 88
32 65 97
29 54 82
76
80
*/
