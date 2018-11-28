/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QLineEdit *ipLineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *ConnectButton;
    QPushButton *DisconnectButton;
    QVBoxLayout *verticalLayout_2;
    QLabel *minLabel;
    QHBoxLayout *horizontalLayout_2;
    QSlider *horizontalMinSlider;
    QLCDNumber *lcdMinNumber;
    QVBoxLayout *verticalLayout_3;
    QLabel *maxLabel;
    QHBoxLayout *horizontalLayout_3;
    QSlider *horizontalMaxSlider;
    QLCDNumber *lcdMaxNumber;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *timingLabel;
    QSlider *timingSlider;
    QLabel *timingLabelValue;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *StopButton;
    QPushButton *StartButton;
    QVBoxLayout *verticalLayout_7;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonPut;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(537, 439);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 531, 371));
        horizontalLayout_8 = new QHBoxLayout(widget);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        ipLineEdit = new QLineEdit(widget);
        ipLineEdit->setObjectName(QStringLiteral("ipLineEdit"));

        verticalLayout->addWidget(ipLineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ConnectButton = new QPushButton(widget);
        ConnectButton->setObjectName(QStringLiteral("ConnectButton"));

        horizontalLayout->addWidget(ConnectButton);

        DisconnectButton = new QPushButton(widget);
        DisconnectButton->setObjectName(QStringLiteral("DisconnectButton"));

        horizontalLayout->addWidget(DisconnectButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        minLabel = new QLabel(widget);
        minLabel->setObjectName(QStringLiteral("minLabel"));

        verticalLayout_2->addWidget(minLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalMinSlider = new QSlider(widget);
        horizontalMinSlider->setObjectName(QStringLiteral("horizontalMinSlider"));
        horizontalMinSlider->setMinimum(1);
        horizontalMinSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalMinSlider);

        lcdMinNumber = new QLCDNumber(widget);
        lcdMinNumber->setObjectName(QStringLiteral("lcdMinNumber"));
        lcdMinNumber->setProperty("intValue", QVariant(1));

        horizontalLayout_2->addWidget(lcdMinNumber);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        maxLabel = new QLabel(widget);
        maxLabel->setObjectName(QStringLiteral("maxLabel"));

        verticalLayout_3->addWidget(maxLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalMaxSlider = new QSlider(widget);
        horizontalMaxSlider->setObjectName(QStringLiteral("horizontalMaxSlider"));
        horizontalMaxSlider->setMinimum(1);
        horizontalMaxSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalMaxSlider);

        lcdMaxNumber = new QLCDNumber(widget);
        lcdMaxNumber->setObjectName(QStringLiteral("lcdMaxNumber"));
        lcdMaxNumber->setProperty("intValue", QVariant(1));

        horizontalLayout_3->addWidget(lcdMaxNumber);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        timingLabel = new QLabel(widget);
        timingLabel->setObjectName(QStringLiteral("timingLabel"));

        horizontalLayout_5->addWidget(timingLabel);

        timingSlider = new QSlider(widget);
        timingSlider->setObjectName(QStringLiteral("timingSlider"));
        timingSlider->setMinimum(1);
        timingSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(timingSlider);


        horizontalLayout_6->addLayout(horizontalLayout_5);

        timingLabelValue = new QLabel(widget);
        timingLabelValue->setObjectName(QStringLiteral("timingLabelValue"));

        horizontalLayout_6->addWidget(timingLabelValue);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        StopButton = new QPushButton(widget);
        StopButton->setObjectName(QStringLiteral("StopButton"));

        horizontalLayout_4->addWidget(StopButton);

        StartButton = new QPushButton(widget);
        StartButton->setObjectName(QStringLiteral("StartButton"));

        horizontalLayout_4->addWidget(StartButton);


        verticalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_6->addLayout(verticalLayout_5);


        horizontalLayout_8->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        textBrowser = new QTextBrowser(widget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout_7->addWidget(textBrowser);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        pushButtonPut = new QPushButton(widget);
        pushButtonPut->setObjectName(QStringLiteral("pushButtonPut"));

        horizontalLayout_7->addWidget(pushButtonPut);


        verticalLayout_7->addLayout(horizontalLayout_7);


        horizontalLayout_8->addLayout(verticalLayout_7);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 537, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        ConnectButton->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        DisconnectButton->setText(QApplication::translate("MainWindow", "Disconnect", nullptr));
        minLabel->setText(QApplication::translate("MainWindow", "MIN", nullptr));
        maxLabel->setText(QApplication::translate("MainWindow", "MAX", nullptr));
        timingLabel->setText(QApplication::translate("MainWindow", "Timing(s)", nullptr));
        timingLabelValue->setText(QApplication::translate("MainWindow", "1", nullptr));
        StopButton->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        StartButton->setText(QApplication::translate("MainWindow", "Start", nullptr));
        pushButtonPut->setText(QApplication::translate("MainWindow", "putData", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
