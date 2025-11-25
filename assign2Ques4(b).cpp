#include<iostream>
#include<string.h>
using namespace std;

int main(){
    char s[100];
    cin >> s;

    int n = strlen(s);

    for(int i=0, j=n-1; i<j; i++, j--){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    cout << s;
}
