#include <iostream>
using namespace std;

void remDuplicates(int a[], int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]){
                for(int k=j;k<n-1;k++){
                    a[k]=a[k+1];
                    n--;
                    j--;
                }
            }   
        }
    }
}

int main(){
    int n;cin>>n;
    int a[100];
    for(int i=0;i<n;i++)cin>>a[i];
    
    remDuplicates(a, int n)
    
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    return 0;
}
