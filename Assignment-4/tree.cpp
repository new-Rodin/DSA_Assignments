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
void preorder(nodeptr tree)
{
    nodeptr root = tree;
    if(root!=NULL)
    {
        cout<<root->data<<"  ";
        preorder(root->left);
        preorder(root->right);
    }
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
    cout << "preorder traversal: ";
    preorder(root);
    cout<<endl;
    return 0;
}