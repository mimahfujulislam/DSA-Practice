#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void findGreaterEqual(int arr[], int size, int key) {
    int index = binarySearch(arr, size, key);
    if (index != -1) {
        cout << "Elements greater than or equal to " << key << ": ";
        for (int i = index; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No elements greater than or equal to " << key << " found." << endl;
    }
}

void findLessEqual(int arr[], int size, int key) {
    int index = binarySearch(arr, size, key);
    if (index != -1) {
        cout << "Elements less than or equal to " << key << ": ";
        for (int i = 0; i <= index; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No elements less than or equal to " << key << " found." << endl;
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49};
    int size = sizeof(arr) / sizeof(arr[0]);

    int keys[3];
    cout << "Enter 3 keys to search: ";
    for (int i = 0; i < 3; i++) {
        cin >> keys[i];
    }

    for (int key : keys) {
        int index = binarySearch(arr, size, key);
        if (index != -1) {
            cout << "Key " << key << " found at index: " << index << endl;
        } else {
            cout << "Key " << key << " not found." << endl;
        }
    }

    findGreaterEqual(arr, size, 17);
    findLessEqual(arr, size, 37);

    return 0;
}
