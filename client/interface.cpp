#include <QVBoxLayout>
#include "interface.h"


Tinterface::Tinterface(QWidget *parent){
    // Sin и Si
    trigonometry = new QLabel("Функции Sin и Si", this);
    trigonometry->setGeometry(25, 10, 200, 25);

    SinMode = new QRadioButton("Функция Sin", this);
    SinMode->setGeometry(50, 30, 200, 25);
    SiMode = new QRadioButton("Функция Si", this);
    SiMode->setGeometry(270, 30, 200, 25);
    SinMode->setChecked(true); // отмеченный по дефолту

    initialValueOfRangeLabel = new QLabel("Диапозон графика: [ ", this);
    initialValueOfRangeLabel->setGeometry(50, 70, 130, 25);
    ReValueInitial = new QLineEdit(this);
    ReValueInitial->setGeometry(190, 70, 35, 25);

    semicolonIdentificator = new QLabel(";", this);
    semicolonIdentificator->setGeometry(230, 70, 25, 25);

    ReValueFinal = new QLineEdit(this);
    ReValueFinal->setGeometry(235, 70, 35, 25);
    finalValueOfRangeLabel = new QLabel("] ", this);
    finalValueOfRangeLabel->setGeometry(280, 70, 30, 25);

    updatePlotButton = new QPushButton("Обновить график", this);
    updatePlotButton->setGeometry(50, 100, 200, 30);

    sinPlotter = new SinPlotter(this);
    sinPlotter->setGeometry(25, 140, 400, 200);

    siPlotter = new SiPlotter(this);
    siPlotter->setGeometry(25, 140, 400, 200);

    connect(updatePlotButton, SIGNAL(clicked()), this, SLOT(updatePlot()));
}


Tinterface::~Tinterface() {
    delete SinMode;
    delete SiMode;
    delete ReValueInitial;
    delete ReValueFinal;
    delete initialValueOfRangeLabel;
    delete finalValueOfRangeLabel;
    delete semicolonIdentificator;
    delete[] values;
    delete updatePlotButton;
    delete siPlotter;
    delete sinPlotter;
}


void Tinterface::updatePlot() {
    double x1 = ReValueInitial->text().toDouble();
    double x2 = ReValueFinal->text().toDouble();

    delete[] values;
    int degree = 10;

    if ( SinMode->isChecked() ) {

        // Создаем новый объект для вычисления значений синуса
        TFsin<double>* SinDouble = new TFsin<double>(degree);
        // Количество точек для графика
        int numPoints = static_cast<int>(x2 - x1);  // Количество точек в интервале
        if (numPoints <= 1) {
            return;  // Если количество точек меньше 1, ничего не рисуем
        }

        values = new double[numPoints];

        // Вычисляем значения синуса для каждого значения X
        for (int i = 0; i < numPoints; i++) {
            double point = x1 + i * (x2 - x1) / (numPoints - 1);  // Вычисление текущего значения X
            values[i] = SinDouble->value(point);  // Получаем значение функции синуса
        }

        // Передаем значения синуса в график
        siPlotter->clearPlot();
        sinPlotter->setSinValues(values, numPoints, x1, x2);
        sinPlotter->update();

    } else {
        // Проверка на пустое или неинициализированное значение

        // Создаем новый объект для вычисления значений синуса
        auto* SiDouble = new TFSi<double>(degree);

        // Количество точек для графика
        int numPoints = static_cast<int>(x2 - x1);  // Количество точек в интервале
        if (numPoints <= 1) {
            return;  // Если количество точек меньше 1, ничего не рисуем
        }

        values = new double[numPoints];

        // Вычисляем значения синуса для каждого значения X
        for (int i = 0; i < numPoints; i++) {
            double point = x1 + i * (x2 - x1) / (numPoints - 1);  // Вычисление текущего значения X
            values[i] = SiDouble->value(point);  // Получаем значение функции синуса
        }

        // Передаем значения синуса в график
        sinPlotter->clearPlot();
        siPlotter->setSiValues(values, numPoints, x1, x2);
        siPlotter->update();
    }



}