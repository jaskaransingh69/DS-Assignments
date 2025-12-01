#include<iostream>
#include<string.h>
using namespace std;

class Stack {
public:
    char arr[100];
    int top;

    Stack(){ top = -1; }
    void push(char c){ arr[++top] = c; }
    char pop(){ return arr[top--]; }
    char peek(){ return arr[top]; }
    bool isEmpty(){ return top == -1; }
};

int precedence(char c){
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}

int main(){
    char infix[100], postfix[100];
    cin >> infix;

    Stack s;
    int k = 0;

    for(int i=0; infix[i] != '\0'; i++){
        char c = infix[i];

        if(isalnum(c))
            postfix[k++] = c;

        else if(c == '(')
            s.push(c);

        else if(c == ')'){
            while(!s.isEmpty() && s.peek() != '(')
                postfix[k++] = s.pop();
            s.pop();  // remove '('
        }

        else {
            while(!s.isEmpty() && precedence(s.peek()) >= precedence(c))
                postfix[k++] = s.pop();
            s.push(c);
        }
    }

    while(!s.isEmpty())
        postfix[k++] = s.pop();

    postfix[k] = '\0';
    cout << postfix;
}
