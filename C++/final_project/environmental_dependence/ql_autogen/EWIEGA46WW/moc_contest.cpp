/****************************************************************************
** Meta object code from reading C++ file 'contest.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ql/contest.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'contest.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASScontestENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASScontestENDCLASS = QtMocHelpers::stringData(
    "contest",
    "back",
    "",
    "return_to_main",
    "choose_1",
    "choose_2",
    "choose_3",
    "choose_4",
    "choose_cancel",
    "choose_submit",
    "choose_reset",
    "show_time",
    "choose_tips",
    "generatingmap"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASScontestENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[8];
    char stringdata1[5];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[9];
    char stringdata5[9];
    char stringdata6[9];
    char stringdata7[9];
    char stringdata8[14];
    char stringdata9[14];
    char stringdata10[13];
    char stringdata11[10];
    char stringdata12[12];
    char stringdata13[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASScontestENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASScontestENDCLASS_t qt_meta_stringdata_CLASScontestENDCLASS = {
    {
        QT_MOC_LITERAL(0, 7),  // "contest"
        QT_MOC_LITERAL(8, 4),  // "back"
        QT_MOC_LITERAL(13, 0),  // ""
        QT_MOC_LITERAL(14, 14),  // "return_to_main"
        QT_MOC_LITERAL(29, 8),  // "choose_1"
        QT_MOC_LITERAL(38, 8),  // "choose_2"
        QT_MOC_LITERAL(47, 8),  // "choose_3"
        QT_MOC_LITERAL(56, 8),  // "choose_4"
        QT_MOC_LITERAL(65, 13),  // "choose_cancel"
        QT_MOC_LITERAL(79, 13),  // "choose_submit"
        QT_MOC_LITERAL(93, 12),  // "choose_reset"
        QT_MOC_LITERAL(106, 9),  // "show_time"
        QT_MOC_LITERAL(116, 11),  // "choose_tips"
        QT_MOC_LITERAL(128, 13)   // "generatingmap"
    },
    "contest",
    "back",
    "",
    "return_to_main",
    "choose_1",
    "choose_2",
    "choose_3",
    "choose_4",
    "choose_cancel",
    "choose_submit",
    "choose_reset",
    "show_time",
    "choose_tips",
    "generatingmap"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASScontestENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   87,    2, 0x08,    2 /* Private */,
       4,    0,   88,    2, 0x08,    3 /* Private */,
       5,    0,   89,    2, 0x08,    4 /* Private */,
       6,    0,   90,    2, 0x08,    5 /* Private */,
       7,    0,   91,    2, 0x08,    6 /* Private */,
       8,    0,   92,    2, 0x08,    7 /* Private */,
       9,    0,   93,    2, 0x08,    8 /* Private */,
      10,    0,   94,    2, 0x08,    9 /* Private */,
      11,    0,   95,    2, 0x08,   10 /* Private */,
      12,    0,   96,    2, 0x08,   11 /* Private */,
      13,    0,   97,    2, 0x08,   12 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject contest::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASScontestENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASScontestENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASScontestENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<contest, std::true_type>,
        // method 'back'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'return_to_main'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'choose_1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'choose_2'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'choose_3'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'choose_4'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'choose_cancel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'choose_submit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'choose_reset'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'show_time'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'choose_tips'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'generatingmap'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void contest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<contest *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->back(); break;
        case 1: _t->return_to_main(); break;
        case 2: _t->choose_1(); break;
        case 3: _t->choose_2(); break;
        case 4: _t->choose_3(); break;
        case 5: _t->choose_4(); break;
        case 6: _t->choose_cancel(); break;
        case 7: _t->choose_submit(); break;
        case 8: _t->choose_reset(); break;
        case 9: _t->show_time(); break;
        case 10: _t->choose_tips(); break;
        case 11: _t->generatingmap(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (contest::*)();
            if (_t _q_method = &contest::back; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *contest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *contest::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASScontestENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int contest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void contest::back()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
