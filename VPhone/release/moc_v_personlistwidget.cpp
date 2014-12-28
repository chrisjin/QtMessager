/****************************************************************************
** Meta object code from reading C++ file 'v_personlistwidget.h'
**
** Created: Sat Jun 8 12:37:32 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../v_personlistwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'v_personlistwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_V_PersonListWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x05,
      44,   19,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      66,   19,   19,   19, 0x0a,
      82,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_V_PersonListWidget[] = {
    "V_PersonListWidget\0\0setBlackSignal(QString)\0"
    "deletePerson(QString)\0onContextMenu()\0"
    "onDeletePerson()\0"
};

void V_PersonListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        V_PersonListWidget *_t = static_cast<V_PersonListWidget *>(_o);
        switch (_id) {
        case 0: _t->setBlackSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->deletePerson((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->onContextMenu(); break;
        case 3: _t->onDeletePerson(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData V_PersonListWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject V_PersonListWidget::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_V_PersonListWidget,
      qt_meta_data_V_PersonListWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &V_PersonListWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *V_PersonListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *V_PersonListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_V_PersonListWidget))
        return static_cast<void*>(const_cast< V_PersonListWidget*>(this));
    return QListWidget::qt_metacast(_clname);
}

int V_PersonListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void V_PersonListWidget::setBlackSignal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void V_PersonListWidget::deletePerson(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
