#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "interface.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "QTTest_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    Tinterface polynom = Tinterface("polynom");
    polynom.show();
//    Tinterface arr = Tinterface("array");
//    arr.show();
    return a.exec();
}
