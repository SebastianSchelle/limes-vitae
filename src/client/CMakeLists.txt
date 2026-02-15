set(EXEC_NAME limes-client)

set(SPHY_2D_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../sphy-2d)
set(SPHY_2D_DATA ${SPHY_2D_DIR}/data)
set(LIM_DATA ${CMAKE_CURRENT_SOURCE_DIR}/../../data)
set(DEPLOY_DIR_LIMC ${CMAKE_CURRENT_SOURCE_DIR}/../../deploy)

set(SRC_LIMC
    main.cpp
    limes-client.cpp
)

set(INC_LIMC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(LIBS_LIMC
    sphy-2d-client
)

add_executable(${EXEC_NAME} ${SRC_LIMC})
target_compile_definitions(${EXEC_NAME} PRIVATE BX_CONFIG_DEBUG=1)
target_include_directories(${EXEC_NAME} PUBLIC ${INC_LIMC})
target_link_libraries(${EXEC_NAME} PUBLIC ${LIBS_LIMC})

