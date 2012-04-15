/****************************************************************************
** Meta object code from reading C++ file 'othelloqt.h'
**
** Created: Sun 15. Apr 04:11:37 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../othelloqt.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'othelloqt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OthelloQt[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      25,   10,   10,   10, 0x08,
      42,   10,   10,   10, 0x08,
      57,   10,   10,   10, 0x08,
      75,   69,   10,   10, 0x08,
      90,   69,   10,   10, 0x08,
     106,   10,   10,   10, 0x08,
     115,   10,   10,   10, 0x08,
     127,  124,   10,   10, 0x08,
     148,   10,   10,   10, 0x08,
     163,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_OthelloQt[] = {
    "OthelloQt\0\0creerAction()\0nouvellePartie()\0"
    "fermerPartie()\0jouerCoup()\0actif\0"
    "obsTexte(bool)\0obsExpert(bool)\0auteur()\0"
    "regles()\0,,\0change(bool,int,int)\0"
    "sauverPartie()\0chargerPartie()\0"
};

const QMetaObject OthelloQt::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_OthelloQt,
      qt_meta_data_OthelloQt, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OthelloQt::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OthelloQt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OthelloQt::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OthelloQt))
        return static_cast<void*>(const_cast< OthelloQt*>(this));
    if (!strcmp(_clname, "SujetDObservation"))
        return static_cast< SujetDObservation*>(const_cast< OthelloQt*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int OthelloQt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: creerAction(); break;
        case 1: nouvellePartie(); break;
        case 2: fermerPartie(); break;
        case 3: jouerCoup(); break;
        case 4: obsTexte((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: obsExpert((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: auteur(); break;
        case 7: regles(); break;
        case 8: change((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 9: sauverPartie(); break;
        case 10: chargerPartie(); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
