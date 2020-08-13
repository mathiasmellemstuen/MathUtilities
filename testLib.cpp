#include <iostream>
#include "InsertionSort.cpp"

using namespace InsertionSort;

int main() {

    //Testing the insertion sort algorithm:
    std::cout << "TESTING: Insertion sort" << std::endl;
    int arr[] = {5,1,54, -2, 54,36};
    int length = sizeof(arr) / sizeof(*arr);
    int* sorted = sort(arr, length);

    for(int i = 0; i < length; i++) {
        std::cout << sorted[i] << std::endl;
    }
    delete sorted;
    return 0;
}