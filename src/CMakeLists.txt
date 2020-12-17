set(SOURCES Game.cpp Gui.cpp Main.cpp)
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

add_subdirectory(Localization)
add_subdirectory(Resource)
add_subdirectory(TileMap)
add_subdirectory(whereami)
add_subdirectory(Widgets)
