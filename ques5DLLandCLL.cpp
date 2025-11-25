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

// Function to check if list is circular
bool isCircular(Node *head){
    if(head == NULL) return true;  // empty list considered circular

    Node *temp = head->next;

    while(temp != NULL && temp != head){
        temp = temp->next;
    }

    return (temp == head);
}

// Helper function to insert normally (non-circular)
void insertEnd(Node* &head, int data){
    Node *newNode = new Node(data);

    if(head == NULL){
        head = newNode;
        return;
    }

    Node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

int main(){
    Node *head = NULL;

    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values:\n";
    for(int i=0; i<n; i++){
        cin >> val;
        insertEnd(head, val);
    }

    // Uncomment this line to make the list circular:
    // head->next->next->next = head;  // example

    if(isCircular(head))
        cout << "The linked list is circular.";
    else
        cout << "The linked list is NOT circular.";

    return 0;
}
