#include<iostream>
using namespace std;
void selectionsort(int arr[], int n) {
    for(int i = 0; i <=n - 2; i++) {
        int minindex = i;
        for(int j = i ; j <= n-1; j++) {
            if(arr[j] < arr[minindex]) {
                minindex = j;
            }
        }
        swap(arr[i], arr[minindex]);
    }
}

int main(){
    int arr[]={13,46,24,52,20,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionsort(arr, n);
    for(int i =0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
