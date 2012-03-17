TEMPLATE = app
TARGET = OthelloQt
QT += core \
    gui
HEADERS += observateurTexte.h \
    Othello.h \
    dialogueconfiguration.h \
    othelloqt.h
SOURCES += observateurTexte.cpp \
    dialogueconfiguration.cpp \
    main.cpp \
    othelloqt.cpp
FORMS += dialogueconfiguration.ui \
    othelloqt.ui
RESOURCES += 
LIBS += -L./lib/ \
    -lothello
