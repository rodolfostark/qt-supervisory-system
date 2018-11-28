#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    tcpConnect();

    connect(ui->pushButtonPut,
            SIGNAL(clicked(bool)),
            this,
            SLOT(putData()));

    connect(ui->horizontalMinSlider,
            SIGNAL(valueChanged(int)),
            this, SLOT(minLcd()));

    connect(ui->horizontalMaxSlider,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(maxLcd()));

    connect(ui->timingSlider,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(timingLabel()));

    connect(ui->ConnectButton,
            SIGNAL(clicked(bool)),
            this,
            SLOT(conectar()));

    connect(ui->DisconnectButton,
            SIGNAL(clicked(bool)),
            this,
            SLOT(desconectar()));

    connect(ui->horizontalMaxSlider,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(setValorMax()));

    connect(ui->horizontalMinSlider,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(setValorMin()));

    connect(ui->StartButton,
            SIGNAL(clicked(bool)),
            this,
            SLOT(startTransmit()));

    connect(ui->StopButton,
            SIGNAL(clicked(bool)),
            this,
            SLOT(stopTransmit()));
}

void MainWindow::tcpConnect()
{
    socket->connectToHost("127.0.0.1",1234);
    if(socket->waitForConnected(3000)){
        qDebug() << "Connected!";
    }
    else{
        qDebug() << "Disconnected!";
    }
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    QDateTime datetime;
    QString str;
    qint64 msecdate;
    if(socket->state()== QAbstractSocket::ConnectedState){
        msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();
        str = "set "+ QString::number(msecdate) + " " + QString::number((qrand()%(valorMax - valorMin +1)) + valorMin)+"\r\n";
        mensagem = str;
        qDebug() << str;
        qDebug() << socket->write(str.toStdString().c_str()) << " bytes written";
        if(socket->waitForBytesWritten(3000)){
            qDebug() << "wrote";
        }
    }
    ui->textBrowser->append(mensagem);
}

void MainWindow::putData()
{
    QDateTime datetime;
    QString str;
    qint64 msecdate;

    if(socket->state()== QAbstractSocket::ConnectedState){
        msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();
        str = "set "+ QString::number(msecdate) + " " + QString::number((qrand()%(valorMax - valorMin +1)) + valorMin)+"\r\n";
        mensagem = str;
        qDebug() << str;
        qDebug() << socket->write(str.toStdString().c_str()) << " bytes written";
        if(socket->waitForBytesWritten(3000)){
            qDebug() << "wrote";
        }
    }
}

void MainWindow::minLcd()
{
    ui->lcdMinNumber->display(ui->horizontalMinSlider->value());
}

void MainWindow::maxLcd()
{
    ui->lcdMaxNumber->display(ui->horizontalMaxSlider->value());
}

void MainWindow::timingLabel()
{
    time = ui->timingSlider->value()*1000;
    if(useTimer){
        killTimer(timer);
        timer = startTimer(time);
    }
    QString valor = QString::number(ui->timingSlider->value());
    ui->timingLabelValue->setText(valor);
}

void MainWindow::conectar()
{
    QString host = ui->ipLineEdit->text();
    socket->connectToHost(host, 1234);
    if(socket->waitForConnected(3000)){
        qDebug() << "Connected!";
    }
    else{
        qDebug() << "Disconnected!";
    }

}

void MainWindow::desconectar()
{
    socket->disconnectFromHost();
    if (socket->state() == QAbstractSocket::UnconnectedState ||
            socket->waitForDisconnected(1000)){
        qDebug("Disconnected!");
    }
}

void MainWindow::setValorMax()
{
    valorMax = ui->horizontalMaxSlider->value();
    qDebug() << "Valor máximo: " << valorMax;
}

void MainWindow::setValorMin()
{
    valorMin = ui->horizontalMinSlider->value();
    qDebug() << "Valor mínimo: " << valorMin;
}

void MainWindow::startTransmit()
{
    if(useTimer == false){
        timer = startTimer(time);
        useTimer = true;
    }
}

void MainWindow::stopTransmit()
{
    if(timer == true){
        killTimer(timer);
        useTimer = false;
    }
}

MainWindow::~MainWindow(){
    delete socket;
    delete ui;
}
