#include<iostream>
#include <cstring>

using namespace std;



struct Contact {
    char name[100];
    char mobile[15];
    Contact* next;
};


Contact* createContact(const char* name, const char* mobile) {
    Contact* newContact = new Contact();
    strcpy(newContact->name, name);
    strcpy(newContact->mobile, mobile);
    newContact->next = nullptr;
    return newContact;
}


int getLength(Contact* head) {
    int length = 0;
    Contact* temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }
    return length;
}


void addAtBeg(Contact** head, const char* name, const char* mobile) {
    Contact* newContact = createContact(name, mobile);
    newContact->next = *head;
    *head = newContact;
}


void append(Contact** head, const char* name, const char* mobile) {
    Contact* newContact = createContact(name, mobile);
    if (*head == nullptr) {
        *head = newContact;
        return;
    }
    Contact* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newContact;
}







void addAtPOS(Contact** head, const char* name, const char* mobile, int pos) {
    if (pos == 0) {
        addAtBeg(head, name, mobile);
        return;
    }
    Contact* newContact = createContact(name, mobile);
    Contact* temp = *head;
    for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position out of bounds\n";
        return;
    }
    newContact->next = temp->next;
    temp->next = newContact;
}


void display(Contact* head) {
    Contact* temp = head;
    while (temp != nullptr) {
        cout << "Name: " << temp->name << ", Mobile: " << temp->mobile << " -> ";
        temp = temp->next;
    }
    cout << endl;
}


void displayMORE(Contact* head) {
    Contact* temp = head;
    while (temp != nullptr) {
        cout << "Address: " << temp << ", Name: " << temp->name << ", Mobile: " << temp->mobile << ", Next: " << temp->next << endl;
        temp = temp->next;
    }
}


void removeFirst(Contact** head) {
    if (*head == nullptr) {
        return;
    }
    Contact* temp = *head;
    *head = (*head)->next;
    delete temp;
}


void removeLast(Contact** head) {
    if (*head == nullptr) {
        return;
    }
    if ((*head)->next == nullptr) {
        delete *head;
        *head = nullptr;
        return;
    }
    Contact* temp = *head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}



void removePOS(Contact** head, int pos) {
    if (*head == nullptr) {
        return;
    }
    if (pos == 0) {
        removeFirst(head);
        return;
    }
    Contact* temp = *head;
    for (int i = 0; i < pos - 1 && temp->next != nullptr; i++) {
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        cout << "Position out of bounds\n";
        return;
    }
    Contact* contactToDelete = temp->next;
    temp->next = temp->next->next;
    delete contactToDelete;
}
int main() {
    Contact* head = nullptr;
    
    append(&head, "Akanksha", "23i3106");
    append(&head, "bhumi", "0987654321");
    addAtBeg(&head, "kaniska", "1112223333");
    addAtPOS(&head, "noone", "4445556666", 2);
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