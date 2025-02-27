cmake_minimum_required(VERSION 3.10.0)

project(test250221 VERSION 0.1.0 LANGUAGES C CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 创建可执行文件
add_executable(kltest main.cpp)

# 收集 src 目录下的所有 .cpp 文件并添加到 kltest 目标中
file(GLOB SOURCES "src/*.cpp")
target_sources(kltest PRIVATE ${SOURCES})

# 使用 target_include_directories 来指定头文件目录
target_include_directories(kltest PRIVATE 
    ${PROJECT_SOURCE_DIR}/head
    ${PROJECT_SOURCE_DIR}/FR/include
)

# 使用 find_library 或直接在 target_link_libraries 中指定完整路径
# 假设 fairino 库位于 ${PROJECT_SOURCE_DIR}/FR/x86/libfairino.so
target_link_libraries(kltest 
    "${PROJECT_SOURCE_DIR}/FR/x86/libfairino.so"
)

# 如果需要设置运行时库路径，确保程序能找到 .so 文件
set_target_properties(kltest PROPERTIES
    INSTALL_RPATH "${PROJECT_SOURCE_DIR}/FR/x86"
    BUILD_WITH_INSTALL_RPATH TRUE
)