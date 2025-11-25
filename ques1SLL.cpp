#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

// ---------------------- INSERTION ------------------------

// Insert at beginning
void insertAtHead(Node* &head, int d){
    Node *newNode = new Node(d);
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertAtTail(Node* &head, int d){
    Node *newNode = new Node(d);

    if(head == NULL){
        head = newNode;
        return;
    }

    Node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Insert BEFORE a value
void insertBefore(Node* &head, int key, int d){
    if(head == NULL) return;

    if(head->data == key){
        insertAtHead(head, d);
        return;
    }

    Node *prev = NULL, *curr = head;

    while(curr != NULL && curr->data != key){
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL){
        cout << "Key not found\n";
        return;
    }

    Node *newNode = new Node(d);
    prev->next = newNode;
    newNode->next = curr;
}

// Insert AFTER a value
void insertAfter(Node* &head, int key, int d){
    Node *temp = head;

    while(temp != NULL && temp->data != key)
        temp = temp->next;

    if(temp == NULL){
        cout << "Key not found\n";
        return;
    }

    Node *newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
}

// ---------------------- DELETION ------------------------

// Delete from beginning
void deleteBeginning(Node* &head){
    if(head == NULL) return;

    Node *temp = head;
    head = head->next;
    delete temp;
}

// Delete from end
void deleteEnd(Node* &head){
    if(head == NULL) return;

    if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;
    while(temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;
}

// Delete specific value
void deleteSpecific(Node* &head, int key){
    if(head == NULL) return;

    if(head->data == key){
        deleteBeginning(head);
        return;
    }

    Node *prev = NULL, *curr = head;

    while(curr != NULL && curr->data != key){
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL){
        cout << "Node not found\n";
        return;
    }

    prev->next = curr->next;
    delete curr;
}

// ---------------------- SEARCH ------------------------

void searchNode(Node *head, int key){
    int pos = 1;

    while(head != NULL){
        if(head->data == key){
            cout << "Found at position " << pos << endl;
            return;
        }
        head = head->next;
        pos++;
    }

    cout << "Not found\n";
}

// ---------------------- DISPLAY ------------------------

void display(Node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// ---------------------- MAIN MENU ------------------------

int main(){
    Node *head = NULL;
    int ch, data, key;

    while(true){
        cout << "\n====== SINGLY LINKED LIST MENU ======\n";
        cout << "1 Insert at beginning\n";
        cout << "2 Insert at end\n";
        cout << "3 Insert before a value\n";
        cout << "4 Insert after a value\n";
        cout << "5 Delete beginning\n";
        cout << "6 Delete end\n";
        cout << "7 Delete specific value\n";
        cout << "8 Search value\n";
        cout << "9 Display\n";
        cout << "10 Exit\n";

        cin >> ch;

        switch(ch){
            case 1: cin>>data; insertAtHead(head,data); break;
            case 2: cin>>data; insertAtTail(head,data); break;
            case 3: cin>>key>>data; insertBefore(head,key,data); break;
            case 4: cin>>key>>data; insertAfter(head,key,data); break;
            case 5: deleteBeginning(head); break;
            case 6: deleteEnd(head); break;
            case 7: cin>>key; deleteSpecific(head,key); break;
            case 8: cin>>key; searchNode(head,key); break;
            case 9: display(head); break;
            case 10: return 0;
        }
    }
}
