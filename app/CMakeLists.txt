cmake_minimum_required(VERSION 3.23.0)
project(university-db-2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

find_package(GTest REQUIRED)
enable_testing()

set(SRC_LIST
    main.cpp
    Database.cpp
    Person.cpp
    Student.cpp
    Employee.cpp
    PESELValidator.cpp
    RecordGenerator.cpp
    Menu.cpp
)

set(SRC_LIST_UT
    Database.cpp
    Person.cpp
    Student.cpp
    Employee.cpp
    PESELValidator.cpp
    RecordGenerator.cpp
    Menu.cpp
    ./gtest/DatabaseTest.cpp
    ./gtest/MenuTest.cpp
    ./gtest/PESELValidatorTest.cpp
    ./gtest/RecordGeneratorTest.cpp    
)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wpedantic -Wextra -Werror)

enable_testing()
include(GoogleTest)
add_executable(${PROJECT_NAME}-ut ${SRC_LIST_UT})
target_link_libraries(${PROJECT_NAME}-ut gtest_main gmock)
add_test(Test ${PROJECT_NAME}-ut)