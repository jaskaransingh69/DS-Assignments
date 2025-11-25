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

// Function to find middle
int findMiddle(Node *head){
    if(head == NULL){
        cout << "List is empty\n";
        return -1;
    }

    Node *slow = head;
    Node *fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
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

    int mid = findMiddle(head);

    if(mid != -1)
        cout << "Middle element = " << mid;

    return 0;
}
