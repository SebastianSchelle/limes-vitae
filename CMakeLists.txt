cmake_minimum_required(VERSION 3.14...4.1)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
    limes-vitae
    VERSION 1.0
    LANGUAGES CXX)

set(INC_IRS 
    ${CMAKE_SOURCE_DIR}/src/client
)

# add third party libraries
add_subdirectory(sphy-2d)
add_subdirectory(src/client)
add_subdirectory(src/server)