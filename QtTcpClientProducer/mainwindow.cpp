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
/**
* Conecta o múdulo produtor de dados ao módulo servidor.
*/
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
/**
* Envia dados ao múdulo servidor do sistema periodicamente.
*/
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
/**
* Envia uma mensagem ao módulo servidor.
*/
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
/**
*Altera os valores no display lcd MIN.
*/
void MainWindow::minLcd()
{
    ui->lcdMinNumber->display(ui->horizontalMinSlider->value());
}
/**
*Altera os valores no display lcd MAX.
*/
void MainWindow::maxLcd()
{
    ui->lcdMaxNumber->display(ui->horizontalMaxSlider->value());
}
/**
*Altera os valores do timing.
*/
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
/**
*Conecta o módulo produtor de dados a um endereço informado pelo usuário no LineEdit.
*/
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
/**
*Desconecta o módulo produtor de um host.
*/
void MainWindow::desconectar()
{
    socket->disconnectFromHost();
    if (socket->state() == QAbstractSocket::UnconnectedState ||
            socket->waitForDisconnected(1000)){
        qDebug("Disconnected!");
    }
}
/**
*Atualiza o valor máximo que poderá ser enviado ao módulo servidor.
*/
void MainWindow::setValorMax()
{
    valorMax = ui->horizontalMaxSlider->value();
    qDebug() << "Valor máximo: " << valorMax;
}
/**
*Atualiza o valor máximo que poderá ser enviado ao módulo servidor.
*/
void MainWindow::setValorMin()
{
    valorMin = ui->horizontalMinSlider->value();
    qDebug() << "Valor mínimo: " << valorMin;
}
/**
*Inicia a transmissão periódica de dados ao servidor.
*/
void MainWindow::startTransmit()
{
    if(useTimer == false){
        timer = startTimer(time);
        useTimer = true;
    }
}
/**
* Paraliza transmissão de dados ao servidor.
*/
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
