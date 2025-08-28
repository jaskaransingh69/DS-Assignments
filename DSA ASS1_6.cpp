#include <iostream>
using namespace std;
//TRANSPOSE OF A MATRIX

int main(){
    int n = 3;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cin>>a[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[j][i]<<" "<<endl;
        }
    }
}
