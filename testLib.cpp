#include <iostream>
#include "InsertionSort.cpp"
#include "InvertArray.cpp"

using namespace InsertionSort;
using namespace InvertArray;

int main() {

    //Testing the insertion sort algorithm:
    std::cout << "TESTING: Insertion sort" << std::endl;
    int arr[] = {5,1,54,-2,54,36, 70};
    int length = sizeof(arr) / sizeof(*arr);
    int* sorted = sort(arr, length);

    for(int i = 0; i < length; i++) {
        std::cout << sorted[i] << std::endl;
    }


    //Testing inverting algorithm:
    std::cout << "TESTING: Inverting algorithm on the previous result." << std::endl;
    int* inverted = invert(sorted, length);
    for(int i = 0; i < length; i++) {
        std::cout << inverted[i] << std::endl;
    }
    delete sorted;
    delete inverted;
    return 0;
}