#include<iostream>
using namespace std;

void transpose(int A[][3], int B[][3]){
    int rows = A[0][0];
    int cols = A[0][1];
    int n = A[0][2];

    B[0][0] = cols;
    B[0][1] = rows;
    B[0][2] = n;

    int k = 1;

    for(int c = 0; c < cols; c++){
        for(int i = 1; i <= n; i++){
            if(A[i][1] == c){
                B[k][0] = A[i][1];
                B[k][1] = A[i][0];
                B[k][2] = A[i][2];
                k++;
            }
        }
    }
}

int main(){
    int A[10][3], B[10][3];
    int n;

    cout << "Enter number of non-zero elements: ";
    cin >> n;

    A[0][0] = A[0][1] = 0;   // will overwrite later
    A[0][2] = n;

    cout << "Enter row, col, value for each (0-indexed):\n";
    for(int i=1; i<=n; i++)
        cin >> A[i][0] >> A[i][1] >> A[i][2];

    cout << "Enter total rows and cols: ";
    cin >> A[0][0] >> A[0][1];

    transpose(A, B);

    cout << "\nTranspose (Triplet):\n";
    for(int i=0; i<=n; i++)
        cout << B[i][0] << " " << B[i][1] << " " << B[i][2] << endl;
}
