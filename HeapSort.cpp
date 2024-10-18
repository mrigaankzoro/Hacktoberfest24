#include <iostream>
using namespace std;

void MaxHeapify(int a[], int i, int n) {
    int j, temp;
    temp = a[i];
    j = 2 * i; 

    while (j <= n) {
        if (j < n && a[j + 1] > a[j]) {
            j = j + 1;
        }

        if (temp >= a[j]) {
            break;
        } else {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
}

void HeapSort(int a[], int n) {
    int temp;
    for (int i = n; i >= 2; i--) {
     
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        MaxHeapify(a, 1, i - 1);
    }
}

void Build_MaxHeap(int a[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        MaxHeapify(a, i, n);
    }
}

int main() {
    int n;
    cout << "\nEnter the number of data elements to be sorted: ";
    cin >> n;
    n++; 
    int arr[n];

    for (int i = 1; i < n; i++) {
        cout << "Enter element " << i << ": ";
        cin >> arr[i];
    }

    Build_MaxHeap(arr, n - 1);
    HeapSort(arr, n - 1);

    cout << "\nSorted Data: ";
    for (int i = 1; i < n; i++) {
        cout << "-> " << arr[i];
    }

    return 0; 
}
