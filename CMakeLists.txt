# 最小的 CMake 版本要求
cmake_minimum_required(VERSION 3.10)

# 项目名称和版本
project(AAP VERSION 1.0)

# 设置全局的 C++ 标准为 C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Boost REQUIRED COMPONENTS log log_setup unit_test_framework program_options random)

# 包含头文件目录
include_directories(${CMAKE_BINARY_DIR}/include)
include_directories(${Boost_INCLUDE_DIRS})

# 添加一个配置文件，用于保存项目版本信息
configure_file(config.h.in config.h)

# 自动收集src/目录下所有cpp文件
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# 移除main.cpp
list(REMOVE_ITEM SRC_FILES ${CMAKE_SOURCE_DIR}/src/main.cpp)
set(MAIN_FILE "${CMAKE_SOURCE_DIR}/src/main.cpp")
# 添加可执行文件 - 程序主文件暂时可以为空或用一个占位
# 后续主人可以在src/main.cpp中增加内容
add_executable(AAP ${SRC_FILES} ${MAIN_FILE})

# 将 config.h 文件包含到编译中
target_include_directories(AAP PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/include")

# 链接Boost库
target_link_libraries(AAP Boost::log_setup Boost::log Boost::program_options)

# 测试部分
enable_testing()

# 自动收集 tests/ 目录下所有的 cpp 测试文件
file(GLOB_RECURSE TEST_FILES tests/*.cpp)

# 为每个测试文件创建独立的可执行文件并添加测试
foreach(test_src ${TEST_FILES})
    # 获取文件名（去掉路径）
    get_filename_component(test_name ${test_src} NAME_WE)
    add_executable(${test_name} ${test_src} ${SRC_FILES})
    target_link_libraries(${test_name} Boost::log_setup Boost::log Boost::unit_test_framework)
    target_include_directories(${test_name} PRIVATE ${PROJECT_SOURCE_DIR}/include)
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()