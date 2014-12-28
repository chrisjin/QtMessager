/****************************************************************************
** Meta object code from reading C++ file 'v_phone.h'
**
** Created: Sat Jun 8 12:37:31 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../v_phone.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'v_phone.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_V_Phone[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,
      18,    8,    8,    8, 0x0a,
      28,    8,    8,    8, 0x0a,
      42,    8,    8,    8, 0x0a,
      56,    8,    8,    8, 0x0a,
      68,    8,    8,    8, 0x0a,
      80,    8,    8,    8, 0x0a,
      90,    8,    8,    8, 0x0a,
     110,  106,    8,    8, 0x0a,
     142,  139,    8,    8, 0x0a,
     164,  160,    8,    8, 0x0a,
     191,  160,    8,    8, 0x0a,
     211,    8,    8,    8, 0x0a,
     225,  160,    8,    8, 0x0a,
     249,  160,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_V_Phone[] = {
    "V_Phone\0\0turnOn()\0turnOff()\0onReadyRead()\0"
    "onConnected()\0onSendBtn()\0onDestroy()\0"
    "onClose()\0onMessageList()\0a,b\0"
    "onAddPerson(QString,QString)\0ID\0"
    "onDeleteItem(int)\0Num\0onDeleteItembyNum(QString)\0"
    "onSetBlack(QString)\0onTurnonBtn()\0"
    "onDeletePerson(QString)\0"
    "onDeleteIrevByNum(QString)\0"
};

void V_Phone::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        V_Phone *_t = static_cast<V_Phone *>(_o);
        switch (_id) {
        case 0: _t->turnOn(); break;
        case 1: _t->turnOff(); break;
        case 2: _t->onReadyRead(); break;
        case 3: _t->onConnected(); break;
        case 4: _t->onSendBtn(); break;
        case 5: _t->onDestroy(); break;
        case 6: _t->onClose(); break;
        case 7: _t->onMessageList(); break;
        case 8: _t->onAddPerson((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->onDeleteItem((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->onDeleteItembyNum((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->onSetBlack((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->onTurnonBtn(); break;
        case 13: _t->onDeletePerson((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->onDeleteIrevByNum((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData V_Phone::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject V_Phone::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_V_Phone,
      qt_meta_data_V_Phone, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &V_Phone::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *V_Phone::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *V_Phone::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_V_Phone))
        return static_cast<void*>(const_cast< V_Phone*>(this));
    return QObject::qt_metacast(_clname);
}

int V_Phone::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
