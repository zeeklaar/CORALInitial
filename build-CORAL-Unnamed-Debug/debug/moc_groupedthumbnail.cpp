/****************************************************************************
** Meta object code from reading C++ file 'groupedthumbnail.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CORAL/groupedthumbnail.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'groupedthumbnail.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GroupedThumbnail_t {
    QByteArrayData data[4];
    char stringdata[47];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GroupedThumbnail_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GroupedThumbnail_t qt_meta_stringdata_GroupedThumbnail = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 7),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 19)
    },
    "GroupedThumbnail\0clicked\0\0QVector<Thumbnail*>\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GroupedThumbnail[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x05,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void GroupedThumbnail::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GroupedThumbnail *_t = static_cast<GroupedThumbnail *>(_o);
        switch (_id) {
        case 0: _t->clicked((*reinterpret_cast< QVector<Thumbnail*>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<Thumbnail*> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GroupedThumbnail::*_t)(QVector<Thumbnail*> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupedThumbnail::clicked)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject GroupedThumbnail::staticMetaObject = {
    { &Thumbnail::staticMetaObject, qt_meta_stringdata_GroupedThumbnail.data,
      qt_meta_data_GroupedThumbnail,  qt_static_metacall, 0, 0}
};


const QMetaObject *GroupedThumbnail::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GroupedThumbnail::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GroupedThumbnail.stringdata))
        return static_cast<void*>(const_cast< GroupedThumbnail*>(this));
    return Thumbnail::qt_metacast(_clname);
}

int GroupedThumbnail::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Thumbnail::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void GroupedThumbnail::clicked(QVector<Thumbnail*> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE