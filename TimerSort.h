//
// Created by tobias on 13.08.2020.
//

#ifndef SORTALGORITHMS_TIMERSORT_H
#define SORTALGORITHMS_TIMERSORT_H

#include <vector>
#include <thread>
#include "iostream"

namespace SortingAlgorithms::TimeSort {
    template <typename T>
    T* sort(T* arr, int length) {

        T* newArray = (T*)malloc(sizeof(T) * length);

        int* counter = new int;

        *counter = 0;

        std::thread thread[length];

        for (int i = 0; i < length; i++) {
            int tVal = arr[i];

            thread[i] = std::thread([tVal, counter, newArray]() mutable {
                std::this_thread::sleep_for(std::chrono::milliseconds(tVal));

                newArray[*counter] = tVal;

                *counter = *counter + 1;
            });
        }

        for (auto &t : thread) {
            t.join();
        }

        delete counter;
        return newArray;
    }
}

#endif //SORTALGORITHMS_TIMERSORT_H
