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

// ================= DOUBLY LINKED LIST =================

// Insert at head
void insertHead(DNode* &head, int d){
    DNode *newNode = new DNode(d);

    if(head == NULL){
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Insert at tail
void insertTail(DNode* &head, int d){
    DNode *newNode = new DNode(d);

    if(head == NULL){
        head = newNode;
        return;
    }

    DNode *temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert before element
void insertBefore(DNode* &head, int key, int d){
    if(head == NULL) return;

    if(head->data == key){
        insertHead(head, d);
        return;
    }

    DNode *temp = head;
    while(temp != NULL && temp->data != key)
        temp = temp->next;

    if(temp == NULL){
        cout << "Key not found\n";
        return;
    }

    DNode *newNode = new DNode(d);
    newNode->next = temp;
    newNode->prev = temp->prev;

    temp->prev->next = newNode;
    temp->prev = newNode;
}

// Insert after element
void insertAfter(DNode* &head, int key, int d){
    DNode *temp = head;

    while(temp != NULL && temp->data != key)
        temp = temp->next;

    if(temp == NULL){
        cout<<"Key not found\n";
        return;
    }

    DNode *newNode = new DNode(d);
    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Delete node with value
void deleteDLL(DNode* &head, int key){
    if(head == NULL) return;

    if(head->data == key){
        DNode *t = head;
        head = head->next;
        if(head) head->prev = NULL;
        delete t;
        return;
    }

    DNode *temp = head;

    while(temp != NULL && temp->data != key)
        temp = temp->next;

    if(temp == NULL){
        cout<<"Node not found\n";
        return;
    }

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    temp->prev->next = temp->next;

    delete temp;
}

// Search in DLL
bool searchDLL(DNode *head, int key){
    while(head != NULL){
        if(head->data == key) return true;
        head = head->next;
    }
    return false;
}

void displayDLL(DNode *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// ================= CIRCULAR LINKED LIST =================

void insertCLL(CNode* &head, int d){
    CNode *newNode = new CNode(d);

    if(head == NULL){
        head = newNode;
        newNode->next = head;
        return;
    }

    CNode *temp = head;
    while(temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

void deleteCLL(CNode* &head, int key){
    if(head == NULL) return;

    CNode *curr = head, *prev = NULL;

    // find key
    do{
        if(curr->data == key) break;
        prev = curr;
        curr = curr->next;
    } while(curr != head);

    if(curr->data != key){
        cout << "Node not found\n";
        return;
    }

    // only one element
    if(curr == head && curr->next == head){
        head = NULL;
        delete curr;
        return;
    }

    // deleting head
    if(curr == head){
        CNode *temp = head;
        while(temp->next != head)
            temp = temp->next;

        head = head->next;
        temp->next = head;
        delete curr;
        return;
    }

    prev->next = curr->next;
    delete curr;
}

bool searchCLL(CNode *head, int key){
    if(head == NULL) return false;

    CNode *temp = head;

    do{
        if(temp->data == key) return true;
        temp = temp->next;
    } while(temp != head);

    return false;
}

void displayCLL(CNode *head){
    if(head == NULL) return;

    CNode *temp = head;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != head);

    cout << endl;
}


// ======================= MAIN =======================
int main(){
    DNode *dhead = NULL;
    CNode *chead = NULL;

    int ch, op, data, key;

    while(true){
        cout << "\n1. Doubly Linked List\n2. Circular Linked List\n3. Exit\n";
        cin >> ch;

        if(ch == 1){
            cout<<"\n1 Insert head\n2 Insert tail\n3 Insert before key\n4 Insert after key\n5 Delete\n6 Search\n7 Display\n";
            cin>>op;

            switch(op){
                case 1: cin>>data; insertHead(dhead,data); break;
                case 2: cin>>data; insertTail(dhead,data); break;
                case 3: cin>>key>>data; insertBefore(dhead,key,data); break;
                case 4: cin>>key>>data; insertAfter(dhead,key,data); break;
                case 5: cin>>key; deleteDLL(dhead,key); break;
                case 6: cin>>key; cout<<(searchDLL(dhead,key)?"Found":"Not Found")<<endl; break;
                case 7: displayDLL(dhead); break;
            }
        }

        else if(ch == 2){
            cout<<"\n1 Insert\n2 Delete\n3 Search\n4 Display\n";
            cin>>op;

            switch(op){
                case 1: cin>>data; insertCLL(chead,data); break;
                case 2: cin>>key; deleteCLL(chead,key); break;
                case 3: cin>>key; cout<<(searchCLL(chead,key)?"Found":"Not Found")<<endl; break;
                case 4: displayCLL(chead); break;
            }
        }

        else break;
    }

    return 0;
}
