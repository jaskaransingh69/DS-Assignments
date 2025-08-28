#include <iostream>
using namespace std;
int main(){
    int n;cin>>n;
    int a[10][10];
//input
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cin>>a[i][j];
    }
//compute
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=a[i][j];
            cout<<"Row"<<i<<"="<<sum<<"\n";
        }
    }
//output    
    for(int j=0;j<n;j++){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i][j];
            cout<<"Col"<<j<<"="<<sum<<"\n";
        }
    }
}
