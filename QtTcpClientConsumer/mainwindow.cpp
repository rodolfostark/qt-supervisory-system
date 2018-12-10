#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    //tcpConnect();

    connect(ui->pushButtonGet,
            SIGNAL(clicked(bool)),
            this,
            SLOT(getData()));
    connect(ui->pushButtonConnect,
            SIGNAL(clicked(bool)),
            this,
            SLOT(conectar()));
    connect(ui->pushButtonDisconnect,
            SIGNAL(clicked(bool)),
            this,
            SLOT(desconectar()));
    connect(ui->horizontalSliderTiming,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(setTimingValue()));
    connect(ui->pushButtonUpdate,
            SIGNAL(clicked(bool)),
            this,
            SLOT(getListOfHosts()));
    connect(ui->listWidget,
            SIGNAL(itemClicked(QListWidgetItem*)),
            this,
            SLOT(selecionarMaquina()));
    connect(ui->pushButtonStart,
            SIGNAL(clicked(bool)),
            this,
            SLOT(startReceive()));
    connect(ui->pushButtonStop,
            SIGNAL(clicked(bool)),
            this,
            SLOT(stopReceive()));
}

void MainWindow::tcpConnect(){
    socket->connectToHost("127.0.0.1",1234);
    if(socket->waitForConnected(3000)){
        qDebug() << "Connected";
    }
    else{
        qDebug() << "Disconnected";
    }
}
void MainWindow::getData(){
    QString str;
    QByteArray array;
    QStringList list;
    qint64 thetime;
    qDebug() << "to get data...";
    if(socket->state() == QAbstractSocket::ConnectedState){
        if(socket->isOpen()){
            qDebug() << "reading...";
            socket->write("get 127.0.0.1 5\r\n");
            socket->waitForBytesWritten();
            socket->waitForReadyRead();
            qDebug() << socket->bytesAvailable();
            while(socket->bytesAvailable()){
                str = socket->readLine().replace("\n","").replace("\r","");
                list = str.split(" ");
                if(list.size() == 2){
                    bool ok;
                    str = list.at(0);
                    thetime = str.toLongLong(&ok);
                    str = list.at(1);
                    qDebug() << thetime << ": " << str;
                }
            }
        }
    }
}

void MainWindow::conectar()
{
    QString host = ui->lineEditIpServer->text();
    socket->connectToHost(host, 1234);
    if(socket->waitForConnected(3000)){
        qDebug() << "Connected to " + host;
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
/**
 * @brief MainWindow::setTimingValue
 * Altera o valor do label
 */
void MainWindow::setTimingValue()
{
    time = ui->horizontalSliderTiming->value()*1000;
    if(useTimer){
        killTimer(timer);
        timer = startTimer(time);
    }
    QString timeValue = QString::number(ui->horizontalSliderTiming->value());
    ui->labelTimingValue->setText(timeValue);
}
/**
 * @brief MainWindow::getListOfHosts
 * Esse método consulta o servidor a respeito dos hosts conectados e produzindo.
 */
void MainWindow::getListOfHosts()
{
    ui->listWidget->clear();
    QString host;
    qDebug() << "look for the producer...";
    if(socket->state() == QAbstractSocket::ConnectedState){
        if(socket->isOpen()){
            qDebug() << "reading...";
            socket->write("list \r\n");
            socket->waitForBytesWritten();
            socket->waitForReadyRead();
            qDebug() << socket->bytesAvailable();
            while(socket->bytesAvailable()){
                host = socket->readLine().replace("\n","").replace("\r","");
                qDebug() << host;
                ui->listWidget->addItem(host);
            }
        }
    }
}
/**
 * @brief MainWindow::startReceive
 * Esse método inicia/reinicia a leitura de dados.
 */
void MainWindow::startReceive()
{
    if(useTimer == false){
        timer = startTimer(time);
        useTimer = true;
    }
}
/**
 * @brief MainWindow::stopReceive
 * Esse método estaciona a leitura de dados.
 */
void MainWindow::stopReceive()
{
    if(timer == true){
        killTimer(timer);
        useTimer = false;
    }

}

void MainWindow::selecionarMaquina()
{
    hostToGet = ui->listWidget->currentItem()->text();
    qDebug() << hostToGet;
}
/**
 * @brief MainWindow::timerEvent
 * O timerEvent irá repetir o processo de leitura de dados disponíveis no servidor em intervalos definidos de tempo.
 * @param event
 */
void MainWindow::timerEvent(QTimerEvent *event){
    getData();
}
MainWindow::~MainWindow()
{
    delete socket;
    delete ui;
}
