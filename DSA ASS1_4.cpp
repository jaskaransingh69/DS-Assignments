#include<iostream>
using namespace std;
//REVERESE AN ARRAY
int main(){
    int n;cin>>n;
    int arr[n];
    //input elements
    for(int i=0;i<n;i++)cin>>arr[i];
    //compute
    for(int i = 0; i<n/2; i++){
        int temp = arr[i]; 
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
    //to display elements
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    return 0;
}