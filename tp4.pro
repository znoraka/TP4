QMAKE_MAC_SDK = macosx10.11

QMAKE_CXXFLAGS += -stdlib=libc++ -std=c++11

INCLUDEPATH += /opt/local/include
LIBS += -stdlib=libc++

SOURCES += $$PWD/openglwindow.cpp \
    main.cpp \
    trianglewindow.cpp
HEADERS += $$PWD/openglwindow.h \
    trianglewindow.h

target.path = .

INSTALLS += target

RESOURCES += gestionnaire.qrc
