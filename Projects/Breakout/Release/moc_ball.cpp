/****************************************************************************
** Meta object code from reading C++ file 'ball.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ball.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ball.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Ball_t {
    QByteArrayData data[7];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Ball_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Ball_t qt_meta_stringdata_Ball = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Ball"
QT_MOC_LITERAL(1, 5, 31), // "signalBallReachedTheLowerBorder"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 14), // "signalGameEnds"
QT_MOC_LITERAL(4, 53, 9), // "isVictory"
QT_MOC_LITERAL(5, 63, 5), // "score"
QT_MOC_LITERAL(6, 69, 4) // "move"

    },
    "Ball\0signalBallReachedTheLowerBorder\0"
    "\0signalGameEnds\0isVictory\0score\0move"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ball[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    2,   30,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::UInt,    4,    5,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Ball::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Ball *_t = static_cast<Ball *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalBallReachedTheLowerBorder(); break;
        case 1: _t->signalGameEnds((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 2: _t->move(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Ball::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Ball::signalBallReachedTheLowerBorder)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Ball::*)(bool , quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Ball::signalGameEnds)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Ball::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Ball.data,
      qt_meta_data_Ball,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Ball::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ball::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Ball.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsEllipseItem"))
        return static_cast< QGraphicsEllipseItem*>(this);
    return QObject::qt_metacast(_clname);
}

int Ball::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Ball::signalBallReachedTheLowerBorder()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Ball::signalGameEnds(bool _t1, quint32 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
