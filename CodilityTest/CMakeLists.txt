cmake_minimum_required(VERSION 3.0.0)
project(Codilitytests VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(main main.cpp)
add_executable(helloworld helloworld.cpp)
add_executable(mainarg mainarg.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
