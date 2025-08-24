// This is for the Circular Linked List implementation with all the operations like insertion, deletion, searching, reversal and displaying the list
#include<iostream>
using namespace std;
struct node{
    int info;
    node* next;
};
typedef struct node* NODEPTR;

void insertatend(NODEPTR p,int x )
{
    NODEPTR q = new node();
    p->next = q; // This line is very important as it connects the Linked list to the new freshly made pointer
    q->info = x;
    q->next = NULL; // This will be connected back to the head in the main function later
}

void insertafter(NODEPTR p,int x)
{
    NODEPTR q = new node();
    q->info = x;
    q->next = p->next;
    p->next = q;
}

void deletenode(NODEPTR &list, int value) // list is passed by reference to handle deletion of the head node
{
    if(list==NULL){
        cout<<"The list is empty"<<endl;
        return;
    }

    NODEPTR p = list;
    NODEPTR q = NULL; // q is the previous node

    // Find the node to be deleted and its previous node
    do{
        if(p->info == value)
        {
            break;
        }
        q = p;
        p = p->next;
    } while(p != list);

    if(p->info != value) // Element is not present at all in the list
    {
        cout<<"No such value is found in the list"<<endl;
        return;
    }

    // If the node is the only node in the list
    if(p->next == list && q == NULL)
    {
        list = NULL;
        delete p;
        return;
    }

    // If p is the head of the list
    if(p == list)
    {
        q = list; // Start q from the beginning to find the last node
        while(q->next != list) // Traverse to the last node
        {
            q = q->next;
        }
        list = p->next; // Move head to the next node
        q->next = list; // Update the last node's next to the new head
        delete p;
    }
    else // If the node is in the middle or at the end
    {
        q->next = p->next; // q is the previous node, so link it to the node after p
        delete p;
    }
}


int search(NODEPTR list,int value)
{
    if (list == NULL) return -1;
    NODEPTR p = list;
    int index = 0;
    do
    {
        if(p->info==value)
            return index;
        p=p->next;
        index++;
    } while(p != list);

    return -1; // Return -1 if the value is not found after checking the whole list
}

NODEPTR nodeat(NODEPTR list, int index) // Return the node at the i-th index
{
    if(list == NULL) return NULL;
    NODEPTR p = list;
    int i = 0;
    do
    {
        if (i == index)
            return p; // If the index is found, return the node
        p = p->next;
        i++;
    } while (p != list);

    return NULL; // If the index is not found after a full circle
}

NODEPTR reverse(NODEPTR list)
{
    if(list == NULL) return NULL;

    NODEPTR q = list;
    NODEPTR rev = NULL; // rev is the head pointer of the reversed list
    do
    {
        NODEPTR temp = new node();
        temp->info = q->info;
        temp->next = rev; // Inserting each node at the beginning of the 'rev' list
        rev = temp;
        q = q->next;
    } while (q != list);

    // Now rev is a reversed singly linked list, we need to make it circular
    NODEPTR p = rev;
    while(p->next != NULL) // Find the last node of the new reversed list
    {
        p=p->next;
    }
    p->next = rev; // Connect the last node back to the new head
    return rev;
}

void display(NODEPTR list)
{
    if(list == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    NODEPTR q = list; // This is important so that we dont lose the head pointer
    do
    {
        cout << (q->info) << " "; // Displaying the value of the node
        q = q->next;
    } while (q != list); // Loop until we circle back to the start
    cout << endl; // Giving a line break after displaying the list
}

int main()
{
    cout << "Enter a series of Numbers, Enter -1 to stop" << endl;
    int a;
    NODEPTR list;
    NODEPTR p = new node(); // Initialization of p is important, it acts as a dummy head
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

    list = list->next; // This is important as the first pointer does not contain any numerical value.
    if(list != NULL)
    {
        p->next = list; // p is the last node, connect it back to the head to make it circular
    }

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