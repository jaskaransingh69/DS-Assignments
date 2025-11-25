#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

// Insert at end
void insertEnd(Node* &head, int d){
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

// Reverse the linked list
Node* reverseList(Node *head){
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while(curr != NULL){
        next = curr->next;   // save next
        curr->next = prev;   // reverse pointer
        prev = curr;         // move prev
        curr = next;         // move curr
    }

    return prev;  // new head
}

// Display
void display(Node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    Node *head = NULL;

    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values:\n";
    for(int i = 0; i < n; i++){
        cin >> val;
        insertEnd(head, val);
    }

    cout << "Original List: ";
    display(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    display(head);

    return 0;
}
