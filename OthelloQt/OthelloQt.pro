TEMPLATE = app
TARGET = OthelloQt
QT += core \
    gui
HEADERS += O_SDO/observateur.h \
    O_SDO/sujetDObservation.h \
    observateurTexte.h \
    Othello.h \
    dialogueconfiguration.h \
    othelloqt.h
SOURCES += O_SDO/sujetDObservation.cpp \
    O_SDO/sujetDObservation.cpp \
    observateurTexte.cpp \
    dialogueconfiguration.cpp \
    main.cpp \
    othelloqt.cpp
FORMS += dialogueconfiguration.ui \
    othelloqt.ui
RESOURCES += 
LIBS += -L./lib/ \
    -lothello
