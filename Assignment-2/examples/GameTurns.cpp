// Example: Managing player turns in a game using a Circular Linked List
#include <iostream>
#include <string>
using namespace std;

struct node{
    string info; // Using string for Player Name
    node* next;
};
typedef struct node* NODEPTR;

// Function to add a player to the game
void addPlayer(NODEPTR &list, string name) {
    NODEPTR newPlayer = new node();
    newPlayer->info = name;

    if (list == NULL) { // If this is the first player
        list = newPlayer;
        newPlayer->next = list; // The first player points to themselves
    } else {
        NODEPTR p = list;
        while (p->next != list) { // Find the last player in the circle
            p = p->next;
        }
        p->next = newPlayer; // The last player now points to the new player
        newPlayer->next = list; // The new player points back to the first player
    }
}

void displayWhoseTurn(NODEPTR currentPlayer) {
    if (currentPlayer == NULL) {
        cout << "No players in the game." << endl;
    } else {
        cout << "It's " << currentPlayer->info << "'s turn." << endl;
    }
}

int main()
{
    NODEPTR game = NULL; // The list of players in the game
    NODEPTR currentPlayer = NULL;

    // Adding players to the game
    addPlayer(game, "Alice");
    addPlayer(game, "Bob");
    addPlayer(game, "Charlie");
    addPlayer(game, "David");

    currentPlayer = game; // The first player to be added starts the game

    cout << "--- The Game Begins! ---" << endl;
    int turnsToSimulate = 10;
    for(int i = 1; i <= turnsToSimulate; i++)
    {
        cout << "\n--- Turn " << i << " ---" << endl;
        displayWhoseTurn(currentPlayer);
        cout << currentPlayer->info << " takes their turn." << endl;

        // Move to the next player for the next turn
        currentPlayer = currentPlayer->next;

        cout << "Press Enter for the next turn...";
        // cin.ignore() is used to clear buffer before cin.get()
        if(i == 1) cin.ignore();
        cin.get();
    }

    cout << "\nGame Over!" << endl;
    return 0;
}