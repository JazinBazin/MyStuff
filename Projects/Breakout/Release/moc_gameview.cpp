/****************************************************************************
** Meta object code from reading C++ file 'gameview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gameview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameView_t {
    QByteArrayData data[9];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameView_t qt_meta_stringdata_GameView = {
    {
QT_MOC_LITERAL(0, 0, 8), // "GameView"
QT_MOC_LITERAL(1, 9, 14), // "signalGameEnds"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5), // "score"
QT_MOC_LITERAL(4, 31, 29), // "slotBallReachedTheLowerBorder"
QT_MOC_LITERAL(5, 61, 12), // "slotGameEnds"
QT_MOC_LITERAL(6, 74, 9), // "isVictory"
QT_MOC_LITERAL(7, 84, 20), // "slotCloseGameResults"
QT_MOC_LITERAL(8, 105, 13) // "levelComplete"

    },
    "GameView\0signalGameEnds\0\0score\0"
    "slotBallReachedTheLowerBorder\0"
    "slotGameEnds\0isVictory\0slotCloseGameResults\0"
    "levelComplete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   37,    2, 0x08 /* Private */,
       5,    2,   38,    2, 0x08 /* Private */,
       7,    2,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::UInt,    6,    3,
    QMetaType::Void, QMetaType::UInt, QMetaType::Bool,    3,    8,

       0        // eod
};

void GameView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameView *_t = static_cast<GameView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalGameEnds((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 1: _t->slotBallReachedTheLowerBorder(); break;
        case 2: _t->slotGameEnds((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 3: _t->slotCloseGameResults((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GameView::*)(quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameView::signalGameEnds)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GameView::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_GameView.data,
      qt_meta_data_GameView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GameView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameView.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int GameView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void GameView::signalGameEnds(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
