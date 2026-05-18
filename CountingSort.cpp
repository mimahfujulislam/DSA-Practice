#include <iostream>
using namespace std;

void countingSort(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    int count[maxVal + 1] = {0};
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }
    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i] > 0) {
            arr[index++]=i;
            count[i]--;
        }
    }
}
int main() {
    int arr[] = {6, 4, 2, 1, 9, 8, 3, 5, 12, 10, 11};
    int size = sizeof(arr)/sizeof(arr[0]);
    countingSort(arr, size);
    for (int i=0; i<size; i++) {
        cout<<arr[i]<< " ";
    }
    cout<<endl;

    return 0;
}
