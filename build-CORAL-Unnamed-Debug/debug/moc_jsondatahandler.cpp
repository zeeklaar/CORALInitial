/****************************************************************************
** Meta object code from reading C++ file 'jsondatahandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CORAL/jsondatahandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jsondatahandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_JsonDataHandler_t {
    QByteArrayData data[7];
    char stringdata[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_JsonDataHandler_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_JsonDataHandler_t qt_meta_stringdata_JsonDataHandler = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 12),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 18),
QT_MOC_LITERAL(4, 49, 14),
QT_MOC_LITERAL(5, 64, 5),
QT_MOC_LITERAL(6, 70, 17)
    },
    "JsonDataHandler\0dataGathered\0\0"
    "imageReplyFinished\0QNetworkReply*\0"
    "reply\0jsonReplyFinished\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_JsonDataHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       3,    1,   30,    2, 0x08,
       6,    1,   33,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

void JsonDataHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        JsonDataHandler *_t = static_cast<JsonDataHandler *>(_o);
        switch (_id) {
        case 0: _t->dataGathered(); break;
        case 1: _t->imageReplyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->jsonReplyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (JsonDataHandler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&JsonDataHandler::dataGathered)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject JsonDataHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_JsonDataHandler.data,
      qt_meta_data_JsonDataHandler,  qt_static_metacall, 0, 0}
};


const QMetaObject *JsonDataHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JsonDataHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JsonDataHandler.stringdata))
        return static_cast<void*>(const_cast< JsonDataHandler*>(this));
    return QObject::qt_metacast(_clname);
}

int JsonDataHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void JsonDataHandler::dataGathered()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
