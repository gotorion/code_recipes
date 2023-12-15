cmake_minimum_required(VERSION 3.0)
project(testAddLib)

add_subdirectory(mathFunc)
add_executable(${PROJECT_NAME} main.cc)
target_include_directories(${PROJECT_NAME} PUBLIC
                            ${PROJECT_BINARY_DIR}
                            ${PROJECT_SOURCE_DIR}/mathFunc
    )
target_link_libraries(${PROJECT_NAME} PUBLIC myMathLib)
