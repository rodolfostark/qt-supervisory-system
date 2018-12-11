#include "grafico.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QDebug>
#include <algorithm>

Grafico::Grafico(QWidget *parent) : QWidget(parent)
{

}
void Grafico::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    painter.setRenderHint(QPainter::Antialiasing);

    brush.setColor(QColor(102, 255, 178));
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(153, 0, 0));
    pen.setWidth(1);

    painter.setBrush(brush);
    painter.setPen(pen);

    painter.drawRect(0,0,width(),height());

    for(int i= 1; i < pontos.length(); i++){
        painter.drawLine(0+i, pontos.at(i).toInt(), pontos.at(i-1).toInt(), 0+i);
    }
}

void Grafico::updatePlot(QStringList novaAmostra)
{
    pontos = novaAmostra;
    for(int i = 1; i < pontos.length(); ++i){
        pontos.at(i).toInt();
    }
    repaint();
}
int Grafico::acharMax()
{
    bool ok;
    int index = 0;
    for(int i = 1; i<pontos.length(); i++){
        if(pontos.at(i).toInt(&ok) > pontos.at(i-1).toInt(&ok)){
            index = i;
        }
    }
    return index;
}

int Grafico::acharMin()
{
    bool ok;
    int index = 0;
    for(int i = 1; i<pontos.length(); i++){
        if(pontos.at(i).toInt(&ok) < pontos.at(i-1).toInt(&ok)){
            index = i;
        }
    }
    return index;
}
