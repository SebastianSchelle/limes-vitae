set(EXEC_NAME limes-server)

set(SPHY_2D_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../sphy-2d)
set(SPHY_2D_DATA ${SPHY_2D_DIR}/data)
set(DEPLOY_DIR_LIMS ${CMAKE_CURRENT_SOURCE_DIR}/../../deploy)

set(SRC_LIMS
    main.cpp
    limes-server.cpp
)

set(INC_LIMS
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(LIBS_LIMS
    sphy-2d-server
)

add_executable(${EXEC_NAME} ${SRC_LIMS})
target_include_directories(${EXEC_NAME} PUBLIC ${INC_LIMS})
target_link_libraries(${EXEC_NAME} PUBLIC ${LIBS_LIMS})

