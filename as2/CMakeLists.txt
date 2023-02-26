# Specify that this is a C++ project!
cmake_minimum_required(VERSION 3.8)
project(CS381 LANGUAGES CXX)

# Find the libraries we are using
set(CMAKE_MODULE_PATH "/usr/local/lib/OGRE/cmake")
find_package(OGRE)
find_package(OIS)
find_package(threads)
find_package(boost)

set(CMAKE_CXX_STANDARD 14)

# Create our executable and set all of its libraries
file(GLOB sources "src/*.cpp" "src/*.c") # Any .cpp or .c file in src will be compiled!
add_executable(as2 ${sources})
target_include_directories (as2 PUBLIC "inc/" ${OGRE_INCLUDE_DIRS} ${OGRE_Overlay_INCLUDE_DIR} ${OIS_INCLUDE_DIRS})
target_link_directories(as2 ${Boost_LIBRARY_DIRS})
target_link_libraries(as2 Threads::Threads ${Boost_LIBRARIES} ${OGRE_LIBRARY} ${OGRE_Overlay_LIBRARY} ${OIS_LIBRARY})

# Copy the CFG files into our build directory
configure_file(plugins.cfg pl(selectedEntityIndex + 1) % nEntsugins.cfg COPYONLY)
configure_file(resources.cfg resources.cfg COPYONLY)