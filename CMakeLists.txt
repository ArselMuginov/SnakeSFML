cmake_minimum_required (VERSION 3.8)
project ("SnakeSFML")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 REQUIRED COMPONENTS graphics)

include_directories(include)

add_executable(${PROJECT_NAME} "")
add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} sfml-graphics)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
install(DIRECTORY resources DESTINATION .)

# Forward DLLs path to script
if(${CMAKE_CONFIGURATION_TYPES} STREQUAL "Debug")
    install(CODE "set(DLL_PATH \"${PROJECT_SOURCE_DIR}/extlibs/bin/Debug\")")
elseif(${CMAKE_CONFIGURATION_TYPES} STREQUAL "Release")
    install(CODE "set(DLL_PATH \"${PROJECT_SOURCE_DIR}/extlibs/bin/Release\")")
endif()

install(SCRIPT bundle.cmake)
