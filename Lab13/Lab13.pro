include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

SOURCES += \
        bankaccount.cpp \
        bankaccountTests.cpp \
        functions.cpp \
        functionsTest.cpp \
        main.cpp         \
        number.cpp \
        numberTests.cpp

HEADERS += \
    bankaccount.h \
    functions.h \
    number.h
