//
// Created by tobias on 13.08.2020.
//

#ifndef SORTALGORITHMS_TIMERSORT_H
#define SORTALGORITHMS_TIMERSORT_H

#include <vector>
#include <thread>
#include <iostream>

namespace MathUtilities::SortingAlgorithms::Experimental::SleepSort {

    static const int threadsLimit = 1900;

    template <typename T>
    T* sort(T* arr, int length) {

        // Returning a nullptr if the length exceeds the max-limit. This is for avoiding a potential stackoverflow.
        if(length > threadsLimit) {
            std::cout << "ERROR: The max length of arrays sorted by this function is: " << threadsLimit << std::endl;
            return nullptr;
        }

        // Allocating memory for the new array
        T* newArray = (T*)malloc(sizeof(T) * length);

        int* counter = new int;
        *counter = 0;

        // Defines a thread for each value in the array
        std::thread thread[length];

        for (int i = 0; i < length; i++) {

            // Sets the array position to a value
            T tVal = arr[i];
            tVal = (int)tVal; //Casting it to a int because sleep_for takes a integer.

            // Sets a thread to "sort" a number
            thread[i] = std::thread([tVal, counter, newArray]() mutable {
                // Makes the thread sleep for the length of the value, in milliseconds
                std::this_thread::sleep_for(std::chrono::milliseconds(tVal));

                // Adds the value to the next position in the array. Gets the next position from counter.
                newArray[*counter] = tVal;

                // Increment the counter by 1, so the next thread will add the value to the next index in the array.
                *counter = *counter + 1;
            });
        }

        // Waits for all threads to be done with their work and joins them with the main thread.
        for (auto &t : thread) {
            t.join();
        }

        // Clean up
        delete counter;

        // Returns the sorted array
        return newArray;
    }
}

#endif //SORTALGORITHMS_TIMERSORT_H
