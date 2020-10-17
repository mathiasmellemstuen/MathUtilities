//
// Created by Tobias Hallingstad on 16/10/2020.
//

#ifndef SORTALGORITHMS_ISSORTED_H
#define SORTALGORITHMS_ISSORTED_H

namespace SortingAlgorithms::Utility::IsSorted {
    bool isSorted(int* arr, int length) {

        for (int i = 0; i < length - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                std::cout << "false " << arr[i] << " - " << arr[i + 1] << " Index: " << i << std::endl;
                return false;
            }
        }
        return true;
    }
}

#endif //SORTALGORITHMS_ISSORTED_H
