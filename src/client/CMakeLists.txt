set(EXEC_NAME limes-client)

set(SPHY_2D_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../sphy-2d)
set(SPHY_2D_DATA ${SPHY_2D_DIR}/data)
set(DEPLOY_DIR_LIMC ${CMAKE_CURRENT_SOURCE_DIR}/../../deploy/client)

set(SRC_LIMC
    main.cpp
    limes-client.cpp
)

set(INC_LIMC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${INC_IRS}
)

set(LIBS_LIMC
    sphy-2d-client
)

add_executable(${EXEC_NAME} ${SRC_LIMC})
target_compile_definitions(${EXEC_NAME} PRIVATE BX_CONFIG_DEBUG=1)
target_include_directories(limes-client PUBLIC ${INC_LIMC})
target_link_libraries(${EXEC_NAME} PUBLIC ${LIBS_LIMC})
add_dependencies(${EXEC_NAME} cpm_limc)

message(STATUS "client deploy directory: ${DEPLOY_DIR_TC}")

add_custom_command(TARGET ${EXEC_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${EXEC_NAME}> ${DEPLOY_DIR_LIMC}/${EXEC_NAME}
)

add_custom_target(cpm_limc ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${SPHY_2D_DATA} ${DEPLOY_DIR_LIMC}
)
