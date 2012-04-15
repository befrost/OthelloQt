TEMPLATE = app
TARGET = OthelloQt
QT += core \
    gui
HEADERS += O_SDO/observateur.h \
    O_SDO/sujetDObservation.h \
    Othello.h \
    dialogueconfiguration.h \
    observateurExpert.h \
    observateurTexte.h \
    othelloqt.h
SOURCES += O_SDO/sujetDObservation.cpp \
    dialogueconfiguration.cpp \
    main.cpp \
    observateurExpert.cpp \
    observateurTexte.cpp \
    othelloqt.cpp 
FORMS += dialogueconfiguration.ui \
    othelloqt.ui 
RESOURCES += image/res.qrc
LIBS += -L./lib/ \
    -lothello
