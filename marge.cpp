#include <iostream>
using namespace std;

void merge(int a[], int l, int mid, int h) {
    int i = l, j = mid + 1, k = l;
    int temp[100]; // Assuming the array size will not exceed 100 elements

    while (i <= mid && j <= h) {
        if (a[i] < a[j]) {
            temp[k] = a[i];
            i++;
            k++;
        } else {
            temp[k] = a[j];
            j++;
            k++;
        }
    }

    if (i > mid) {
        while (j <= h) {
            temp[k] = a[j];
            j++;
            k++;
        }
    } else {
        while (i <= mid) {
            temp[k] = a[i];
            i++;
            k++;
        }
    }

    for (k = l; k <= h; k++) {
        a[k] = temp[k];
    }
}

void mergeSort(int a[], int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, h);
        merge(a, l, mid, h);
    }
}

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int a[100]; // Assuming the array size will not exceed 100 elements
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    mergeSort(a, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
