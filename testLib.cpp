#include <iostream>

#include "Utility/Swap.h"
#include "Utility/InvertArray.h"
#include "Utility/IsSorted.h"

#include "Basic/InsertionSort.h"
#include "Basic/BubbleSort.h"
#include "Basic/CountSort.h"

#include "Experimental/SleepSort.h"

int main() {
    int arr[] = {5,1,54,-2,54,36, 70};
    int length = sizeof(arr) / sizeof(*arr);

    /*
     * Testing the insertion sort algorithm:
     */
    std::cout << "TESTING: Insertion sort" << std::endl;
    int* sorted = SortingAlgorithms::Basic::InsertionSort::sort(arr, length);
    for(int i = 0; i < length; i++)
        std::cout << sorted[i] << " ";
    std::cout << std::endl << std::endl;

    /*
     * Testing inverting algorithm:
     */
    std::cout << "TESTING: Inverting algorithm on the previous result." << std::endl;
    int* inverted = SortingAlgorithms::Utility::InvertArray::invert(sorted, length);
    for(int i = 0; i < length; i++)
        std::cout << inverted[i] << " ";
    std::cout << std::endl << std::endl;

    /*
     * Testing bubble sort
     */
    std::cout << "TESTING: Bubble sort" << std::endl;
    int* sorted3 = SortingAlgorithms::Basic::BubbleSort::sort(arr,length);
    for(int i = 0; i < length; i++)
        std::cout << sorted3[i] << " ";
    std::cout << std::endl << std::endl;

    /*
     * Testing sleep sorting:
     */
    std::cout << "TESTING: Timed sorting" << std::endl;
    // Generating a "random" array of numbers to test on
    int arr2Size = 20;  // Define the size of the array
    int arr2[arr2Size]; // Define the array
    for (int i = 0; i < arr2Size; i++)  // Fill the array with random number (1 - 100)
        arr2[i] = rand() % 100;

    // Sorts the array
    int length2 = sizeof(arr2) / sizeof(*arr2); // Define the lenth of the array
    int* sorted2 = SortingAlgorithms::Experimental::SleepSort::sort(arr2, length2); // Sorts the array using SleepSort

    // Print the unsorted array
    std::cout << "Unsorted array: ";
    for (int i = 0; i < arr2Size; i++)
        std::cout << arr2[i] << " ";
    std::cout << std::endl;

    // Print the sorted array
    std::cout << "Sorted array:   ";
    for (int i = 0; i < length2; i++)
        std::cout << sorted2[i] << " ";
    std::cout << std::endl;

    std::cout << SortingAlgorithms::Utility::IsSorted::isSorted(sorted2, length2) << std::endl << std::endl;

    /*
     * Testing swap
     */
    std::cout << "TESTING: Swap" << std::endl;
    int number1 = 1;
    int number2 = 2;
    SortingAlgorithms::Utility::Swap::swap(&number1, &number2);
    std::cout << "Number 1: " << number1 << " and number 2: " << number2 << std::endl << std::endl;

    /*
     * Testing counting sort
     */
    std::cout << "TESTING: CountSort" << std::endl;
    sorted2 = SortingAlgorithms::Basic::CountSort::sort(arr2, length2);

    // Print the sorted array
    std::cout << "Sorted array:   ";
    for (int i = 0; i < length2; i++)
        std::cout << sorted2[i] << " ";
    std::cout << std::endl << (SortingAlgorithms::Utility::IsSorted::isSorted(sorted2, length2) ? "List is sorted" : "List not sorted") << std::endl;

    delete[] inverted;
    delete[] sorted;
    delete[] sorted2;
    delete[] sorted3;

    return 0;
}