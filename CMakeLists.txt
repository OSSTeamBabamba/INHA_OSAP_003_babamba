cmake_minimum_required(VERSION 3.21)
project(AVLTreeSTL)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "--coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} --coverage")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,-no_warn_duplicate_libraries")



find_package(GTest REQUIRED)

add_library(common_library node.cc tree_node.cc avl_tree.cc avl_tree_set_adpater.cc avl_tree_set_adapter.h OSAP_003_babamba_source.cpp)


add_executable(test_insert tests/insert_test.cc )
target_link_libraries(test_insert common_library ${GTEST_LIBRARIES} pthread )

add_executable(test_erase tests/erase_test.cc )
target_link_libraries(test_erase common_library ${GTEST_LIBRARIES} pthread )

add_executable(test_empty tests/empty_test.cc)
target_link_libraries(test_empty common_library ${GTEST_LIBRARIES} pthread )

add_executable(test_size tests/size_test.cpp)
target_link_libraries(test_size common_library ${GTEST_LIBRARIES} pthread )

add_executable(test_maximum tests/maximum_test.cc)
target_link_libraries(test_maximum common_library ${GTEST_LIBRARIES} pthread )

add_executable(test_minimum tests/minimum_test.cc)
target_link_libraries(test_minimum common_library ${GTEST_LIBRARIES} pthread )

add_executable(test_rank tests/rank_test.cc)
target_link_libraries(test_minimum common_library ${GTEST_LIBRARIES} pthread )


file(
        WRITE ${CMAKE_BINARY_DIR}/start.sh "#!/bin/bash\n"
        "cd CMakeFiles/common_library.dir && gcov CMakeFiles/common_library.dir/avl_tree.cpp.gcda && lcov --rc lcov_branch_coverage=1 --capture --directory . --output-file out.info && genhtml out.info --branch-coverage --output-directory /univ/gcovOutPut"
)

add_executable(avl_tree_stl main.cc)
target_link_libraries(avl_tree_stl common_library)

add_executable(for_test_server OSAP_003_babamba_source.cpp)


