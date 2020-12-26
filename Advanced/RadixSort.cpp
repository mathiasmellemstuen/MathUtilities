#ifndef SORTALGORITHMS_RADIXSORT_H
#define SORTALGORITHMS_RADIXSORT_H

#include "iostream"
#include "RadixSort.h"

namespace MathUtilities::SortingAlgorithms::Advanced::RadixSort {
    int* sort(const int* arr, int length) {

        int* arrOut = (int*)malloc(sizeof(int) * length);
        //int arrOut[length];

        for (int i = 0; i < length; i++)
            arrOut[i] = arr[i];

        // Gets max value of the array
        int max = arr[0];
        for (int i = 1; i < length; i++)
            max = max > arr[i] ? max : arr[i];

        // Sorting part
        for (int exp = 1; max / exp > 0; exp *= 10) {   // exp is what part of the number is sorted by. exp = 10^i.
            int output[length];
            for (int i = 0; i < length; i++)
                output[i] = 0;

            // Because we use the decimal system, we only need to store the number from 0 to 9.
            // So sett count to all 0
            int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

            // Count the occurrences of a number in the exponent position
            for (int i = 0; i < length; i++)
                count[(arrOut[i] / exp) % 10]++;

            // Create the index for the number
            for (int i = 1; i < 10; i++)
                count[i] += count[i - 1];

            // Move the full number to the index position calculated above, starting from the back. Then decrees the index by 1
            for (int i = length - 1; i >= 0; i--) {
                output[count[(arrOut[i] / exp) % 10] - 1] = arrOut[i];
                count[(arrOut[i] / exp) % 10]--;
            }

            for (int i = 0; i < length; i++)
                arrOut[i] = output[i];
        }

        return arrOut;
    }
}

#endif //SORTALGORITHMS_RADIXSORT_H
