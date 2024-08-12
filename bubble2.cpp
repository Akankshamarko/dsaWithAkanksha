#include<iostream>
using namespace std;
void  bubblesort(int arr[] , int n)
{
    for (int i = 0; i<n-1; i++)
    {
        for ( int j =0; j<n-1-i; j++)
        {
            if (arr[j]>arr[j+i])
            {
        
            int temp=arr[j];
            arr[j]=arr[j+i];
            arr[j+i]=temp;
             
        }
    }
}
}

int main (){

    int arr[] = { 25, 60, 54, 64 , 70 };
    int n =5;

    
    bubblesort(arr,n);
    for (int i =0; i<n; i++){
       // for (int j = 0;j<n-1; j++){

        
        cout<<arr[i]<<" "<<endl;
    }
    return 0;
}
