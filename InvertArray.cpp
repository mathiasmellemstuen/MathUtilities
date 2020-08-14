#include <iostream>
#include "InvertArray.h"


namespace InvertArray {
    template<typename T>
    T* invert(T* arr, int length) {

        //Allocating memory for the new array
        T* newArray = (T*)malloc(sizeof(T) * length);

        //Inverting the array and returning the new array:
        for(int i = length - 1; i >= 0; i--) {
            newArray[length - i - 1] = arr[i];
        }

        return newArray;
    }
}