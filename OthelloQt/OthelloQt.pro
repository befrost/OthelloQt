TEMPLATE = app
TARGET = OthelloQt
QT += core \
    gui
HEADERS += dialogueconfiguration.h \
    lib/Othello_lib.h \
    othelloqt.h
SOURCES += dialogueconfiguration.cpp \
    main.cpp \
    othelloqt.cpp
FORMS += dialogueconfiguration.ui \
    othelloqt.ui
RESOURCES += 
