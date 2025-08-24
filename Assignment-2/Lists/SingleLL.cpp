// This is a single linked list implementation with all the operations like insertion, deletion, searching,reverse and displaying the list
#include <iostream>
using namespace std;
struct node
{
    int info;
    node *next;
};

typedef struct node *NODEPTR;

void insertatend(NODEPTR list, int x)
{
    NODEPTR q = new node();
    list->next = q; // This line is also very important as it connects the Linked list to the new freshly made pointer
    q->info = x;
    q->next = NULL;
}

void insertafter(NODEPTR p, int x)
{
    NODEPTR q = new node();
    q->info = x;
    q->next = p->next;
    p->next = q;
}

void deletenode(NODEPTR list, int value)
{
    NODEPTR p = list;
    if (p == NULL) // If the list is empty
    {
        cout << "List is empty" << endl;
        return;
    }
    NODEPTR q = new node();
    q = NULL; // q is the previous node, it is initialized to NULL so that we can check if the value is the first node or not
    while (p != NULL && p->info != value)
    {
        q = p; // q is the previous node
        p = p->next;
    }
    if (p == NULL) // If the value is not found
    {
        cout << "Value not found in the list" << endl;
        return;
    }
    else if (p->next == NULL) // If the value is the last node
    {
        q->next = NULL;
        delete p; // Freeing the memory of the deleted node
        return;   // We return here as we have deleted the last node
    }
    else if (q == NULL)
    {
        list = p->next; // We need to update the head pointer to the next node
        delete p;       // If the value is the first node, we just delete it
        return;         // We return here as we have deleted the first node
    }
    else // If the value is found and it is not the last node or the first node
    {
        q->next = p->next; // Connecting the previous node to the next node
        delete p;          // Freeing the memory of the deleted node
    }
}

int search(NODEPTR list, int value)
{
    NODEPTR p = new node();
    int index = 0; // This is to keep track of the index of the value
    p = list;
    while (p != NULL)
    {
        if (p->info == value)
            return index; // If the value is found, return the index
        else
        {
            p = p->next;
            index++;
        }
    }
    return -1; // If the value is not found, return -1
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
    NODEPTR q = new node();
    NODEPTR rev = new node();
    q = list;
    rev = NULL; // rev is the head pointer of the reversed list
    while (q != NULL)
    {
        NODEPTR temp = new node();
        temp->info = q->info;
        temp->next = rev;
        rev = temp;
        q = q->next;
    }
    return rev; // Returning the head pointer of the reversed list   
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

    cout << "What actions do you want to perform?" << endl << "Enter 1 for deletion , 2 for inserting a node after a particular index, 3 for searching the list , 4 to know the value of a node at index i, 5 to get the reverse of th elist" << endl;
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
    else if( choice == 5)
    {
        NODEPTR rev = reverse(list);
        cout << "The reversed list is:" << endl;
        display(rev);
    }   
    else
    {
        cout << "Invalid choice" << endl;
    }
}