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
private:
  int time = 1;
  int timer;
  bool useTimer = false;
  Ui::MainWindow *ui;
  QTcpSocket *socket;
};

#endif // MAINWINDOW_H
