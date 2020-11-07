cmake_minimum_required (VERSION 3.8)

set (PROJECT_NAME "bank_system")
set (CMAKE_CXX_STANDARD 11)

project (${PROJECT_NAME})
add_executable(
        ${PROJECT_NAME}
        main.cpp
        account.cpp
        normal_account.cpp
        high_credit_account.cpp)
