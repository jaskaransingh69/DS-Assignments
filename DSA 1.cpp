#include <iostream>
using namespace std;

int arr[100], n = 0;

void create() {
    cout << "Enter size: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void display() {
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void insertElement() {
    int pos, x;
    cout << "Enter position and value: ";
    cin >> pos >> x;

    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = x;
    n++;
}

void deleteElement() {
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void searchElement() {
    int x;
    cout << "Enter value to search: ";
    cin >> x;

    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            cout << "Found at index " << i << "\n";
            return;
        }
    }
    cout << "Not Found\n";
}

int main() {
    int ch;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. CREATE" << endl;
        cout << "2. DISPLAY" << endl;
        cout << "3. INSERT" << endl;
        cout << "4. DELETE" << endl;
        cout << "5. SEARCH" << endl;
        cout << "6. EXIT" << endl;
        cout << "Enter choice: " << endl;
        cin >> ch;

        if (ch == 1) create();
        else if (ch == 2) display();
        else if (ch == 3) insertElement();
        else if (ch == 4) deleteElement();
        else if (ch == 5) searchElement();
        else break;
    }
    return 0;
}

