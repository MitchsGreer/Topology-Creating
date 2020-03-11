
include(../KNN.pri)

QT += gui widgets

TARGET = qknn

LIBS += -lacegui

SOURCES += \
    ../main.cpp \

DEFINES += GUI=1

isEmpty(PREFIX) { PREFIX = /usr/local }
program.path = $${PREFIX}/bin
program.files = $${TARGET}
INSTALLS += program
