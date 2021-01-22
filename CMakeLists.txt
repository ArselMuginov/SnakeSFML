cmake_minimum_required(VERSION 3.13)
project("SnakeSfml")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 REQUIRED COMPONENTS graphics)

include_directories(src)
add_executable(${PROJECT_NAME} "")
add_subdirectory(src)
target_link_libraries(${PROJECT_NAME} sfml-graphics)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)

if(MSVC)
	# Ignore inline stuff, defined as deleted, bytes padding
	target_compile_options(${PROJECT_NAME} PRIVATE /wd4514 /wd4625 /wd4626 /wd4710 /wd4820 /wd5026 /wd5027)
endif()

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
install(DIRECTORY data DESTINATION .)

# Forward executable & DLL path to script
install(CODE "set(EXE_PATH \"${CMAKE_INSTALL_PREFIX}/bin/${PROJECT_NAME}${CMAKE_EXECUTABLE_SUFFIX}\")")
install(CODE "set(DLL_PATH \"${PROJECT_SOURCE_DIR}/extlibs/bin/*\")")
install(SCRIPT bundle.cmake)
