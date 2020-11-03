//
// Created by Matmel on 15.08.2020.
//

#ifndef SORTALGORITHMS_BUBBLESORT_H
#define SORTALGORITHMS_BUBBLESORT_H

#include "../Utility/Swap.h"
#include "BubbleSort.h"
namespace MathUtilities::SortingAlgorithms::Basic::BubbleSort {
    template <typename T>
    T* sort(T* arr, int length) {

        // Allocating memory for the new array
        T* newArray = (T*)malloc(sizeof(T) * length);

        //Copying the old array into the new allocation
        for(int i = 0; i < length; i++) {
            newArray[i] = arr[i];
        }

        bool swapped;

        do {
            swapped = false;

            //Looping through all elements in the array and checking if i - 1 is greater than i, if that's the case, swapping them.
            for(int i = 0; i < length; i++) {
                if(newArray[i - 1] > newArray[i]) {
                    swapped = true;
                    MathUtilities::SortingAlgorithms::Utility::Swap::swap(newArray + (i - 1), newArray + i);
                }
            }
        } while(swapped); //Algorithm is running until it has had one whole pass without any swaps. The array is sorted if this is the case.

        return newArray;
    }


}
#endif