include(gtest_dependency.pri)
QT += core gui network
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread

HEADERS += \
        cliente.h \
        csvreader.h \
        graph.h \
        server.h

SOURCES += \
        Cliente_unittest.cpp \
        Server_unittest.cpp \
        cliente.cpp \
        csvreader.cpp \
        csvreader_unittest.cpp \
        graph.cpp \
        graph_unittest.cpp \
        main.cpp \
        server.cpp

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
