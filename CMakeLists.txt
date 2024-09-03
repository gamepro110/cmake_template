# project config
cmake_minimum_required(VERSION 3.24)
project(Template_Name)

include(cmake_scripts/CPM.cmake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(VERBOSE_BUILD "use -v on compiler")
option(DISABLE_SANITIZERS "disable sanitizers for easier debugging")

if(VERBOSE_BUILD)
    add_compile_options(-v)
endif(VERBOSE_BUILD)

if(WIN32)
    add_compile_options(/W4 /WX /MP /permissive-)
else()
    add_compile_options(-O0 -Wall -Werror -Wpedantic)

    if (NOT APPLE AND NOT DISABLE_SANITIZERS)
        add_compile_options(-fsanitize=address,undefined)
        link_libraries(
            asan
            ubsan
        )
    endif (NOT APPLE AND NOT DISABLE_SANITIZERS)
endif(WIN32)

# project
add_subdirectory(lib)
add_subdirectory(app)

# doxygen building
set(BUILD_DOXYGEN_DOCS ON)
add_subdirectory(doxyDocs)

# unit tests
enable_testing() # NEEDS TO BE IN THE ROOT
add_subdirectory(tests)
