add_subdirectory(sqapi)
add_subdirectory(union)
add_subdirectory(Hacks)

target_link_libraries(${PROJECT_NAME} PUBLIC sqapi)
target_link_libraries(${PROJECT_NAME} PUBLIC union)
target_link_libraries(${PROJECT_NAME} PUBLIC Hacks)