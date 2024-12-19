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

void SiPlotter::paintEvent(QPaintEvent *) {
    if (siValues == nullptr || size == 0)
        return;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); // Сглаживание

    int margin = 30;
    int width = this->width();
    int height = this->height();

    QRect graphArea(margin, margin, width - 2 * margin, height - 2 * margin);

    // Оси
    int yCenter = graphArea.top() + graphArea.height() / 2;

    painter.setPen(QPen(Qt::white, 2));
    painter.drawLine(graphArea.left(), yCenter, graphArea.right(), yCenter); // Ось X
    painter.drawLine(graphArea.left(), graphArea.top(), graphArea.left(), graphArea.bottom()); // Ось Y

    // Масштабирование
    double xStep = static_cast<double>(graphArea.width()) / (size - 1);

    // Определим максимальное значение для интегрального синуса
    double maxAbsValue = 0;
    for (int i = 0; i < size; ++i) {
        if (fabs(siValues[i]) > maxAbsValue)
            maxAbsValue = fabs(siValues[i]);
    }
    double yScale = (graphArea.height() / 2.0) / maxAbsValue;

    // Рисование графика
    painter.setPen(QPen(Qt::green, 2)); // Цвет линии — зелёный для Si

    for (int i = 1; i < size; i++) {
        QPointF p1(graphArea.left() + (i - 1) * xStep, yCenter - siValues[i - 1] * yScale);
        QPointF p2(graphArea.left() + i * xStep, yCenter - siValues[i] * yScale);
        painter.drawLine(p1, p2);
    }

    // Метки на осях X и Y
    painter.setPen(QPen(Qt::white, 1));

    // Метки на оси X (начало и конец)
    int xPos1 = graphArea.left();
    painter.drawLine(xPos1, yCenter - 5, xPos1, yCenter + 5);
    painter.drawText(QPointF(xPos1, yCenter + 15), QString::number(x1));

    int xPos2 = graphArea.right();
    painter.drawLine(xPos2, yCenter - 5, xPos2, yCenter + 5);
    painter.drawText(QPointF(xPos2, yCenter + 15), QString::number(x2));

    // Метки на оси Y (-maxAbsValue, 0, maxAbsValue)
    painter.drawLine(graphArea.left() - 5, yCenter, graphArea.left() + 5, yCenter); // Метка 0
    painter.drawText(QPointF(graphArea.left() - 25, yCenter + 5), "0");

    painter.drawLine(graphArea.left() - 5, graphArea.top(), graphArea.left() + 5, graphArea.top());
    painter.drawText(QPointF(graphArea.left() - 25, graphArea.top() + 5), QString::number(maxAbsValue, 'f', 2));

    painter.drawLine(graphArea.left() - 5, graphArea.bottom(), graphArea.left() + 5, graphArea.bottom());
    painter.drawText(QPointF(graphArea.left() - 25, graphArea.bottom() - 5), QString::number(-maxAbsValue, 'f', 2));
}

void SiPlotter::clearPlot() {
    if (siValues != nullptr) {
        delete[] siValues;
        siValues = nullptr;
    }
    size = 0;
    update();
}

