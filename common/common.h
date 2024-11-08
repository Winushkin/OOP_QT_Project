#include <QString>

#pragma once

#ifndef OOP_QT_PROJECT_COMMON_H
#define OOP_QT_PROJECT_COMMON_H

const QChar separator(';');

QString& operator<< (QString& m, const QString& s);
const QChar separator(';');
enum massages {
    PRINT_CLASSIC_REQUEST,
    PRINT_CANONIC_REQUEST,
    PRINT_POLYNOM_ANSWER,
    ADD_ROOT_REQUEST,
    ADD_ROOT_ANSWER,
    ADD_COEFFICIENT_REQUEST,
    ADD_COEFFICIENT_ANSWER,
    CHANGE_ROOT_REQUEST,
    CHANGE_ROOT_ANSWER,
    VALUE_AT_POINT_REQUEST,
    VALUE_AT_POINT_ANSWER,
};


#endif
