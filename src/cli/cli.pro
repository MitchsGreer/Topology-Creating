
include(../KNN.pri)

TARGET = knn

LIBS += -laceconsole

SOURCES += \
    ../main.cpp \

DEFINES += GUI=0

isEmpty(PREFIX) { PREFIX = /usr/local }
program.path = $${PREFIX}/bin
program.files = $${TARGET}
INSTALLS += program
