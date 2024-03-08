set(TESTS DatabaseTest.cpp
          MenuTest.cpp
          PESELValidatorTest.cpp
          RecordGeneratorTest.cpp
          ../app/Database.cpp
          ../app/Employee.cpp
            ../app/Person.cpp
          ../app/RecordGenerator.cpp
            ../app/Student.cpp
            ../app/PESELValidator.cpp)

add_executable(${PROJECT_NAME}-ut ${TESTS})

target_compile_options(${PROJECT_NAME}-ut PRIVATE -Werror -Wall -Wextra -pedantic)
target_link_libraries(${PROJECT_NAME}-ut GTest::gtest_main)
target_include_directories(${PROJECT_NAME}-ut PRIVATE ../app)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-ut)
