qt_add_executable(${PROJECT_NAME} main.cpp
                                  mainwindow.h
                                  mainwindow.cpp
                                  mainwindow.ui
                                  addrecordform.h
                                  addrecordform.cpp
                                  addrecordform.ui
                                  Database.hpp
                                  Database.cpp 
                                  Employee.hpp
                                  Employee.cpp 
                                  IDatabase.hpp
                                  IDatabase.cpp
                                  Menu.hpp
                                  Menu.cpp
                                  Person.hpp
                                  Person.cpp
                                  PESELValidator.hpp
                                  PESELValidator.cpp
                                  RecordGenerator.hpp
                                  RecordGenerator.cpp
                                  showallform.h
                                  showallform.cpp
                                  showallform.ui
                                  Student.hpp
                                  Student.cpp
                                  recordgeneratorform.h recordgeneratorform.cpp recordgeneratorform.ui)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)
target_compile_options(${PROJECT_NAME} PRIVATE -Werror -Wall -Wextra -pedantic)
