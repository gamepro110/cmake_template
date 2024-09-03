# executable config

file(
    GLOB_RECURSE
    template_AppSrc
    src/*.cpp
    src/*.hpp
)

add_executable(
    template_App
    ${template_AppSrc}
)

target_link_libraries(
    template_App
    PUBLIC
    template_Lib
)

if(NOT DISABLE_SANITIZERS)
    target_link_libraries(
        template_App
        PUBLIC
        ${SANITIZER_LIBS}
    )
endif(NOT DISABLE_SANITIZERS)

set_target_properties(
    template_App
    PROPERTIES
    FOLDER ${PROJECT_NAME}
)
