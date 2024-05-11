cmake_minimum_required(VERSION 3.20)
enable_language(C CXX)
message("Hello world")
message(WARNING "Hello world")
message(STATUS "Hello world")  # with -- prefix
# message(FATAL_ERROR) # terminal
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 以上在 project 之前
project(demo LANGUAGES NONE)

if (NOT CMAKE_BUILD_TYPE) 
    set(CMAKE_BUILD_TYPE Release)
endif()

if (WIN32)
    add_definitions(-DNOMINMAX -D_USE_MATH_DEFINES)
endif()
# GLOB 只能单个目录指定
# GLOB_RECURSE 会把 build 下临时的 cpp 文件也加进来, 所以源码不要和 build 放在同一级目录
# file(GLOB SRC CONFIGURE_DEPENDS *.cpp)

aux_source_directory(./src SRC)

# set(BUILD_SHARED_LIBS ON) 不指定的话默认都是静态库
add_library(add SHARED ./src/add.cpp)
# 设置 target 的属性
set_property(TARGET add PROPERTY LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set_property(TARGET add PROPERTY CXX_STANDARD 17)

add_executable(demo)
set_target_properties(demo PROPERTIES
    WIN32_EXECUTABLE ON
    LINK_WHAT_YOU_USE ON # 告诉编译器不要自动剔除没有引用符号的链接库
)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
# set(SRC main.cpp)

target_sources(demo PUBLIC ${SRC})
target_link_libraries(demo PUBLIC Threads::Threads)
# 根据系统定义程序里的宏定义
if (CMAKE_SYSTEM_NAME MATCHES "Windows")
    target_compile_definitions(demo PUBLIC MICRO_NAME="Windows System")
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
    target_compile_definitions(demo PUBLIC MICRO_NAME="Linux System")
elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    target_compile_definitions(demo PUBLIC MICRO_NAME="MacOS System")
endif()

if(WIN32) # 和上面等价
elseif(UNIX AND NOT APPLE)
elseif(APPLE)
    message("Apple")
endif()

message(${CMAKE_SYSTEM_NAME})
