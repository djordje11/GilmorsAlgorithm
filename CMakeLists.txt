cmake_minimum_required(VERSION 3.5.1)
project (gilmores-procedure)

set(FORMULAS_SRC
    src/term.cpp
)
set(MAIN_SRC
    main.cpp
)

set(G++_VERSION "-std=c++17")
set(FLAGS "-g")
include_directories(
   inc
)
add_definitions(${G++_VERSION})
add_definitions(${FLAGS})

add_executable(${PROJECT_NAME}
    ${FORMULAS_SRC}
    ${MAIN_SRC}
)