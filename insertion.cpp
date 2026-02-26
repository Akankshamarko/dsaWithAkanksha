#include<iostream>
using namespace std;
void selectionsort(int arr[],int n){
    for(int i=0; i<n; i++){
        int j =i;
        while(j> 0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
            cout<<"runs"<<endl;
        }
    }

}
int main(){
    // int arr[]={13,46,24,52,20,9,8};
    int arr[]={1,2,3,4,5,6,7,8,9,10};
     int n = sizeof(arr) / sizeof(arr[0]);
    selectionsort(arr,n);
   
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<endl;
    }
}