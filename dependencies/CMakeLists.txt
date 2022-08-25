add_subdirectory(squirrel)
add_subdirectory(sqrat)
add_subdirectory(Union)
add_subdirectory(Hacks)

target_link_libraries(union-template PUBLIC Squirrel)
target_link_libraries(union-template PUBLIC SqRat)
target_link_libraries(union-template PUBLIC Union)
target_link_libraries(union-template PUBLIC Hacks)