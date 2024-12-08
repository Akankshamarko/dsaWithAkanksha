#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

Node* createNode(char data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

int getLength(Node* head) {
    int length = 0;
    Node* temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }
    return length;
}

void addAtBeg(Node** head, char data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void append(Node** head, char data) {
    Node* newNode = createNode(data);
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void addAtPOS(Node** head, char data, int pos) {
    if (pos == 0) {
        addAtBeg(head, data);
        return;
    }
    Node* newNode = createNode(data);
    Node* temp = *head;
    for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position out of bounds\n";
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void displayMORE(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "Address: " << temp << ", Value: " << temp->data << ", Next: " << temp->next << endl;
        temp = temp->next;
    }
}

void removeFirst(Node** head) {
    if (*head == nullptr) {
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    delete temp;
}

void removeLast(Node** head) {
    if (*head == nullptr) {
        return;
    }
    if ((*head)->next == nullptr) {
        delete *head;
        *head = nullptr;
        return;
    }
    Node* temp = *head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void removePOS(Node** head, int pos) {
    if (*head == nullptr) {
        return;
    }
    if (pos == 0) {
        removeFirst(head);
        return;
    }
    Node* temp = *head;
    for (int i = 0; i < pos - 1 && temp->next != nullptr; i++) {
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        cout << "Position out of bounds\n";
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}
int main() {
    Node* head = nullptr;

    append(&head, 'A');
    append(&head, 'B');
    addAtBeg(&head, 'C');
    addAtPOS(&head, 'D', 2);
    display(head);
    displayMORE(head);
    cout << "Length: " << getLength(head) << endl;
    removeFirst(&head);
    display(head);
    removeLast(&head);
    display(head);
    removePOS(&head, 1);
    display(head);
    return 0;
}