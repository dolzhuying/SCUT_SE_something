/****************************************************************************
** Meta object code from reading C++ file 'rank_show.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ql/rank_show.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rank_show.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSrank_showENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSrank_showENDCLASS = QtMocHelpers::stringData(
    "rank_show",
    "back",
    "",
    "returntomain",
    "choose_common",
    "choose_boss",
    "choose_id",
    "choose_pass_time",
    "choose_timeuse"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSrank_showENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[10];
    char stringdata1[5];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[14];
    char stringdata5[12];
    char stringdata6[10];
    char stringdata7[17];
    char stringdata8[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSrank_showENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSrank_showENDCLASS_t qt_meta_stringdata_CLASSrank_showENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "rank_show"
        QT_MOC_LITERAL(10, 4),  // "back"
        QT_MOC_LITERAL(15, 0),  // ""
        QT_MOC_LITERAL(16, 12),  // "returntomain"
        QT_MOC_LITERAL(29, 13),  // "choose_common"
        QT_MOC_LITERAL(43, 11),  // "choose_boss"
        QT_MOC_LITERAL(55, 9),  // "choose_id"
        QT_MOC_LITERAL(65, 16),  // "choose_pass_time"
        QT_MOC_LITERAL(82, 14)   // "choose_timeuse"
    },
    "rank_show",
    "back",
    "",
    "returntomain",
    "choose_common",
    "choose_boss",
    "choose_id",
    "choose_pass_time",
    "choose_timeuse"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSrank_showENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    0,   62,    2, 0x08,    7 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject rank_show::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSrank_showENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSrank_showENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSrank_showENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<rank_show, std::true_type>,
        // method 'back'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'returntomain'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'choose_common'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'choose_boss'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'choose_id'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'choose_pass_time'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'choose_timeuse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void rank_show::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<rank_show *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->back(); break;
        case 1: _t->returntomain(); break;
        case 2: _t->choose_common(); break;
        case 3: _t->choose_boss(); break;
        case 4: _t->choose_id(); break;
        case 5: _t->choose_pass_time(); break;
        case 6: _t->choose_timeuse(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (rank_show::*)();
            if (_t _q_method = &rank_show::back; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *rank_show::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rank_show::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSrank_showENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int rank_show::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void rank_show::back()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP