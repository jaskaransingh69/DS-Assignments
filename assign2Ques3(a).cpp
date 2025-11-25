#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,6,7};
    int n = 7; // range is 1 to n → 1 to 7

    int expected = n*(n+1)/2;
    int sum = 0;

    for(int i=0; i<n-1; i++)
        sum += arr[i];

    cout << "Missing number = " << expected - sum;
}