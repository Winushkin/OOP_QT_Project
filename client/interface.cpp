#include <QVBoxLayout>
#include "interface.h"


void Tinterface::updatePlot() {
    double x1 = ReValueInitial->text().toDouble();
    double x2 = ReValueFinal->text().toDouble();

    // Проверка на пустое или неинициализированное значение
    if (sineValues != nullptr) {
        delete[] sineValues;  // Освобождаем память только если она была выделена
    }

    // Создаем новый объект для вычисления значений синуса
    int degree = 10;
    TFsin<double>* SinDouble = new TFsin<double>(degree);

    // Количество точек для графика
    int numPoints = static_cast<int>(x2 - x1);  // Количество точек в интервале
    if (numPoints <= 1) {
        return;  // Если количество точек меньше 1, ничего не рисуем
    }

    sineValues = new double[numPoints];

    // Вычисляем значения синуса для каждого значения X
    for (int i = 0; i < numPoints; i++) {
        double point = x1 + i * (x2 - x1) / (numPoints - 1);  // Вычисление текущего значения X
        sineValues[i] = SinDouble->value(point);  // Получаем значение функции синуса
    }

    // Передаем значения синуса в график
    plotter->setSinValues(sineValues, numPoints, x1, x2);

    // Обновляем виджет для перерисовки
    plotter->update();
}
Tinterface::Tinterface(QWidget *parent){
    // Sin и Si
    trigonometry = new QLabel("Функции Sin и Si", this);
    trigonometry->setGeometry(25, 10, 200, 25);

    SinMode = new QRadioButton("Функция Sin", this);
    SinMode->setGeometry(50, 30, 200, 25);
    SiMode = new QRadioButton("Функция Si", this);
    SiMode->setGeometry(270, 30, 200, 25);
    SinMode->setChecked(true); // отмеченный по дефолту

    initialValueOfRangeLabel = new QLabel("x1: ", this);
    initialValueOfRangeLabel->setGeometry(50, 70, 30, 25);
    ReValueInitial = new QLineEdit(this);
    ReValueInitial->setGeometry(90, 70, 25, 25);
    finalValueOfRangeLabel = new QLabel("x2: ", this);
    finalValueOfRangeLabel->setGeometry(270, 70, 30, 25);
    ReValueFinal = new QLineEdit(this);
    ReValueFinal->setGeometry(310, 70, 25, 25);
    updatePlotButton = new QPushButton("Обновить график", this);
    updatePlotButton->setGeometry(50, 100, 200, 30);
    // Создаём график
    plotter = new SinPlotter(this);
    plotter->setGeometry(25, 140, 400, 200);
    connect(updatePlotButton, SIGNAL(clicked()), this, SLOT(updatePlot()));
}


Tinterface::~Tinterface() {
    delete SinMode;
    delete SiMode;
    delete ReValueInitial;
    delete ReValueFinal;
    delete initialValueOfRangeLabel;
    delete finalValueOfRangeLabel;
    delete[] sineValues;
    delete updatePlotButton;
    delete plotter;
}
