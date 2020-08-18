#include <iostream>
#include "Utility/Swap.h"
#include "Utility/InvertArray.h"
#include "Basic/InsertionSort.h"
#include "Basic/BubbleSort.h"
#include "Experimental/SleepSort.h"

int main() {

    //Testing the insertion sort algorithm:
    std::cout << "TESTING: Insertion sort" << std::endl;
    int arr[] = {5,1,54,-2,54,36, 70};
    int length = sizeof(arr) / sizeof(*arr);
    int* sorted = SortingAlgorithms::Basic::InsertionSort::sort(arr, length);

    for(int i = 0; i < length; i++) {
        std::cout << sorted[i] << std::endl;
    }


    //Testing inverting algorithm:
    std::cout << "TESTING: Inverting algorithm on the previous result." << std::endl;
    int* inverted = SortingAlgorithms::Utility::InvertArray::invert(sorted, length);
    for(int i = 0; i < length; i++) {
        std::cout << inverted[i] << std::endl;
    }

    // Testing timed sorting:
    std::cout << "TESTING: Timed sorting" << std::endl;
    int arr2[] = {5,3,54,2,54,36,70,100,30,8,1};
    int length2 = sizeof(arr2) / sizeof(*arr2);
    int* sorted2 = SortingAlgorithms::Experimental::SleepSort::sort(arr2, length2);

    for (int i = 0; i < length2; i++) {
        std::cout << sorted2[i] << std::endl;
    }


    std::cout << "TESTING: Swap" << std::endl;
    int number1 = 1;
    int number2 = 2;
    SortingAlgorithms::Utility::Swap::swap(&number1, &number2);
    std::cout << "Number 1: " << number1 << " and number 2: " << number2 << std::endl;

    std::cout << "TESTING: Bubble sort" << std::endl;
    int* sorted3 = SortingAlgorithms::Basic::BubbleSort::sort(arr,length);
    for(int i = 0; i < length; i++) {
        std::cout << sorted[i] << std::endl;
    }

    delete inverted;
    delete sorted;
    delete sorted2;
    delete sorted3;

    return 0;
}