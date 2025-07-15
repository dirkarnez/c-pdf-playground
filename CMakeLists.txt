cmake_minimum_required(VERSION 3.14)

project("c-pdf-playground" C)

add_executable(${PROJECT_NAME}
    "src/main.c"
)

target_link_options(${PROJECT_NAME} PRIVATE "-static")
