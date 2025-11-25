#include<iostream>
using namespace std;

int main(){
    char s[100], res[100];
    cin >> s;

    int j = 0;

    for(int i=0; s[i]!='\0'; i++){
        char c = s[i];
        if(c!='a' && c!='e' && c!='i' && c!='o' && c!='u' &&
           c!='A' && c!='E' && c!='I' && c!='O' && c!='U'){
               res[j++] = c;
        }
    }
    res[j] = '\0';

    cout << res;
}
