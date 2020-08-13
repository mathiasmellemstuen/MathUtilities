//
// Created by matmel on 13.08.2020.
//

#include <iostream>
#include "InvertArray.h"


namespace InvertArray {
    template<typename T>
    T* invert(T* arr, int length) {

        //Allocating memory for the new array
        T* newArray = (T*)malloc(sizeof(T) * length);

        //Making length = length - 1 if length is a odd number.
        length = length % 2 ? length : length - 1;

        //Inverting the array.
        for(int i = 0; i < length; i++) {
            newArray[i] = arr[length - i];
        }

        return newArray;
    }
}