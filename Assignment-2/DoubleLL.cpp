// This is for the Double Linked List implementation with all the operations like insertion, deletion, searching and displaying the list
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
    list->next = q; // This line is also very important as it connects the Linked list to the new freshly made pointer
    q->info = x;
    q-> next = NULL;
    q-> prev = list; // This is important to connect the previous pointer of the new node to the last node
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
    if(list==NULL)
    return NULL;
    NODEPTR rev = new node();
    NODEPTR temp = new node();
    NODEPTR nextptr;
    NODEPTR p = list;
    while(p->next!=NULL) // To get the last node
    {
        p=p->next;
    }
    temp = p;
    rev = temp;
    while(p->prev!=NULL) //Untill we get to the first node
    {
        nextptr = new node();
        nextptr = p->prev;
        temp->next = nextptr;
        nextptr ->prev = temp;
        nextptr ->next = NULL;
        temp = temp -> next;
        p = p->prev;
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
    NODEPTR list = new node();
    NODEPTR p = new node(); // Initialization of p is important
    list = p;               // Attaching the list pointer to the first node

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

    cout << "The List is:" << endl;
    display(list);
    NODEPTR reversed_list = reverse(list);
    cout<<"The Reversed list is:"<<endl;
    display(reversed_list);
}