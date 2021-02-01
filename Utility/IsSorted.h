#ifndef SORTINGALGORITHMS_ISSORTED_H
#define SORTINGALGORITHMS_ISSORTED_H

#include <iostream>

namespace MathUtilities::SortingAlgorithms::Utility::IsSorted {

    bool isSorted(int* arr, int length) {

        for (int i = 0; i < length - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                std::cout << "false " << arr[i] << " - " << arr[i + 1] << " Index: " << i << std::endl;
                return false;
            }
        }
        return true;
    };
}
#endif