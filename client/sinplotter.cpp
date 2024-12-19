#include "sinplotter.h"

SinPlotter::SinPlotter(QWidget *parent): QWidget(parent), sinValues(nullptr), size(0) {}


SinPlotter::~SinPlotter() {delete[] sinValues;}


void SinPlotter::setSinValues(double *values, int valuesLen, double x1, double x2) {
    delete[] sinValues;
    this->size = valuesLen;
    this->x1 = x1;
    this->x2 = x2;
    sinValues = new double[valuesLen];
    std::copy(values, values + valuesLen, sinValues);
    update();
}


void SinPlotter::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    if (sinValues == nullptr || size == 0)
        return;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Границы графика
    int margin = 30;
    int width = this->width();
    int height = this->height();
    QRect graphArea(margin, margin, width - 2 * margin, height - 2 * margin);

    double xStep = static_cast<double>(graphArea.width()) / (size - 1);
    double yScale = graphArea.height() / 2.0;

    int yCenter = graphArea.top() + graphArea.height() / 2;

    // Рисуем оси
    painter.setPen(QPen(Qt::white, 2));
    painter.drawLine(graphArea.left(), yCenter, graphArea.right(), yCenter); // Ось X
    painter.drawLine(graphArea.left(), graphArea.top(), graphArea.left(), graphArea.bottom()); // Ось Y

    // Рисуем график синуса
    painter.setPen(QPen(Qt::red, 2));
    for (int i = 1; i < size; i++) {
        QPointF p1(graphArea.left() + (i - 1) * xStep, yCenter - sinValues[i - 1] * yScale);
        QPointF p2(graphArea.left() + i * xStep, yCenter - sinValues[i] * yScale);
        painter.drawLine(p1, p2);
    }

    // Рисуем метки только на начальной и конечной точке оси X
    painter.setPen(QPen(Qt::white, 1));  // Белый цвет для меток

    // Для начальной точки (x1)
    int xPos1 = graphArea.left() + ((x1 - x1) / (x2 - x1)) * graphArea.width();
    painter.drawLine(xPos1, yCenter - 5, xPos1, yCenter + 5);
    painter.drawText(QPointF(xPos1, yCenter + 15), QString::number(x1));

    // Для конечной точки (x2)
    int xPos2 = graphArea.left() + ((x2 - x1) / (x2 - x1)) * graphArea.width();
    painter.drawLine(xPos2, yCenter - 5, xPos2, yCenter + 5);
    painter.drawText(QPointF(xPos2, yCenter + 15), QString::number(x2));

    // Рисуем разметку на оси Y (например, для -1, 0, 1)
    for (int i = -1; i <= 1; i++) {
        int y = yCenter - i * yScale;
        painter.drawLine(graphArea.left() - 5, y, graphArea.left() + 5, y);  // Рисуем метки на оси Y
        painter.drawText(QPointF(graphArea.left() - 25, y + 5), QString::number(i));  // Метки значений
    }
}

void SinPlotter::clearPlot() {
    if (sinValues != nullptr) {
        delete[] sinValues;
        sinValues = nullptr;
    }
    size = 0;
    update();
}
