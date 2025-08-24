// Example: A simple music playlist using a Singly Linked List
#include <iostream>
#include <string> // Using string for song titles
using namespace std;

struct node
{
    string info; // Using string for the song title
    node *next;
};

typedef struct node *NODEPTR;

// A simplified insert function to add a song to the end of the playlist
void addSong(NODEPTR &list, string title)
{
    NODEPTR q = new node();
    q->info = title;
    q->next = NULL;

    if (list == NULL)
    {
        list = q; // If the playlist is empty, this is the first song
    }
    else
    {
        NODEPTR p = list;
        while (p->next != NULL) // Go to the last song
        {
            p = p->next;
        }
        p->next = q; // Add the new song at the end
    }
}

void displayPlaylist(NODEPTR list)
{
    NODEPTR q = list; // This is important so that we dont lose the head pointer
    if(q == NULL) {
        cout << "Playlist is empty." << endl;
        return;
    }
    cout << "Playlist:" << endl;
    int track = 1;
    while (q != NULL)
    {
        cout << track << ". " << (q->info) << endl; // Displaying the song
        q = q->next;
        track++;
    }
    cout << endl;
}

int main()
{
    NODEPTR playlist = NULL; // The list starts empty
    NODEPTR currentSong = NULL;

    // Adding some songs to our playlist
    addSong(playlist, "Bohemian Rhapsody - Queen");
    addSong(playlist, "Stairway to Heaven - Led Zeppelin");
    addSong(playlist, "Hotel California - Eagles");
    addSong(playlist, "Like a Rolling Stone - Bob Dylan");

    currentSong = playlist;
    cout << "--- Music Playlist ---" << endl;
    displayPlaylist(playlist);

    // Let's simulate playing the playlist
    cout << "--- Now Playing ---" << endl;
    while(currentSong != NULL)
    {
        cout << "Playing: " << currentSong->info << endl;
        cout << "Press Enter to play next song...";
        cin.get(); // Wait for user to press Enter
        currentSong = currentSong->next; // Move to the next song
    }
    cout << "\nEnd of playlist." << endl;

    return 0;
}