#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string song;
    Node* next;

    Node(string s) {
        song = s;
        next = nullptr;
    }
};

class Playlist {
    Node* head;

public:
    Playlist() { head = nullptr; }

    void addSong(string song) {
        Node* nn = new Node(song);
        if (head == nullptr) {
            head = nn;
            head->next = head;
        } else {
            nn->next = head->next;
            head->next = nn;
            head = nn;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }
        Node* temp = head->next;
        do {
            cout << temp->song << " -> ";
            temp = temp->next;
        } while (temp != head->next);
        cout << "(back to start)\n";
    }

    void deleteSong(string song) {
        if (head == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }

        Node* current = head->next;
        Node* prev = head;
        do {
            if (current->song == song) {
                if (current == head && current == head->next) {
                    delete current;
                    head = nullptr;
                } else {
                    prev->next = current->next;
                    if (current == head)
                        head = prev;
                    if (current == head->next)
                        head->next = current->next;
                    delete current;
                }
                cout << song << " removed from playlist.\n";
                return;
            }
            prev = current;
            current = current->next;
        } while (current != head->next);

        cout << song << " not found in playlist.\n";
    }

    void play(int count) {
        if (head == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }
        Node* current = head->next;
        for (int i = 0; i < count; i++) {
            cout << "Now Playing: " << current->song << endl;
            current = current->next;
        }
    }
};

int main() {
    Playlist pl;
    pl.addSong("Song A");
    pl.addSong("Song B");
    pl.addSong("Song C");
    pl.addSong("Song D");

    pl.display();
    pl.deleteSong("Song B");
    pl.display();
    pl.play(6);
}
