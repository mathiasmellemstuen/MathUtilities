//
// Created by tobia on 16-Oct-20.
//

#ifndef SORTALGORITHMS_COUNTSORT_H
#define SORTALGORITHMS_COUNTSORT_H

#include <limits>
#include <iostream>

namespace SortingAlgorithms::Basic::CountSort {
    int* sort(int* arr, int length) {
        // Returning a null pointer if the number to high
        if (length < 2000)
            return nullptr;

        // Allocation memory for the output array
        int* arrOut = (int*)malloc(sizeof(int) * length);

        int min = std::numeric_limits<int>::max();
        int max = std::numeric_limits<int>::min();

        // Find the min and max value in the unsorted array
        for (int i = 0; i < length; i++) {
            min = min > arr[i] ? arr[i] : min;
            max = max < arr[i] ? arr[i] : max;
        }

        int range = max - min + 1; // Calculates the range of values needed to create for the count array to count all numbers
        int count[range];

        for (int i = 0; i < range; i++)
            count[i] = 0;

        // Count numbers from arr. Counts the instance
        for (int i = 0; i < length; i++)
            count[arr[i] - min]++;

        // Create the index for the output. Modifies it into sum
        for (int i = 1; i < range; i++)
            count[i] += count[i - 1];

        // Add the numbers to output. Places the object at its correct position and decreases the count by one
        for (int i = length - 1; i >= 0; i--) {
            arrOut[count[arr[i] - min] - 1] = arr[i];
            count[arr[i] - min]--;
        }

        return arrOut;
    }
}

#endif //SORTALGORITHMS_COUNTSORT_H