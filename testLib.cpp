#include <iostream>
#include "BinarySearch.cpp"

using namespace BinarySearch;

int main() {
    int arr[] = {1,2,3, 4};
    int length = sizeof(arr) / sizeof(*arr);
    int* sorted = sort(arr, length);

    return 0;
}