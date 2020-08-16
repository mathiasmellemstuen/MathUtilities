//
// Created by Matmel on 15.08.2020.
//

#ifndef SORTALGORITHMS_SWAP_H
#define SORTALGORITHMS_SWAP_H

namespace SortingAlgorithms::Swap {
    template <typename T>
    void swap(T* x, T* y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

}
#endif //SORTALGORITHMS_SWAP_H
