//
// Created by tobias on 13.08.2020.
//

#ifndef SORTALGORITHMS_TIMERSORT_H
#define SORTALGORITHMS_TIMERSORT_H

namespace TimeSort {
    template <typename T>
    T* sort(T* arr, int length) {
        // Creating a new vector
        std::vector<T>* vectorPointer;

        // Creates threads for each element in arr
        std::thread thread[length];

        for (int i = 0; i < length; i++) {
            thread[i] = std::thread([arr, i, vectorPointer](){
                std::this_thread::sleep_for(std::chrono::milliseconds(arr[i]));
                vectorPointer->push_back(arr[i]);
            });
        }

        for (auto &t : thread) {
            t.join();
        }

        T* newArray = (T*)malloc(sizeof(T) * length);
        return newArray;
    }
}

#endif //SORTALGORITHMS_TIMERSORT_H
