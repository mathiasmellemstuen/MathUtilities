project(SortAlgorithms)
set(CMAKE_CXX_STANDARD 20)

add_library(SortAlgorithmsLibrary BinarySearch.h BinarySearch.cpp TimerSort.cpp TimerSort.h InsertionSort.h InsertionSort.cpp)

add_executable(SortAlgorithms testLib.cpp InvertArray.cpp InvertArray.h)
target_link_libraries(SortAlgorithms PRIVATE SortAlgorithmsLibrary)