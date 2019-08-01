cmake_minimum_required(VERSION "3.14.2")

project("test")

add_executable("${PROJECT_NAME}" "main.c")

install(TARGETS "${PROJECT_NAME}" DESTINATION .)
install(FILES "main.c" DESINATION src)