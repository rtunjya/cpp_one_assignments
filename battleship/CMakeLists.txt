cmake_minimum_required(VERSION 3.17)
cmake_policy(VERSION 3.17)

project(battleship)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

if(MSVC)
    # Compiler flags for Visual Studio
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX /O2")
else()
    # Compiler flags for other compilers (e.g., GCC, Clang)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -O2")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(HEADER_FILES include/types.h include/board.h include/guesser.h include/solver.h include/user_solver.h include/example_solver.h)

set(SRC_FILES src/board.cpp src/guesser.cpp src/solver.cpp src/user_solver.cpp src/example_solver.cpp)

add_executable(battleship src/main.cpp ${HEADER_FILES} ${SRC_FILES})

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(
  battleship_test
  test/battleship_test.cpp
  ${HEADER_FILES}
  ${SRC_FILES}
)

target_link_libraries(
  battleship_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(battleship_test)
