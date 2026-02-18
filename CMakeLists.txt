cmake_minimum_required(VERSION 3.14...4.1)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
    limes-vitae
    VERSION 1.0
    LANGUAGES CXX)

set(GAME_NAME "limes" CACHE STRING "Game name used for save files and binaries")

set(INC_IRS 
    ${CMAKE_SOURCE_DIR}/src/client
)

# add third party libraries
add_subdirectory(sphy-2d)
add_subdirectory(src/client)
add_subdirectory(src/server)

# Deploy script path
set(DEPLOY_SCRIPT ${CMAKE_SOURCE_DIR}/scripts/deploy.sh)
set(DEPLOY_DIR ${CMAKE_SOURCE_DIR}/deploy)

# Find bash
find_program(BASH_EXECUTABLE bash)
if(NOT BASH_EXECUTABLE)
    message(FATAL_ERROR "bash not found")
endif()

# Custom target to run deploy script
# Pass build directory and executable paths to the script
add_custom_target(deploy
    COMMAND ${BASH_EXECUTABLE} ${DEPLOY_SCRIPT} ${DEPLOY_DIR} ${CMAKE_BINARY_DIR} "$<TARGET_FILE:limes-client>" "$<TARGET_FILE:limes-server>"
    DEPENDS limes-client limes-server
    COMMENT "Deploying modules and executables to ${DEPLOY_DIR}"
)