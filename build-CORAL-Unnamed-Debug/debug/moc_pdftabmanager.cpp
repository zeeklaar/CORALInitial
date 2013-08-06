/****************************************************************************
** Meta object code from reading C++ file 'pdftabmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CORAL/pdftabmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pdftabmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PDFTabManager_t {
    QByteArrayData data[6];
    char stringdata[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_PDFTabManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_PDFTabManager_t qt_meta_stringdata_PDFTabManager = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 9),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 10),
QT_MOC_LITERAL(4, 36, 11),
QT_MOC_LITERAL(5, 48, 15)
    },
    "PDFTabManager\0zoomInPDF\0\0zoomOutPDF\0"
    "nextPDFPage\0previousPDFPage\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PDFTabManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a,
       3,    0,   35,    2, 0x0a,
       4,    0,   36,    2, 0x0a,
       5,    0,   37,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PDFTabManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PDFTabManager *_t = static_cast<PDFTabManager *>(_o);
        switch (_id) {
        case 0: _t->zoomInPDF(); break;
        case 1: _t->zoomOutPDF(); break;
        case 2: _t->nextPDFPage(); break;
        case 3: _t->previousPDFPage(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject PDFTabManager::staticMetaObject = {
    { &Manager::staticMetaObject, qt_meta_stringdata_PDFTabManager.data,
      qt_meta_data_PDFTabManager,  qt_static_metacall, 0, 0}
};


const QMetaObject *PDFTabManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PDFTabManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PDFTabManager.stringdata))
        return static_cast<void*>(const_cast< PDFTabManager*>(this));
    return Manager::qt_metacast(_clname);
}

int PDFTabManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Manager::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
