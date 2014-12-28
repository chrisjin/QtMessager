/****************************************************************************
** Meta object code from reading C++ file 'v_configwidget.h'
**
** Created: Sat Jun 8 12:37:32 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../v_configwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'v_configwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_V_ConfigWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      27,   15,   15,   15, 0x0a,
      41,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_V_ConfigWidget[] = {
    "V_ConfigWidget\0\0configOK()\0onBrowseBtn()\0"
    "onOKBtn()\0"
};

void V_ConfigWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        V_ConfigWidget *_t = static_cast<V_ConfigWidget *>(_o);
        switch (_id) {
        case 0: _t->configOK(); break;
        case 1: _t->onBrowseBtn(); break;
        case 2: _t->onOKBtn(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData V_ConfigWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject V_ConfigWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_V_ConfigWidget,
      qt_meta_data_V_ConfigWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &V_ConfigWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *V_ConfigWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *V_ConfigWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_V_ConfigWidget))
        return static_cast<void*>(const_cast< V_ConfigWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int V_ConfigWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void V_ConfigWidget::configOK()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
