#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "application.h"


int main(int argc, char *argv[]) {
//    QApplication b(argc, argv);
//
//    QTranslator translator;
//    const QStringList uiLanguages = QLocale::system().uiLanguages();
//    for (const QString &locale : uiLanguages) {
//        const QString baseName = "QTTest_" + QLocale(locale).name();
//        if (translator.load(":/i18n/" + baseName)) {
//            b.installTranslator(&translator);
//            break;
//        }
//    }
    ServerApplication a(argc, argv);
    return a.exec();
}
