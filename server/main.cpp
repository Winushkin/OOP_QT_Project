#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "application.h"


int main(int argc, char *argv[]) {
    ServerApplication a(argc, argv);
    return a.exec();
}
