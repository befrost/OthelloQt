/****************************************************************************
** Meta object code from reading C++ file 'observateurExpert.h'
**
** Created: Sun 15. Apr 19:23:38 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../observateurExpert.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'observateurExpert.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_observateurExpert[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,
      34,   31,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      63,   59,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_observateurExpert[] = {
    "observateurExpert\0\0masque(int)\0,,\0"
    "changement(bool,int,int)\0l,c\0"
    "placer(int,int)\0"
};

const QMetaObject observateurExpert::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_observateurExpert,
      qt_meta_data_observateurExpert, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &observateurExpert::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *observateurExpert::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *observateurExpert::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_observateurExpert))
        return static_cast<void*>(const_cast< observateurExpert*>(this));
    if (!strcmp(_clname, "Observateur"))
        return static_cast< Observateur*>(const_cast< observateurExpert*>(this));
    if (!strcmp(_clname, "SujetDObservation"))
        return static_cast< SujetDObservation*>(const_cast< observateurExpert*>(this));
    return QWidget::qt_metacast(_clname);
}

int observateurExpert::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: masque((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: changement((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: placer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void observateurExpert::masque(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void observateurExpert::changement(bool _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
