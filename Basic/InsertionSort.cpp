#ifndef SORTALGORITHMS_INSERTIONSORT_H
#define SORTALGORITHMS_INSERTIONSORT_H

#include <cstdlib>
#include "../Utility/Swap.h"
#include "InsertionSort.h"

namespace MathUtilities::SortingAlgorithms::Basic::InsertionSort {
    template <typename T>
    T* sort(T* arr, int length) {

        //Allocating memory for the new array
        T* newArray = (T*)malloc(sizeof(T) * length);

        //Copying the array to the new array.
        for(int i = 0; i < length; i++) {
            newArray[i] = arr[i];
        }

        //Running the insertion sort algorithm and returning newArray pointer:
        T temp;
        for(int i = 0; i < length; i++) {
            for(int j = i; j > 0; j--) {
                if(newArray[j] < newArray[j - 1]) {
                   MathUtilities::SortingAlgorithms::Utility::Swap::swap(newArray + (j - 1), newArray + j);
                }
            }
        }
        return newArray;
    }

}

#endif
