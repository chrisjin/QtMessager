/****************************************************************************
** Meta object code from reading C++ file 'v_phonegui.h'
**
** Created: Sat Jun 8 12:37:31 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../v_phonegui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'v_phonegui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_V_PhoneGUI[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      26,   11,   11,   11, 0x05,
      49,   45,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      87,   82,   11,   11, 0x0a,
     117,   82,   11,   11, 0x0a,
     150,   11,   11,   11, 0x0a,
     164,   11,   11,   11, 0x0a,
     180,   11,   11,   11, 0x0a,
     196,   11,   11,   11, 0x0a,
     220,   11,   11,   11, 0x0a,
     234,   11,   11,   11, 0x0a,
     245,   11,   11,   11, 0x0a,
     253,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_V_PhoneGUI[] = {
    "V_PhoneGUI\0\0closeSignal()\0enterMessageList()\0"
    "a,b\0addPersonSignal(QString,QString)\0"
    "item\0onItemClick(QListWidgetItem*)\0"
    "onMailBoxCheck(QListWidgetItem*)\0"
    "onBackClick()\0onAddBtnClick()\0"
    "onDelBtnClick()\0onAddFinishedBtnClick()\0"
    "onPersonAdd()\0onConfig()\0onTip()\0"
    "onConfigOK()\0"
};

void V_PhoneGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        V_PhoneGUI *_t = static_cast<V_PhoneGUI *>(_o);
        switch (_id) {
        case 0: _t->closeSignal(); break;
        case 1: _t->enterMessageList(); break;
        case 2: _t->addPersonSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->onItemClick((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->onMailBoxCheck((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->onBackClick(); break;
        case 6: _t->onAddBtnClick(); break;
        case 7: _t->onDelBtnClick(); break;
        case 8: _t->onAddFinishedBtnClick(); break;
        case 9: _t->onPersonAdd(); break;
        case 10: _t->onConfig(); break;
        case 11: _t->onTip(); break;
        case 12: _t->onConfigOK(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData V_PhoneGUI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject V_PhoneGUI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_V_PhoneGUI,
      qt_meta_data_V_PhoneGUI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &V_PhoneGUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *V_PhoneGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *V_PhoneGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_V_PhoneGUI))
        return static_cast<void*>(const_cast< V_PhoneGUI*>(this));
    return QWidget::qt_metacast(_clname);
}

int V_PhoneGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void V_PhoneGUI::closeSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void V_PhoneGUI::enterMessageList()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void V_PhoneGUI::addPersonSignal(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
