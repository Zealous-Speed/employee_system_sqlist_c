cmake_minimum_required(VERSION 3.10.0)

project(EmployeeList VERSION 0.0.1 LANGUAGES C)

add_executable(EmployeeList
    src/main.c
    src/SqList.c
)

target_include_directories(EmployeeList
    PRIVATE include
)