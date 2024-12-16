#include "siplotter.h"

SiPlotter::SiPlotter(QWidget *parent): QWidget(parent), siValues(nullptr), size(0)  {}

SiPlotter::~SiPlotter() {delete[] siValues;}

void SiPlotter::setSiValues(double *values, int valuesLen, double x1, double x2) {
    delete[] siValues;
    this->size = valuesLen;
    this->x1 = x1;
    this->x2 = x2;
    siValues = new double[valuesLen];
    std::copy(values, values + valuesLen, siValues);
    update();
}

void SiPlotter::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
}
