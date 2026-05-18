#include <iostream>
using namespace std;

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main() {
    int arr[] = {7, 6, 10, 5, 9, 2, 1, 15, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout<<"Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<< " ";
    }
    cout<<endl;
    return 0;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int left = low + 1;
    int right = high;
    while(left <= right) {
        while(left<=right&&arr[left]<=pivot) {
            left++;
        }
        while(left <= right && arr[right]>pivot) {
            right--;
        }
        if (left < right) {
            swap(arr[left],arr[right]);
        }
    }
    swap(arr[low], arr[right]);
    return right;
}
