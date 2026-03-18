#include<iostream>
#include<vector>
using namespace std;
int binarysearch(vector<int>& arr, int target) {
    int start = 0;
    int end = arr.size() - 1;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(arr[mid] == target) {
            return mid; // Target found at index mid
        } else if(arr[mid] < target) {
            start = mid + 1; // Search in the right half
        } else {
            end = mid - 1; // Search in the left half
        }
    }
    return -1; // Target not found
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int target = 5;
    int target = 6;
    int result = binarysearch(arr, target);
    if(result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    return 0;
}
