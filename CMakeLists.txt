project(SortAlgorithms)
set(CMAKE_CXX_STANDARD 20)

#add_library(SortAlgorithmsLibrary TimerSort.h InsertionSort.h InvertArray.h BubbleSort.h Swap.h libraryBuild.cpp)

add_executable(SortAlgorithms testLib.cpp Utility/Swap.h Utility/InvertArray.h Basic/InsertionSort.h Basic/BubbleSort.h Experimental/SleepSort.h)
#target_link_libraries(SortAlgorithms PRIVATE SortAlgorithmsLibrary)