#include<iostream>
using namespace std;

void multiply(int A[][3], int B[][3], int C[][3]){
    if(A[0][1] != B[0][0]){
        cout << "Multiplication not possible!\n";
        return;
    }

    int k = 1;
    C[0][0] = A[0][0];
    C[0][1] = B[0][1];

    for(int i=1; i<=A[0][2]; i++){
        for(int j=1; j<=B[0][2]; j++){
            if(A[i][1] == B[j][0]){
                int row = A[i][0];
                int col = B[j][1];
                int val = A[i][2] * B[j][2];

                bool found = false;

                for(int x=1; x<k; x++){
                    if(C[x][0] == row && C[x][1] == col){
                        C[x][2] += val;
                        found = true;
                        break;
                    }
                }

                if(!found){
                    C[k][0] = row;
                    C[k][1] = col;
                    C[k][2] = val;
                    k++;
                }
            }
        }
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

    multiply(A, B, C);

    cout << "\nResult (A × B) in triplet form:\n";
    for(int i=0; i<=C[0][2]; i++)
        cout << C[i][0] << " " << C[i][1] << " " << C[i][2] << endl;
}
