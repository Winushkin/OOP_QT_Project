#ifndef OOP_QT_PROJECT_SINPLOTTER_H
#define OOP_QT_PROJECT_SINPLOTTER_H
#include <QWidget>
#include <QPainter>

class SinPlotter: public QWidget {
    Q_OBJECT
    double* sinValues;
    int size;
    double x1 = 0.0;
    double x2 = 0.0;
public:
    explicit SinPlotter(QWidget* parent = nullptr);
    void clearPlot();
    ~SinPlotter();
    void setSinValues(double* values, int valuesLen, double x1, double x2);
    void paintEvent(QPaintEvent* event) override;
};


#endif //OOP_QT_PROJECT_SINPLOTTER_H
