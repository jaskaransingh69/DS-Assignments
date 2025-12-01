#include<iostream>
#include<string.h>
using namespace std;

class Stack {
public:
    char arr[100];
    int top;

    Stack(){ top = -1; }

    void push(char c){
        arr[++top] = c;
    }

    char pop(){
        return arr[top--];
    }

    bool isEmpty(){
        return top == -1;
    }
};

int main(){
    char str[100];
    cin >> str;

    Stack s;

    for(int i = 0; str[i] != '\0'; i++)
        s.push(str[i]);

    while(!s.isEmpty())
        cout << s.pop();
}
