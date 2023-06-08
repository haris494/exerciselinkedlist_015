#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int rollNumber; //
    string name; // untuk menampung suatu kalimat
    Node* next; //
};

class CircularLinkedList {
private:
    Node* LAST; 

public:
    CircularLinkedList() {
        LAST = NULL;
    }

    void addNode();
    bool search(int rollno, Node** previous, Node** current);
    bool listEmpty();
    bool delNode();
    void traverse();
};

void CircularLinkedList::addNode() {
    int rollNumber;
    string name;

    cout << "\nEnter roll number: ";
    cin >> rollNumber;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);

    Node* newnode = new Node();
    newnode->rollNumber = rollNumber;
    newnode->name = name;

    if (listEmpty()) {
        LAST = newnode;
        newnode->next = newnode; 
    }
    else if (newnode->rollNumber < LAST->next->rollNumber) {
        newnode->next = LAST->next;
        LAST->next = newnode;
    }
    else {
        Node* current = LAST->next;
        Node* previous = NULL;

        while (current != LAST && current->rollNumber < newnode->rollNumber) {
            previous = current;
            current = current->next;
        }

        previous->next = newnode;
        newnode->next = current;
    }

    cout << "Record added successfully." << endl;
}

bool CircularLinkedList::search(int rollno, Node** previous, Node** current) {
    *previous = LAST->next;
    *current = LAST->next;

    while (*current != LAST) {
        if (rollno == (*current)->rollNumber) {
            return true;
        }

        *previous = *current;
        *current = (*current)->next;
    }

    if (rollno == LAST->rollNumber) {
        return true;
    }
    else {
        return false;
    }
}

bool CircularLinkedList::listEmpty() {
    return LAST == NULL;
}

bool CircularLinkedList::delNode() {
    if (listEmpty()) { 
        cout << "List is empty." << endl;
        return false;
    }

    int rollNumber;
    cout << "Enter the roll number to delete: ";
    cin >> rollNumber;

    Node* previous = NULL;
    Node* current = NULL;
    bool found = search(rollNumber, &previous, &current);

    if (!found) {
        cout << "Record not found." << endl;
        return false;
    }

    if (current == LAST) {
        LAST = previous;
    }

    if (current == LAST->next) {
        LAST->next = current->next;
    }
    else {
        previous->next = current->next;
    }

    delete current;
    cout << "Record deleted successfully." << endl;
    return true;
}

void CircularLinkedList::traverse() {
    if (listEmpty()) {
        cout << "List is empty." << endl;
    }
    else {
        cout << "Records in the list are:" << endl;
        Node* currentNode = LAST->next;

        while (currentNode != LAST) {
            cout << currentNode->rollNumber << " " << currentNode->name << endl;
            currentNode = currentNode->next;
        }

        cout << LAST->rollNumber << " " << LAST->name << endl;
    }
}

int main() {
    CircularLinkedList obj;// Baris ini membuat objek dari kelas 
    string firstName = "Haris";// Ini menunjukkan bahwa kode tersebut menggunakan variabel string untuk menyimpan nama pertama.
    string lastName = "shihab";//  Ini menunjukkan bahwa kode tersebut menggunakan variabel string untuk menyimpan nama keluarga atau nama terakhir.


    