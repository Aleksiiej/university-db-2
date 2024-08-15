qt_add_executable(${PROJECT_NAME} main.cpp
                                  mainwindow.h
                                  mainwindow.cpp
                                  mainwindow.ui
                                  Database.hpp
                                  Database.cpp
                                  Employee.hpp
                                  Employee.cpp
                                  Person.hpp
                                  Person.cpp
                                  PESELValidator.hpp
                                  PESELValidator.cpp
                                  RecordGenerator.hpp
                                  RecordGenerator.cpp
                                  Student.hpp
                                  Student.cpp
                                  json.hpp
                                  addrecordform.h addrecordform.cpp addrecordform.ui
                                  recordgeneratorform.h recordgeneratorform.cpp recordgeneratorform.ui
                                  showallform.h showallform.cpp showallform.ui
                                  informationform.h informationform.cpp informationform.ui
                                  findrecordbysurnameform.h findrecordbysurnameform.cpp findrecordbysurnameform.ui
                                  findrecordbypeselform.h findrecordbypeselform.cpp findrecordbypeselform.ui
                                  sortrecordsbysurnameform.h sortrecordsbysurnameform.cpp sortrecordsbysurnameform.ui
                                  sortrecordsbypeselform.h sortrecordsbypeselform.cpp sortrecordsbypeselform.ui
                                  sortemployeesrecordsbysalaryform.h sortemployeesrecordsbysalaryform.cpp sortemployeesrecordsbysalaryform.ui





                              )

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)
target_compile_options(${PROJECT_NAME} PRIVATE -Werror -Wall -Wextra -pedantic)
