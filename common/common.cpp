#include "common.h"



QString& operator<< (QString& m, const QString& s) {
    m += s;
    m.append(separator);
    return m;
}
