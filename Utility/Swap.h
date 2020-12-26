#ifndef SORTALGORITHMS_SWAP_H
#define SORTALGORITHMS_SWAP_H

namespace MathUtilities::SortingAlgorithms::Utility::Swap {
    template <typename T>
    void swap(T* x, T* y) {
        T temp = *x;
        *x = *y;
        *y = temp;
    }
}
#endif //SORTALGORITHMS_SWAP_H
