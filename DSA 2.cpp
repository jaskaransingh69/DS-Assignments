#include<iostream>
using namespace std;

void remDuplicates(int arr[], int n){
    for(int i = 0; i<n; i++){
        int target = arr[i];
        for(int j = 1; j<n-1; j++){
            if(arr[j] == target){
                arr[j] = arr[j+1];
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    remDuplicates(arr, n);
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}