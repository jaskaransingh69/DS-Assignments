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

// Count occurrences
int countKey(Node *head, int key){
    int count = 0;

    while(head != NULL){
        if(head->data == key) count++;
        head = head->next;
    }

    return count;
}

// Delete all occurrences
void deleteKey(Node* &head, int key){
    while(head != NULL && head->data == key){
        Node *t = head;
        head = head->next;
        delete t;
    }

    Node *curr = head;
    Node *prev = NULL;

    while(curr != NULL){
        if(curr->data == key){
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
}

void display(Node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

int main(){
    Node *head = NULL;

    int n, val, key;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter the values:\n";
    for(int i=0; i<n; i++){
        cin >> val;
        insertEnd(head, val);
    }

    cout << "Enter key to count and delete: ";
    cin >> key;

    int occ = countKey(head, key);
    cout << "Occurrences of " << key << " = " << occ << endl;

    deleteKey(head, key);

    cout << "List after deleting all occurrences:\n";
    display(head);
}
