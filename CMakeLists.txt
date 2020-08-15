project(SortAlgorithms)
set(CMAKE_CXX_STANDARD 20)

add_library(SortAlgorithmsLibrary TimerSort.cpp TimerSort.h InsertionSort.h InsertionSort.cpp InvertArray.cpp InvertArray.h BubbleSort.cpp BubbleSort.h)

add_executable(SortAlgorithms testLib.cpp)
target_link_libraries(SortAlgorithms PRIVATE SortAlgorithmsLibrary)