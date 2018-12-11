#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>

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
    void getData();
    void conectar();
    void desconectar();
    void setTimingValue();
    void getListOfHosts();
    void startReceive();
    void stopReceive();
    void selecionarMaquina();
private:
    QStringList listToSend;
    int time = 800;
    int timer;
    bool useTimer = false;
    QString hostToGet = "127.0.0.1";
    Ui::MainWindow *ui;
    QTcpSocket *socket;
};

#endif // MAINWINDOW_H
