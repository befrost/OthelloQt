TEMPLATE = app
TARGET = OthelloQt
QT += core \
    gui
HEADERS += Othello.h \
    dialogueconfiguration.h \
    othelloqt.h
SOURCES += dialogueconfiguration.cpp \
    main.cpp \
    othelloqt.cpp
FORMS += dialogueconfiguration.ui \
    othelloqt.ui
RESOURCES += 
LIBS += -L./lib/ -lothello
