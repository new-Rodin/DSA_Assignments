// Example: Browser session history using a Doubly Linked List
#include <iostream>
#include <string>
using namespace std;

struct node{
    string info; // Using string for the URL
    node* next;
    node* prev;
};
typedef struct node* NODEPTR;

// This function simulates visiting a new page
void visitPage(NODEPTR &currentPage, string url) {
    NODEPTR newPage = new node();
    newPage->info = url;
    newPage->next = NULL; // There's no "forward" page from a new one
    newPage->prev = currentPage;

    if (currentPage != NULL) {
        currentPage->next = newPage;
    }
    currentPage = newPage; // The new page is now the current one
}

void displayCurrentPage(NODEPTR currentPage) {
    if (currentPage == NULL) {
        cout << "Browser is on a blank page." << endl;
    } else {
        cout << "Currently on: " << currentPage->info << endl;
    }

    // Show status of back/forward buttons
    cout << " [Back button: " << (currentPage != NULL && currentPage->prev != NULL ? "Enabled" : "Disabled") << "]";
    cout << " [Forward button: " << (currentPage != NULL && currentPage->next != NULL ? "Enabled" : "Disabled") << "]" << endl << endl;
}

int main()
{
    NODEPTR history = NULL; // This will be our current position in the history
    NODEPTR startPage = new node();
    startPage->info = "www.google.com";
    startPage->prev = NULL;
    startPage->next = NULL;
    history = startPage; // Start on the home page

    // Simulating a browsing session
    visitPage(history, "www.wikipedia.org/wiki/Linked_list");
    visitPage(history, "www.geeksforgeeks.org/data-structures/");

    int choice = 0;
    while(choice != 4) {
        displayCurrentPage(history);
        cout << "Choose an action:" << endl;
        cout << "1. Go Back" << endl;
        cout << "2. Go Forward" << endl;
        cout << "3. Visit New Page" << endl;
        cout << "4. Close Browser" << endl;
        cin >> choice;

        if(choice == 1) { // Go Back
            if (history != NULL && history->prev != NULL) {
                history = history->prev;
            } else {
                cout << "Cannot go back further." << endl;
            }
        } else if (choice == 2) { // Go Forward
            if (history != NULL && history->next != NULL) {
                history = history->next;
            } else {
                cout << "Cannot go forward further." << endl;
            }
        } else if (choice == 3) {
            cout << "Enter new URL to visit: ";
            string newUrl;
            cin >> newUrl;
            visitPage(history, newUrl);
        }
    }
    cout << "Browser closed." << endl;
    return 0;
}