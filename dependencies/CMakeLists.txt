add_subdirectory(squirrel)
add_subdirectory(sqrat)
add_subdirectory(Union)

target_link_libraries(ClientModule PUBLIC Squirrel)
target_link_libraries(ClientModule PUBLIC SqRat)
target_link_libraries(ClientModule PUBLIC Union)