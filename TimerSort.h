//
// Created by tobias on 13.08.2020.
//

#ifndef SORTALGORITHMS_TIMERSORT_H
#define SORTALGORITHMS_TIMERSORT_H

#include <vector>
#include <thread>

namespace SortingAlgorithms::TimeSort {
    template <typename T>
    T* sort(T* arr, int length) {
        // Creating a new vector
        std::vector<T>* vectorPointer;

        int* counter = new int;
        // Creates threads for each element in arr
        std::thread thread[length];

        for (int i = 0; i < length; i++) {
            thread[i] = std::thread([arr, i, vectorPointer, counter](){
                std::this_thread::sleep_for(std::chrono::milliseconds(arr[i]));
                vectorPointer->push_back(arr[i]);

                *counter = *counter + 1;
            });
        }

        for (auto &t : thread) {
            t.join();
        }

        std::cout << counter << std::endl;
        delete counter;

        T* newArray = (T*)malloc(sizeof(T) * length);
        return newArray;
    }
}

#endif //SORTALGORITHMS_TIMERSORT_H
