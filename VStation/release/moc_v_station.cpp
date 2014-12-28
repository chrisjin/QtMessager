/****************************************************************************
** Meta object code from reading C++ file 'v_station.h'
**
** Created: Wed Jul 4 00:37:07 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../v_station.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'v_station.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_V_Station[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      25,   10,   10,   10, 0x0a,
      46,   42,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_V_Station[] = {
    "V_Station\0\0onReadyRead()\0onDisconnected()\0"
    "err\0onSocketError(QAbstractSocket::SocketError)\0"
};

void V_Station::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        V_Station *_t = static_cast<V_Station *>(_o);
        switch (_id) {
        case 0: _t->onReadyRead(); break;
        case 1: _t->onDisconnected(); break;
        case 2: _t->onSocketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData V_Station::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject V_Station::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_V_Station,
      qt_meta_data_V_Station, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &V_Station::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *V_Station::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *V_Station::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_V_Station))
        return static_cast<void*>(const_cast< V_Station*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int V_Station::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
