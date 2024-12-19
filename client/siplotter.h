#ifndef OOP_QT_PROJECT_SIPLOTTER_H
#define OOP_QT_PROJECT_SIPLOTTER_H
#include <QWidget>
#include <QPainter>

class SiPlotter: public QWidget {
Q_OBJECT
    double* siValues;
    int size;
    double x1 = 0.0;
    double x2 = 0.0;
public:
    explicit SiPlotter(QWidget* parent = nullptr);
    void clearPlot();
    ~SiPlotter();
    void setSiValues(double* values, int valuesLen, double x1, double x2);
    void paintEvent(QPaintEvent* event) override;
};


#endif //OOP_QT_PROJECT_SIPLOTTER_H
