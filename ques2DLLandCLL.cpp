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

void insert(Node* &head, int d){
    Node *newNode = new Node(d);

    if(head == NULL){
        head = newNode;
        newNode->next = head;
        return;
    }

    Node *temp = head;
    while(temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

void display(Node *head){
    if(head == NULL) return;

    Node *temp = head;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != head);

    cout << head->data; // repeat head node
}

int main(){
    Node *head = NULL;
    int n, val;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> val;
        insert(head, val);
    }

    display(head);
}
