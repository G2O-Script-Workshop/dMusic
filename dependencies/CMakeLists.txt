add_subdirectory(squirrel)
add_subdirectory(sqrat)
add_subdirectory(Union)

target_link_libraries(SqUnionModule PUBLIC Squirrel)
target_link_libraries(SqUnionModule PUBLIC SqRat)
target_link_libraries(SqUnionModule PUBLIC Union)