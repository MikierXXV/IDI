/****************************************************************************
** Meta object code from reading C++ file 'MyLabel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Galton/MyLabel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyLabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyLabel_t {
    QByteArrayData data[10];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyLabel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyLabel_t qt_meta_stringdata_MyLabel = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MyLabel"
QT_MOC_LITERAL(1, 8, 6), // "borrar"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 9), // "siguiente"
QT_MOC_LITERAL(4, 26, 8), // "esquerra"
QT_MOC_LITERAL(5, 35, 5), // "dreta"
QT_MOC_LITERAL(6, 41, 5), // "reset"
QT_MOC_LITERAL(7, 47, 10), // "changebola"
QT_MOC_LITERAL(8, 58, 12), // "probabilidad"
QT_MOC_LITERAL(9, 71, 5) // "jugar"

    },
    "MyLabel\0borrar\0\0siguiente\0esquerra\0"
    "dreta\0reset\0changebola\0probabilidad\0"
    "jugar"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyLabel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyLabel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->borrar(); break;
        case 1: _t->siguiente(); break;
        case 2: _t->esquerra(); break;
        case 3: _t->dreta(); break;
        case 4: _t->reset(); break;
        case 5: _t->changebola(); break;
        case 6: _t->probabilidad(); break;
        case 7: _t->jugar(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyLabel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLabel::borrar)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyLabel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLabel::siguiente)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MyLabel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLabel::esquerra)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MyLabel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLabel::dreta)) {
                *result = 3;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MyLabel::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_MyLabel.data,
    qt_meta_data_MyLabel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyLabel.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int MyLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MyLabel::borrar()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MyLabel::siguiente()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MyLabel::esquerra()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MyLabel::dreta()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
