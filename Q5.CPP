#include <iostream>
#include <string>
using namespace std;


unsigned long calculateAddress(string type, int rows, int cols, string arrangement, unsigned long baseAddress, int i, int j) {
    int elementSize;
    

    if (type == "int") {
        elementSize = sizeof(int);
    } else if (type == "char") {
        elementSize = sizeof(char);
    } else if (type == "float") {
        elementSize = sizeof(float);
    } else if (type == "double") {
        elementSize = sizeof(double);
    } else {
        cout << "Unsupported type!" << endl;
        return 0;
    }
    

    if (arrangement == "ROW") {
        return baseAddress + elementSize * (i * cols + j);
    } else if (arrangement == "COLUMN") {
        return baseAddress + elementSize * (j * rows + i);
    } else {
        cout << "Unsupported memory arrangement!" << endl;
        return 0;
    }
}
int main() {
    string type;
    int rows, cols, i, j;
    string arrangement;
    unsigned long baseAddress;
    

    cout << "Enter the type of array (int, char, float, double): ";
    cin >> type;
    


    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    cout << "Enter the memory arrangement (ROW or COLUMN): ";
    cin >> arrangement;

    cout << "Enter the base address of the array: ";
    cin >> baseAddress;

    cout << "Enter the row index of the element: ";
    cin >> i;
    cout << "Enter the column index of the element: ";
    cin >> j;

    unsigned long address = calculateAddress(type, rows, cols, arrangement, baseAddress, i, j);
    cout << "The address of the element at (" << i << ", " << j << ") is: " << address << endl;
    return
     }
    