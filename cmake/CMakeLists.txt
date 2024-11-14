cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(example)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Dependencies
set(RAYLIB_VERSION 4.5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

# Our Project

add_executable(${PROJECT_NAME} ../main.cpp ../src/creatureSrc/Creature.cpp ../include/gui_lib/raygui.h ../include/CreatureIncludes/movement.h ../src/creatureSrc/Movement.cpp ../src/creatureSrc/Seeing.cpp ../include/foodInclude/Food.h ../src/foodSrc/Food.cpp ../include/foodInclude/foodContainer.h ../src/foodSrc/FoodContainer.cpp ../include/EntityFactoryInclude/creatureFactory.h ../src/EntityFactorySrc/CreatureFactory.cpp ../include/CreatureIncludes/creatureContainer/CreatureContainer.h ../src/creatureSrc/creatureContainerSrc/CreatureContainer.cpp ../include/CreatureIncludes/Movable.h ../src/creatureSrc/Movable.cpp ../include/CreatureIncludes/Genome.h ../src/creatureSrc/Genome.cpp ../include/SimulationInclude/Simulation.h ../src/SimulationSrc/Simulation.cpp ../include/IObserver.h ../include/DataManagerInc/dataManager.h ../src/DataManagerSrc/DataManager.cpp ../include/ObserverSubject.h)
#set(raylib_VERBOSE 1)xq
target_link_libraries(${PROJECT_NAME} raylib)



# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()