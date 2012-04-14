TEMPLATE = app
TARGET = OthelloQt
QT += core \
    gui
HEADERS += observateurExpert.h \
    O_SDO/observateur.h \
    O_SDO/sujetDObservation.h \
    observateurTexte.h \
    Othello.h \
    dialogueconfiguration.h \
    othelloqt.h
SOURCES += observateurExpert.cpp \
    O_SDO/sujetDObservation.cpp \
    observateurTexte.cpp \
    dialogueconfiguration.cpp \
    main.cpp \
    othelloqt.cpp
FORMS += dialogueconfiguration.ui \
    othelloqt.ui
RESOURCES += image/res.qrc
LIBS += -L./lib/ \
    -lothello
