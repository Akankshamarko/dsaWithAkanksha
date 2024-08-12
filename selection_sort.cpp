#include<iostream>
using namespace std;
void Selection_sort ( int arr[] , int n);
  int main(){
    int arr[] = { 6 , 5 , 3, 2 ,1 ,4};
    int n = 6; 

    Selection_sort( arr,  n);
    for ( int i = 0; i<n; i++){
        cout<<arr[i]<<endl;
    }
    
    return 0;
}  

void Selection_sort ( int arr[] , int n)
{
    for (int i = 0; i<(n-1); i++){
        int min_pos = 1;
        for (int j = i+1; j<n; j++ ){
            if( arr[j]<arr[min_pos]){
                min_pos = j;
            }
            
        }
        if (min_pos != i){
            int temp = arr[i];
            arr[i] = arr[min_pos];
            arr[min_pos] = temp;

        }
    }
    
}
