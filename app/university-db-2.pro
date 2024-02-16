QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addrecordform.cpp \
    main.cpp \
    mainwindow.cpp \
    Database.cpp \
    Employee.cpp \
    IDatabase.cpp \
    Menu.cpp \
    Person.cpp \
    PESELValidator.cpp \
    RecordGenerator.cpp \
    Student.cpp \
    showallform.cpp

HEADERS += \
    addrecordform.h \
    mainwindow.h \
    Database.hpp \
    Employee.hpp \
    IDatabase.hpp \
    Menu.hpp \
    Person.hpp \
    PESELValidator.hpp \
    RecordGenerator.hpp \
    Student.hpp \
    showallform.h

FORMS += \
    addrecordform.ui \
    mainwindow.ui \
    showallform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
