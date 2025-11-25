#include<iostream>
using namespace std;

int main(){
    char s1[100], s2[100];

    cin >> s1;
    cin >> s2;

    int i=0, j=0;

    while(s1[i] != '\0') i++;

    while(s2[j] != '\0'){
        s1[i] = s2[j];
        i++; j++;
    }
    s1[i] = '\0';

    cout << "Concatenated: " << s1;
}
