/****************************************************************************
** Meta object code from reading C++ file 'contenttabmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CORAL/contenttabmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'contenttabmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ContentTabManager_t {
    QByteArrayData data[15];
    char stringdata[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ContentTabManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ContentTabManager_t qt_meta_stringdata_ContentTabManager = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 22),
QT_MOC_LITERAL(2, 41, 0),
QT_MOC_LITERAL(3, 42, 14),
QT_MOC_LITERAL(4, 57, 5),
QT_MOC_LITERAL(5, 63, 10),
QT_MOC_LITERAL(6, 74, 8),
QT_MOC_LITERAL(7, 83, 8),
QT_MOC_LITERAL(8, 92, 7),
QT_MOC_LITERAL(9, 100, 8),
QT_MOC_LITERAL(10, 109, 3),
QT_MOC_LITERAL(11, 113, 11),
QT_MOC_LITERAL(12, 125, 10),
QT_MOC_LITERAL(13, 136, 19),
QT_MOC_LITERAL(14, 156, 10)
    },
    "ContentTabManager\0testConnectionFinished\0"
    "\0QNetworkReply*\0reply\0setupVideo\0"
    "videoURL\0setupPDF\0PDFPath\0setupWeb\0"
    "url\0restriction\0setupGroup\0"
    "QVector<Thumbnail*>\0thumbnails\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ContentTabManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08,
       5,    1,   42,    2, 0x08,
       7,    1,   45,    2, 0x08,
       9,    2,   48,    2, 0x08,
      12,    1,   53,    2, 0x08,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   10,   11,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

void ContentTabManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ContentTabManager *_t = static_cast<ContentTabManager *>(_o);
        switch (_id) {
        case 0: _t->testConnectionFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 1: _t->setupVideo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->setupPDF((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->setupWeb((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->setupGroup((*reinterpret_cast< QVector<Thumbnail*>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<Thumbnail*> >(); break;
            }
            break;
        }
    }
}

const QMetaObject ContentTabManager::staticMetaObject = {
    { &Manager::staticMetaObject, qt_meta_stringdata_ContentTabManager.data,
      qt_meta_data_ContentTabManager,  qt_static_metacall, 0, 0}
};


const QMetaObject *ContentTabManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ContentTabManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ContentTabManager.stringdata))
        return static_cast<void*>(const_cast< ContentTabManager*>(this));
    return Manager::qt_metacast(_clname);
}

int ContentTabManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Manager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
