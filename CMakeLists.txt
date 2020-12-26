project(MathUtilities)
set(CMAKE_CXX_STANDARD 20)

find_package(Threads)
add_library(MathUtilities Utility/InvertArray.h Utility/IsSorted.cpp Utility/IsSorted.h Utility/Swap.h Advanced/RadixSort.cpp Advanced/RadixSort.h Basic/BubbleSort.cpp Basic/BubbleSort.h Basic/CountSort.cpp Basic/CountSort.h Basic/InsertionSort.cpp Basic/InsertionSort.h Experimental/SleepSort.cpp Experimental/SleepSort.h libraryBuild.cpp)
