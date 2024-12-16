#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include "sinplotter.h"
#include "siplotter.h"
#include "../server/functions.h"


class Tinterface : public QWidget
{
    Q_OBJECT
    //Sin, Si
    QLabel *trigonometry;

    QRadioButton *SinMode;
    QRadioButton *SiMode;

    QLabel *semicolonIdentificator;
    QLabel *initialValueOfRangeLabel;
    QLabel *finalValueOfRangeLabel;
    QLineEdit *ReValueInitial;
    QLineEdit *ReValueFinal;

    SinPlotter* sinPlotter;  // Виджет для отображения графика
    SiPlotter* siPlotter;  // Виджет для отображения графика
    QPushButton* updatePlotButton; // Кнопка обновления
    double* values = nullptr;   // Указатель на массив значений синуса
public:
    Tinterface(QWidget *parent = 0);
    ~Tinterface();

public slots:
    void updatePlot();
};

#endif // INTERFACE_H

