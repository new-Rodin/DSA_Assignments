#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
typedef node* nodeptr;
nodeptr insert(nodeptr root,int value)
{
    if(root == NULL){
        nodeptr q = new node();
        q->data = value;
        q->left = q->right = NULL;
    return q;
    }
    else if(value < root->data)
    root->left = insert(root->left,value);
    else
    root->right = insert(root->right,value);

    return root;
}
void postorder(nodeptr tree)
{
    nodeptr root = tree;
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<"  ";
    }
}
void inorder(nodeptr tree)
{
    nodeptr root = tree;
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<"  ";
        inorder(root->right);
    }
}

bool searchtree(nodeptr tree, int value){
    nodeptr root = tree;
    if(root == NULL)
    return false;
    else if(root->data == value)
    return true;
    else if(value < root->data)
    return searchtree(root->left,value);
    else
    return searchtree(root->right,value);
}
int main() {
    nodeptr root = NULL;
    int n, value; 

    cout << "Enter number of nodes: ";
    cin >> n;                

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "Postorder traversal: ";
    postorder(root);
    cout<<endl;
    cout<< "Inorder Traversal: ";
    inorder(root);
    cout<<endl;

    cout<<"Enter the value that you want to search:"<<endl;
    int key;
    cin>>key;
    if(searchtree(root,key))
    cout<<"Value is present in the tree."<<endl;
    else
    cout<<"Value is not present in the tree."<<endl;
    return 0;
}