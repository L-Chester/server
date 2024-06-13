########
#版本需求
cmake_minimum_required(VERSION 3.25)
#项目名称
project(simServer)
#设置变量A 值B
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CPP_COMPILER g++)
set(CMAKE_CPP_STANDARD 14)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#
add_compile_options(-std=c++14 -Wall -g)

#设置头文件目录(即包含目录)
#include_directories(DIR1 DIR2 ...)
include_directories(${PROJECT_SOURCE_DIR}/inc)

#搜索A中的源文件并存储在变量B中
#aux_source_directory(A B)
aux_source_directory(${PROJECT_SOURCE_DIR}/src SOURCE_LIST)

#生成动态/静态库(.so/.a)
#add_library(${SOURC_LIST} SHARED ${SOURCE_LIST})
#add_library(crtName STATIC ${SOURCE})
#循环获取源文件并生成对应动态库
foreach(FILE ${SOURCE_LIST})
    #获取文件名的特定部分：变量 完整文件名 截取模式
    get_filename_component(Lib_Name ${FILE} NAME_WE)
    add_library(${Lib_Name} SHARED ${FILE})
endforeach()


#从目标文件夹查找库并存储到变量中
#find_library(var lib_name dir)
find_library(LIB ${SOURCE_LIST} ${PROJECT_SOURCE_DIR}/lib)

#生成执行文件
add_executable(simServer ${SOURCE_LIST})

#把库链接到目标文件中
#target_link_libraries(target lib_name)
#target_link_libraries(createName ${LIB})