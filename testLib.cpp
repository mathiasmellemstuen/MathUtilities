#include <iostream>
#include "InsertionSort.cpp"
#include "InvertArray.cpp"
#include "TimerSort.cpp"

int main() {

    //Testing the insertion sort algorithm:
    std::cout << "TESTING: Insertion sort" << std::endl;
    int arr[] = {5,1,54,-2,54,36, 70};
    int length = sizeof(arr) / sizeof(*arr);
    int* sorted = InsertionSort::sort(arr, length);

    for(int i = 0; i < length; i++) {
        std::cout << sorted[i] << std::endl;
    }


    //Testing inverting algorithm:
    std::cout << "TESTING: Inverting algorithm on the previous result." << std::endl;
    int* inverted = InvertArray::invert(sorted, length);
    for(int i = 0; i < length; i++) {
        std::cout << inverted[i] << std::endl;
    }

    // Testing timed sorting:
    std::cout << "TESTING: Timed sorting" << std::endl;
    int arr2[] = {5,3,54,2,54,36,70,100,30,8,1};
    int length2 = sizeof(arr2) / sizeof(*arr2);
    int* sorted2 = TimeSort::sort(arr2, length2);

    for (int i = 0; i < length2; i++) {
        std::cout << sorted2[i] << std::endl;
    }

    delete sorted;
    delete inverted;

    return 0;
}