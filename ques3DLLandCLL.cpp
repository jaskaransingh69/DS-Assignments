#include<iostream>
using namespace std;

class DNode{
public:
    int data;
    DNode *prev, *next;

    DNode(int d){
        data = d;
        prev = next = NULL;
    }
};

class CNode{
public:
    int data;
    CNode *next;

    CNode(int d){
        data = d;
        next = NULL;
    }
};

int sizeDLL(DNode *head){
    int c = 0;
    while(head){
        c++;
        head = head->next;
    }
    return c;
}

int sizeCLL(CNode *head){
    if(head == NULL) return 0;

    int c = 0;
    CNode *temp = head;

    do{
        c++;
        temp = temp->next;
    } while(temp != head);

    return c;
}

int main(){
    // DLL creation example
    DNode *d = new DNode(1);
    d->next = new DNode(2);
    d->next->prev = d;

    // CLL creation example
    CNode *c = new CNode(10);
    CNode *c2 = new CNode(20);
    c->next = c2;
    c2->next = c;

    cout << "DLL Size = " << sizeDLL(d) << endl;
    cout << "CLL Size = " << sizeCLL(c) << endl;
}
