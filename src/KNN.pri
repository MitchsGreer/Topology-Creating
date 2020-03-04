
isEmpty(MPICXX) { MPICXX = "yes" }
isEmpty(CUDADIR) { CUDADIR = /usr/local/cuda }

LIBS += -L$${OUT_PWD}/../core -lKNNcore -lacecore -L$${CUDADIR}/lib64 -lcuda -lnvrtc  -lOpenCL -lmpi
equals(MPICXX,"yes") { LIBS += -lmpi_cxx }

INCLUDEPATH += $${PWD}/../src/
DEPENDPATH += $${PWD}/../src/
PRE_TARGETDEPS += $${OUT_PWD}/../core/libKNNcore.a

TEMPLATE = app

QMAKE_CXXFLAGS += -Wno-ignored-attributes

