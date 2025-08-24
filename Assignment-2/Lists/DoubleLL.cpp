// This is for the Double Linked List implementation with all the operations like insertion, deletion, searching,reversal and displaying the list
#include<iostream>
using namespace std;
struct node{
    int info;
    node* next;
    node* prev;
}; 
typedef struct node* NODEPTR;
void insertatend(NODEPTR list ,int x )
{
    NODEPTR q = new node();
    list->next = q; // This line is very important as it connects the Linked list to the new freshly made pointer
    q->info = x;
    q-> next = NULL;
    q-> prev = list; // This is also important to connect the previous pointer of the new node to the last node
    
}
void insertafter(NODEPTR p,int x)
{
    NODEPTR q = new node();
    if(p->next == NULL) // If the insertion is taking place after the last node
    {
        q->info =x;
        q->prev =p;
        q->next=NULL;
        p->next = q;
    }
    else{
    NODEPTR t = p->next;
    q->info = x;
    q->next = t;
    t->prev = q;
    p->next = q;
    q->prev = p;
    }
}
void insertbefore(NODEPTR p,int x)
{
    NODEPTR q = new node();
    if(p->prev == NULL) // If the insertion is taking place after the first node
    {
        q->info =x;
        q->next =p;
        q->prev=NULL;
        p->prev = q;
    }
    else{
    NODEPTR t = p->prev;
    q->info = x;
    q->prev = t;
    t->next = q;
    p->prev = q;
    q->next = p;
    }
}
void deletenode(NODEPTR list, int value)
{
    NODEPTR p=list;
    NODEPTR temp = new node();
    NODEPTR nextptr = new node();
    if(list==NULL){
    cout<<"The list is empty"<<endl;
    return;
    }
    while(p!=NULL && p->info!=value)
    {
        p=p->next;
    }
    if(p==NULL) //Element is not present at all in the list
    {
        cout<<"No such value is found in the list"<<endl;
    }
    else if(p->prev == NULL) //p is the first element 
    {
        list = list->next;
        delete(p);
    }
    else if(p->next == NULL) // p is the last node
    {
        temp = p->prev;
        temp->next = NULL;
        delete(p);
    }
    else
    {
        temp = p->prev;
        nextptr = p->next;
        temp->next = nextptr;
        nextptr ->prev = temp;
        delete(p);
    }
}

int search(NODEPTR list,int value)
{
    NODEPTR p = list;
    int index = 0;
    while(p!=NULL)
    {
        if(p->info==value)
        return index;
        else 
        p=p->next;
    }
    return -1;
}

NODEPTR nodeat(NODEPTR list, int index) // Return the node at the i-th index
{
    NODEPTR p = new node();
    p = list;
    int i = 0; // This is to keep track of the index of the value
    while (p != NULL)
    {
        if (i == index)
            return p; // If the index is found, return the node
        else
        {
            p = p->next;
            i++;
        }
    }
    return NULL; // If the index is not found, return NULL
}

NODEPTR reverse(NODEPTR list)
{
    if(list==NULL)  return NULL;
    NODEPTR rev;
    NODEPTR temp = new node();
    NODEPTR nextptr;
    NODEPTR p = list;
    while(p->next!=NULL) // To get the last node
    {
        p=p->next;
    }
    temp->info = p->info;
    temp->prev = NULL;
    rev = temp;
    while(p->prev!=NULL) 
    {
        nextptr = new node();
        p = p->prev;
        nextptr->info = p->info;
        nextptr->prev = temp;
        temp->next = nextptr;
        temp = nextptr;
    }
    return rev;
}

void display(NODEPTR list)
{
    NODEPTR q = list; // This is important so that we dont lose the head pointer
    while (q != NULL)
    {
        cout << (q->info) << " "; // Displaying the value of the node
        q = q->next;
    }
    cout << endl; // Giving a line break after displaying the list
}

int main()
{
    cout << "Enter a series of Numbers, Enter -1 to stop" << endl;
    int a;
    NODEPTR list;
    NODEPTR p = new node(); // Initialization of p is important
    list = p; // Attaching the list pointer to the first node
    while (true)
    {
        cin >> a;
        if (a != -1)
        {
            insertatend(p, a);
            p = p->next; // Now p points to the freshly made pointer q
        }
        else
        {
            break;
        }
    }
    list = list->next; // This is important as the first pointer does not contain any numerical value and just containts the adress to the first pointer.
    list ->prev = NULL; // This is to make sure there's no void pointer at the beginning
    cout << "The List is:" << endl;
    display(list);

    cout << "What actions do you wish to perform?" << endl << "Enter 1 for deletion , 2 for inserting a node after a particular index, 3 for searching the list , 4 to know the value of a node at index i, 5 to reverse the list" << endl;
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter the value to be deleted" << endl;
        int del;
        cin >> del;
        deletenode(list, del);
        cout << "The List after deletion is:" << endl;
        display(list);
    }
    else if (choice == 2)
    {
        int index, ins;
        cout << "Enter the index after which you want to insert a new node" << endl;
        cin >> index;
        NODEPTR key = nodeat(list, index);
        if (key == NULL)
        {
            cout << "Index not found" << endl;
            return 0; // If the index is not found, we return
        }
        cout << "Enter the value to be inserted" << endl;
        cin >> ins;
        insertafter(key, ins);
        cout << "The List after insertion is:" << endl;
        display(list);
    }
    else if (choice == 3)
    {
        int value;
        cout << "Enter the value to be searched" << endl;
        cin >> value;
        int index = search(list, value);
        if (index == -1)
        {
            cout << "Value not found in the list" << endl;
        }
        else
        {
            cout << "Value found at index " << index << endl;
        }
    }
    else if (choice == 4)
    {
        int index;
        cout << "Enter the index of the node you want to know the value of" << endl;
        cin >> index;
        NODEPTR key = nodeat(list, index);
        cout << "The value at index " << index << " is ";
        if (key == NULL)
            cout << "not found" << endl; // If the index is not found, we return
        else
            cout << key->info << endl; // If the index is found, we print the value
    }
    else if(choice == 5)
    {
        NODEPTR rev = reverse(list);
        cout<<"The reversed list is:"<<endl;
        display(rev);
    }
    else
    {
        cout << "Invalid choice" << endl;
    }
}