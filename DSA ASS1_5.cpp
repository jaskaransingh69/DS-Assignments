#include <iostream>
using namespace std;
//MATRIX MULTIPLICATION

int main(){
    int n = 3;
    int a[n][n],b[n][n],c[n][n]={0};
//input
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cin>>a[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cin>>b[i][j];
    }
//compute
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
//output    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<c[i][j]<<" "<<endl;
        }
    }
}
