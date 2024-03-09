add_subdirectory(sqapi)
add_subdirectory(Union)
add_subdirectory(Hacks)

target_link_libraries(${PROJECT_NAME} PUBLIC sqapi)
target_link_libraries(${PROJECT_NAME} PUBLIC Union)
target_link_libraries(${PROJECT_NAME} PUBLIC Hacks)