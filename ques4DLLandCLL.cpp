#include<iostream>
using namespace std;

class Node{
public:
    char data;
    Node *prev, *next;

    Node(char c){
        data = c;
        prev = next = NULL;
    }
};

bool isPalindrome(Node *head){
    if(head == NULL) return true;

    Node *tail = head;

    // go to last node
    while(tail->next != NULL)
        tail = tail->next;

    while(head != tail && tail->next != head){
        if(head->data != tail->data)
            return false;

        head = head->next;
        tail = tail->prev;
    }

    return true;
}

int main(){
    Node *head = new Node('R');
    head->next = new Node('A'); head->next->prev = head;
    head->next->next = new Node('D'); head->next->next->prev = head->next;
    head->next->next->next = new Node('A'); head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node('R'); head->next->next->next->next->prev = head->next->next->next;

    cout << (isPalindrome(head) ? "True" : "False");
}
