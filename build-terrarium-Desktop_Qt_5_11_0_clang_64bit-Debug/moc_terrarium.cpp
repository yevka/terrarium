/****************************************************************************
** Meta object code from reading C++ file 'terrarium.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../terrarium.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'terrarium.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Terrarium_t {
    QByteArrayData data[13];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Terrarium_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Terrarium_t qt_meta_stringdata_Terrarium = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Terrarium"
QT_MOC_LITERAL(1, 10, 7), // "newGame"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 6), // "setFon"
QT_MOC_LITERAL(4, 26, 8), // "QAction*"
QT_MOC_LITERAL(5, 35, 4), // "pFon"
QT_MOC_LITERAL(6, 40, 8), // "setBoard"
QT_MOC_LITERAL(7, 49, 6), // "pBoard"
QT_MOC_LITERAL(8, 56, 4), // "font"
QT_MOC_LITERAL(9, 61, 13), // "colorTextEdit"
QT_MOC_LITERAL(10, 75, 5), // "about"
QT_MOC_LITERAL(11, 81, 12), // "startClicked"
QT_MOC_LITERAL(12, 94, 12) // "DataGameForm"

    },
    "Terrarium\0newGame\0\0setFon\0QAction*\0"
    "pFon\0setBoard\0pBoard\0font\0colorTextEdit\0"
    "about\0startClicked\0DataGameForm"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Terrarium[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    1,   50,    2, 0x08 /* Private */,
       6,    1,   53,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,
      10,    0,   58,    2, 0x08 /* Private */,
      11,    1,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,    2,

       0        // eod
};

void Terrarium::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Terrarium *_t = static_cast<Terrarium *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newGame(); break;
        case 1: _t->setFon((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 2: _t->setBoard((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 3: _t->font(); break;
        case 4: _t->colorTextEdit(); break;
        case 5: _t->about(); break;
        case 6: _t->startClicked((*reinterpret_cast< DataGameForm(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Terrarium::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Terrarium.data,
      qt_meta_data_Terrarium,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Terrarium::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Terrarium::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Terrarium.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Terrarium::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE