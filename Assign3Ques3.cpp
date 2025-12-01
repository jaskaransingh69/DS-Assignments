#include<iostream>
using namespace std;

class Stack {
public:
    char arr[100];
    int top;

    Stack(){ top = -1; }

    void push(char c){ arr[++top] = c; }
    char pop(){ return arr[top--]; }
    bool isEmpty(){ return top == -1; }
};

bool isMatching(char a, char b){
    return (a=='(' && b==')') ||
           (a=='{' && b=='}') ||
           (a=='[' && b==']');
}

int main(){
    char exp[100];
    cin >> exp;

    Stack s;

    for(int i=0; exp[i]!='\0'; i++){
        char c = exp[i];

        if(c=='(' || c=='{' || c=='[')
            s.push(c);

        else if(c==')' || c=='}' || c==']'){
            if(s.isEmpty()){
                cout << "Not Balanced";
                return 0;
            }
            if(!isMatching(s.pop(), c)){
                cout << "Not Balanced";
                return 0;
            }
        }
    }

    cout << (s.isEmpty() ? "Balanced" : "Not Balanced");
}
