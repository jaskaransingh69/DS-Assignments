#include<iostream>
using namespace std;

void addSparse(int A[][3], int B[][3], int C[][3]){
    if(A[0][0] != B[0][0] || A[0][1] != B[0][1]){
        cout << "Matrix dimensions do not match!";
        return;
    }

    int i=1, j=1, k=1;
    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    while(i <= A[0][2] && j <= B[0][2]){
        if(A[i][0] < B[j][0]){
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        }
        else if(B[j][0] < A[i][0]){
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        }
        else {
            if(A[i][1] < B[j][1]){
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = A[i][2];
                i++; k++;
            }
            else if(B[j][1] < A[i][1]){
                C[k][0] = B[j][0];
                C[k][1] = B[j][1];
                C[k][2] = B[j][2];
                j++; k++;
            }
            else {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = A[i][2] + B[j][2];
                i++; j++; k++;
            }
        }
    }

    while(i <= A[0][2]){
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++; k++;
    }

    while(j <= B[0][2]){
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++; k++;
    }

    C[0][2] = k - 1;
}

int main(){
    int A[10][3], B[10][3], C[20][3];
    int m, n;

    cout << "Enter non-zero count for A: ";
    cin >> m;
    cout << "Enter triplets of A:\n";
    for(int i=0; i<=m; i++)
        cin >> A[i][0] >> A[i][1] >> A[i][2];

    cout << "Enter non-zero count for B: ";
    cin >> n;
    cout << "Enter triplets of B:\n";
    for(int i=0; i<=n; i++)
        cin >> B[i][0] >> B[i][1] >> B[i][2];

    addSparse(A, B, C);

    cout << "\nResult (A + B):\n";
    for(int i=0; i<=C[0][2]; i++)
        cout << C[i][0] << " " << C[i][1] << " " << C[i][2] << endl;
}
