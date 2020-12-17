cmake_minimum_required (VERSION 3.13)
project ("SnakeSfml")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 REQUIRED COMPONENTS graphics)

include_directories(src)
add_executable(${PROJECT_NAME} "")
add_subdirectory(src)
target_link_libraries(${PROJECT_NAME} sfml-graphics)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
install(DIRECTORY data DESTINATION .)

# Forward DLLs path to script
install(CODE "set(DLL_PATH \"${PROJECT_SOURCE_DIR}/extlibs/bin/*\")")
install(SCRIPT bundle.cmake)
