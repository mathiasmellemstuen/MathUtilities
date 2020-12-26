project(MathUtilities)
set(CMAKE_CXX_STANDARD 20)

find_package(Threads)
add_library(MathUtilities Utility/InvertArray.h Utility/IsSorted.cpp Utility/IsSorted.h Utility/Swap.h SortingAlgorithms/Advanced/RadixSort.cpp SortingAlgorithms/Advanced/RadixSort.h SortingAlgorithms/Basic/BubbleSort.cpp SortingAlgorithms/Basic/BubbleSort.h SortingAlgorithms/Basic/CountSort.cpp SortingAlgorithms/Basic/CountSort.h SortingAlgorithms/Basic/InsertionSort.cpp SortingAlgorithms/Basic/InsertionSort.h SortingAlgorithms/Experimental/SleepSort.cpp SortingAlgorithms/Experimental/SleepSort.h libraryBuild.cpp)
