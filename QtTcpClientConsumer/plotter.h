#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>

class Plotter: public QWidget
{
    Q_OBJECT
public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

private:
    QList<int> pontos;
signals:

public slots:
    void atualizaPontos(QList<int>  novosPontos);
    int acharMax();
    int acharMin();
};

#endif // PLOTTER_H
