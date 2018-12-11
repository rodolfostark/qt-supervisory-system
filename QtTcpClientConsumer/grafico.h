#ifndef GRAFICO_H
#define GRAFICO_H

#include <QWidget>

class Grafico : public QWidget
{
    Q_OBJECT
private:
    QStringList pontos;
    QVector<int> plot;
public:
    explicit Grafico(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:

public slots:
      void updatePlot(QStringList novaAmostra);
      int acharMax();
      int acharMin();
};
#endif // GRAFICO_H
