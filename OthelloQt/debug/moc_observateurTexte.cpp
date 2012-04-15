/****************************************************************************
** Meta object code from reading C++ file 'observateurTexte.h'
**
** Created: Sun 15. Apr 04:11:35 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../observateurTexte.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'observateurTexte.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_observateurTexte[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_observateurTexte[] = {
    "observateurTexte\0\0masque()\0"
};

const QMetaObject observateurTexte::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_observateurTexte,
      qt_meta_data_observateurTexte, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &observateurTexte::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *observateurTexte::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *observateurTexte::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_observateurTexte))
        return static_cast<void*>(const_cast< observateurTexte*>(this));
    if (!strcmp(_clname, "Observateur"))
        return static_cast< Observateur*>(const_cast< observateurTexte*>(this));
    return QLabel::qt_metacast(_clname);
}

int observateurTexte::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: masque(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void observateurTexte::masque()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
