# template lib config

file(
    GLOB_RECURSE
    template_LibSrc
    "src/*.cpp"
    "src/*.hpp"
)

add_library(
    template_Lib
    "${template_LibSrc}"
)

target_include_directories(
    template_Lib
    PUBLIC
    "src/"
)

if(NOT DISABLE_SANITIZERS)
    target_link_libraries(
        template_Lib
        PUBLIC
        ${SANITIZER_LIBS}
    )
endif(NOT DISABLE_SANITIZERS)

set_target_properties(
    template_Lib
    PROPERTIES
    FOLDER ${PROJECT_NAME}
)
