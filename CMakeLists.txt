project(SortAlgorithms)
set(CMAKE_CXX_STANDARD 20)

#add_library(SortAlgorithmsLibrary TimerSort.h InsertionSort.h InvertArray.h BubbleSort.h Swap.h libraryBuild.cpp)

add_executable(SortAlgorithms testLib.cpp)
#target_link_libraries(SortAlgorithms PRIVATE SortAlgorithmsLibrary)