/****************************************************************************
** Meta object code from reading C++ file 'server_widget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ql/server_widget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server_widget.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSserver_widgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSserver_widgetENDCLASS = QtMocHelpers::stringData(
    "server_widget",
    "start_Server",
    "",
    "stop_Server",
    "send_message",
    "incomingConnection",
    "readyReadHandler",
    "disconnectedHandler"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSserver_widgetENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[14];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[13];
    char stringdata5[19];
    char stringdata6[17];
    char stringdata7[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSserver_widgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSserver_widgetENDCLASS_t qt_meta_stringdata_CLASSserver_widgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "server_widget"
        QT_MOC_LITERAL(14, 12),  // "start_Server"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 11),  // "stop_Server"
        QT_MOC_LITERAL(40, 12),  // "send_message"
        QT_MOC_LITERAL(53, 18),  // "incomingConnection"
        QT_MOC_LITERAL(72, 16),  // "readyReadHandler"
        QT_MOC_LITERAL(89, 19)   // "disconnectedHandler"
    },
    "server_widget",
    "start_Server",
    "",
    "stop_Server",
    "send_message",
    "incomingConnection",
    "readyReadHandler",
    "disconnectedHandler"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSserver_widgetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject server_widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSserver_widgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSserver_widgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSserver_widgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<server_widget, std::true_type>,
        // method 'start_Server'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stop_Server'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'send_message'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'incomingConnection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readyReadHandler'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'disconnectedHandler'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void server_widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<server_widget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->start_Server(); break;
        case 1: _t->stop_Server(); break;
        case 2: _t->send_message(); break;
        case 3: _t->incomingConnection(); break;
        case 4: _t->readyReadHandler(); break;
        case 5: _t->disconnectedHandler(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *server_widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *server_widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSserver_widgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int server_widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
