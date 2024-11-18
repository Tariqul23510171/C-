#include <iostream>
using namespace std;

void countingSort(int arr[], int n) {
    int k = arr[0];//initialized k= 0 index
    for (int i = 1; i < n; i++) {
        k = max(k, arr[i]);//finding max index by max number
    }

    int count[k + 1] = {0};
    for (int i = 0; i < n; i++) {  //how many element how many times (count)
        count[arr[i]]++;
    }

    for (int i = 1; i <= k; i++) {//position with + count
        count[i] += count[i - 1];
    }

    int output[n];
    for (int i = n - 1; i >= 0; i--) {//sored array using decrement
        output[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    countingSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

        cout << "Md Tariqul islam ___ id; 23-51017-1  ";


    return 0;
}


