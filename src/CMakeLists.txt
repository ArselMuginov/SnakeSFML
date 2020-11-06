file(GLOB SOURCES "*.cpp")
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

add_subdirectory(Localization)
add_subdirectory(TileMap)
add_subdirectory(UI)
