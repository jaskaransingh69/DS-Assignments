#include<iostream>
#include<string.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    char arr[20][100];

    for(int i=0; i<n; i++)
        cin >> arr[i];

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(strcmp(arr[j], arr[j+1]) > 0){
                char temp[100];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);
            }
        }
    }

    for(int i=0; i<n; i++)
        cout << arr[i] << endl;
}
