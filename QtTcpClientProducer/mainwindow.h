#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void tcpConnect();
    void timerEvent(QTimerEvent *event);

public slots:
    void putData();
    void minLcd();
    void maxLcd();
    void timingLabel();
    void conectar();
    void desconectar();
    void setValorMax();
    void setValorMin();
    void startTransmit();
    void stopTransmit();

private:
    int valorMax = 1;
    int valorMin = 1;
    int time = 800;
    int timer;
    QString mensagem = "Não conectado ao servidor.";
    bool useTimer = false;
    Ui::MainWindow *ui;
    QTcpSocket *socket;
};

#endif // MAINWINDOW_H
