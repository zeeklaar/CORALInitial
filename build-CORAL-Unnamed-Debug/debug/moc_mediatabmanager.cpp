/****************************************************************************
** Meta object code from reading C++ file 'mediatabmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CORAL/mediatabmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mediatabmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MediaTabManager_t {
    QByteArrayData data[14];
    char stringdata[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MediaTabManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MediaTabManager_t qt_meta_stringdata_MediaTabManager = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 8),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 15),
QT_MOC_LITERAL(4, 42, 16),
QT_MOC_LITERAL(5, 59, 11),
QT_MOC_LITERAL(6, 71, 17),
QT_MOC_LITERAL(7, 89, 3),
QT_MOC_LITERAL(8, 93, 6),
QT_MOC_LITERAL(9, 100, 9),
QT_MOC_LITERAL(10, 110, 9),
QT_MOC_LITERAL(11, 120, 9),
QT_MOC_LITERAL(12, 130, 12),
QT_MOC_LITERAL(13, 143, 10)
    },
    "MediaTabManager\0addMedia\0\0updateTrackList\0"
    "QTreeWidgetItem*\0clickedItem\0"
    "playSelectedMedia\0row\0column\0pausePlay\0"
    "nextTrack\0prevTrack\0changeVolume\0"
    "updateTime\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MediaTabManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08,
       3,    1,   55,    2, 0x08,
       6,    2,   58,    2, 0x08,
       9,    0,   63,    2, 0x08,
      10,    0,   64,    2, 0x08,
      11,    0,   65,    2, 0x08,
      12,    0,   66,    2, 0x08,
      13,    0,   67,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MediaTabManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MediaTabManager *_t = static_cast<MediaTabManager *>(_o);
        switch (_id) {
        case 0: _t->addMedia(); break;
        case 1: _t->updateTrackList((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->playSelectedMedia((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->pausePlay(); break;
        case 4: _t->nextTrack(); break;
        case 5: _t->prevTrack(); break;
        case 6: _t->changeVolume(); break;
        case 7: _t->updateTime(); break;
        default: ;
        }
    }
}

const QMetaObject MediaTabManager::staticMetaObject = {
    { &Manager::staticMetaObject, qt_meta_stringdata_MediaTabManager.data,
      qt_meta_data_MediaTabManager,  qt_static_metacall, 0, 0}
};


const QMetaObject *MediaTabManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MediaTabManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MediaTabManager.stringdata))
        return static_cast<void*>(const_cast< MediaTabManager*>(this));
    return Manager::qt_metacast(_clname);
}

int MediaTabManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Manager::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
