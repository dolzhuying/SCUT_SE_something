/****************************************************************************
** Meta object code from reading C++ file 'client_widget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ql/client_widget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSclient_widgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSclient_widgetENDCLASS = QtMocHelpers::stringData(
    "client_widget",
    "connect_to_server",
    "",
    "connected_to_server",
    "disconnect_from_server",
    "disconnected_from_server",
    "show_error",
    "error",
    "send_message",
    "readyRead_handler"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSclient_widgetENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[14];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[20];
    char stringdata4[23];
    char stringdata5[25];
    char stringdata6[11];
    char stringdata7[6];
    char stringdata8[13];
    char stringdata9[18];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSclient_widgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSclient_widgetENDCLASS_t qt_meta_stringdata_CLASSclient_widgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "client_widget"
        QT_MOC_LITERAL(14, 17),  // "connect_to_server"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 19),  // "connected_to_server"
        QT_MOC_LITERAL(53, 22),  // "disconnect_from_server"
        QT_MOC_LITERAL(76, 24),  // "disconnected_from_server"
        QT_MOC_LITERAL(101, 10),  // "show_error"
        QT_MOC_LITERAL(112, 5),  // "error"
        QT_MOC_LITERAL(118, 12),  // "send_message"
        QT_MOC_LITERAL(131, 17)   // "readyRead_handler"
    },
    "client_widget",
    "connect_to_server",
    "",
    "connected_to_server",
    "disconnect_from_server",
    "disconnected_from_server",
    "show_error",
    "error",
    "send_message",
    "readyRead_handler"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSclient_widgetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    1,   60,    2, 0x08,    5 /* Private */,
       8,    0,   63,    2, 0x08,    7 /* Private */,
       9,    0,   64,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject client_widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSclient_widgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSclient_widgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSclient_widgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<client_widget, std::true_type>,
        // method 'connect_to_server'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'connected_to_server'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'disconnect_from_server'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'disconnected_from_server'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'show_error'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'send_message'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readyRead_handler'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void client_widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<client_widget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->connect_to_server(); break;
        case 1: _t->connected_to_server(); break;
        case 2: _t->disconnect_from_server(); break;
        case 3: _t->disconnected_from_server(); break;
        case 4: _t->show_error((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->send_message(); break;
        case 6: _t->readyRead_handler(); break;
        default: ;
        }
    }
}

const QMetaObject *client_widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *client_widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSclient_widgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int client_widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
