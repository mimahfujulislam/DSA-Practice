#include <iostream>
using namespace std;

int linearSearch(int a[], int size, int target) {
    for (int i=0; i<size; i++) {
        if (a[i]==target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int a[]={10,15,30,70,80,60,20,90,40};
    int size = sizeof(a)/sizeof(a[0]);
    int target;

    cout<<"Enter the number to search: ";
    cin>>target;

    int result=linearSearch(a,size,target);

    if (result!=-1) {
        cout<<"Data found at index: "<<result<<endl;
    } else {
        cout<<"Data not found in the array." <<endl;
    }

    return 0;
}
