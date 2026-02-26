#include<iostream>
using namespace std;
void bubbleSort(int arr[],int n){
    for(int i = n-1; i >=1; i--) {
        int didswap =0;
        for(int j = 0; j <= i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                didswap =1;
            }
        }
        if(didswap == 0) {
            break;
        }
        cout<<"runs"<<endl;
    }


}


int main(){
    // int arr[]={13,46,24,52,20,9};
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);
    for(int i =0; i<n;i++){
        cout<<arr[i]<<" ";
    }


}