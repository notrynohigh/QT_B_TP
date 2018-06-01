/********************************************************************************
** Form generated from reading UI file 'ble_tools.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLE_TOOLS_H
#define UI_BLE_TOOLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BLE_TOOLS
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *refresh_com;
    QComboBox *COMx;
    QPushButton *opencom;
    QGroupBox *Cmd;
    QPushButton *setDate;
    QPushButton *getdata;
    QPushButton *version;
    QPushButton *AdjustChip;
    QPushButton *wave;
    QPushButton *StopDrawWave;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QDateEdit *total_step_time;
    QPushButton *updateRun;
    QPushButton *updateWalk;
    QPushButton *total_steps;
    QLabel *conn_label;
    QPushButton *RT_START;
    QPushButton *RT_END;
    QPushButton *battery;
    QPushButton *breakdown;
    QPushButton *restart;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QPushButton *scan;
    QPushButton *clear_list;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *uartRecText;
    QPushButton *clear_log;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *protocol_result;
    QPushButton *clear_proto_result;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BLE_TOOLS)
    {
        if (BLE_TOOLS->objectName().isEmpty())
            BLE_TOOLS->setObjectName(QStringLiteral("BLE_TOOLS"));
        BLE_TOOLS->resize(1500, 759);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BLE_TOOLS->sizePolicy().hasHeightForWidth());
        BLE_TOOLS->setSizePolicy(sizePolicy);
        BLE_TOOLS->setMinimumSize(QSize(1162, 759));
        BLE_TOOLS->setMaximumSize(QSize(1500, 759));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icon/resources/ble_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        BLE_TOOLS->setWindowIcon(icon);
        centralWidget = new QWidget(BLE_TOOLS);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 10, 341, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        refresh_com = new QPushButton(layoutWidget);
        refresh_com->setObjectName(QStringLiteral("refresh_com"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(refresh_com->sizePolicy().hasHeightForWidth());
        refresh_com->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(refresh_com);

        COMx = new QComboBox(layoutWidget);
        COMx->setObjectName(QStringLiteral("COMx"));
        COMx->setEnabled(true);

        horizontalLayout->addWidget(COMx);

        opencom = new QPushButton(layoutWidget);
        opencom->setObjectName(QStringLiteral("opencom"));

        horizontalLayout->addWidget(opencom);

        Cmd = new QGroupBox(centralWidget);
        Cmd->setObjectName(QStringLiteral("Cmd"));
        Cmd->setGeometry(QRect(420, 20, 711, 181));
        setDate = new QPushButton(Cmd);
        setDate->setObjectName(QStringLiteral("setDate"));
        setDate->setGeometry(QRect(30, 20, 75, 23));
        getdata = new QPushButton(Cmd);
        getdata->setObjectName(QStringLiteral("getdata"));
        getdata->setGeometry(QRect(30, 50, 75, 23));
        version = new QPushButton(Cmd);
        version->setObjectName(QStringLiteral("version"));
        version->setGeometry(QRect(30, 80, 75, 23));
        AdjustChip = new QPushButton(Cmd);
        AdjustChip->setObjectName(QStringLiteral("AdjustChip"));
        AdjustChip->setGeometry(QRect(30, 110, 75, 23));
        wave = new QPushButton(Cmd);
        wave->setObjectName(QStringLiteral("wave"));
        wave->setGeometry(QRect(30, 140, 75, 23));
        StopDrawWave = new QPushButton(Cmd);
        StopDrawWave->setObjectName(QStringLiteral("StopDrawWave"));
        StopDrawWave->setGeometry(QRect(120, 140, 81, 23));
        layoutWidget1 = new QWidget(Cmd);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(220, 20, 181, 151));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        total_step_time = new QDateEdit(layoutWidget1);
        total_step_time->setObjectName(QStringLiteral("total_step_time"));

        verticalLayout_3->addWidget(total_step_time);

        updateRun = new QPushButton(layoutWidget1);
        updateRun->setObjectName(QStringLiteral("updateRun"));

        verticalLayout_3->addWidget(updateRun);

        updateWalk = new QPushButton(layoutWidget1);
        updateWalk->setObjectName(QStringLiteral("updateWalk"));

        verticalLayout_3->addWidget(updateWalk);

        total_steps = new QPushButton(layoutWidget1);
        total_steps->setObjectName(QStringLiteral("total_steps"));

        verticalLayout_3->addWidget(total_steps);

        conn_label = new QLabel(Cmd);
        conn_label->setObjectName(QStringLiteral("conn_label"));
        conn_label->setGeometry(QRect(610, 10, 91, 21));
        RT_START = new QPushButton(Cmd);
        RT_START->setObjectName(QStringLiteral("RT_START"));
        RT_START->setGeometry(QRect(450, 20, 101, 31));
        RT_END = new QPushButton(Cmd);
        RT_END->setObjectName(QStringLiteral("RT_END"));
        RT_END->setGeometry(QRect(450, 60, 101, 31));
        battery = new QPushButton(Cmd);
        battery->setObjectName(QStringLiteral("battery"));
        battery->setGeometry(QRect(120, 20, 75, 23));
        breakdown = new QPushButton(Cmd);
        breakdown->setObjectName(QStringLiteral("breakdown"));
        breakdown->setGeometry(QRect(120, 50, 75, 23));
        restart = new QPushButton(Cmd);
        restart->setObjectName(QStringLiteral("restart"));
        restart->setGeometry(QRect(120, 80, 75, 23));
        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(34, 62, 331, 311));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(layoutWidget2);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        scan = new QPushButton(layoutWidget2);
        scan->setObjectName(QStringLiteral("scan"));

        verticalLayout->addWidget(scan);

        clear_list = new QPushButton(layoutWidget2);
        clear_list->setObjectName(QStringLiteral("clear_list"));

        verticalLayout->addWidget(clear_list);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(30, 380, 331, 301));
        verticalLayout_2 = new QVBoxLayout(layoutWidget3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        uartRecText = new QTextEdit(layoutWidget3);
        uartRecText->setObjectName(QStringLiteral("uartRecText"));

        verticalLayout_2->addWidget(uartRecText);

        clear_log = new QPushButton(layoutWidget3);
        clear_log->setObjectName(QStringLiteral("clear_log"));

        verticalLayout_2->addWidget(clear_log);

        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(420, 220, 1061, 461));
        verticalLayout_4 = new QVBoxLayout(layoutWidget4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        protocol_result = new QTextEdit(layoutWidget4);
        protocol_result->setObjectName(QStringLiteral("protocol_result"));

        verticalLayout_4->addWidget(protocol_result);

        clear_proto_result = new QPushButton(layoutWidget4);
        clear_proto_result->setObjectName(QStringLiteral("clear_proto_result"));

        verticalLayout_4->addWidget(clear_proto_result);

        BLE_TOOLS->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(BLE_TOOLS);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1500, 23));
        BLE_TOOLS->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BLE_TOOLS);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        BLE_TOOLS->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(BLE_TOOLS);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        BLE_TOOLS->setStatusBar(statusBar);

        retranslateUi(BLE_TOOLS);

        QMetaObject::connectSlotsByName(BLE_TOOLS);
    } // setupUi

    void retranslateUi(QMainWindow *BLE_TOOLS)
    {
        BLE_TOOLS->setWindowTitle(QApplication::translate("BLE_TOOLS", "BLE_TOOLS", Q_NULLPTR));
        refresh_com->setText(QApplication::translate("BLE_TOOLS", "Refresh", Q_NULLPTR));
        opencom->setText(QApplication::translate("BLE_TOOLS", "Open", Q_NULLPTR));
        Cmd->setTitle(QApplication::translate("BLE_TOOLS", "Protocol_Test", Q_NULLPTR));
        setDate->setText(QApplication::translate("BLE_TOOLS", "SetDate", Q_NULLPTR));
        getdata->setText(QApplication::translate("BLE_TOOLS", "GetDate", Q_NULLPTR));
        version->setText(QApplication::translate("BLE_TOOLS", "GetVersion", Q_NULLPTR));
        AdjustChip->setText(QApplication::translate("BLE_TOOLS", "AdjustChip", Q_NULLPTR));
        wave->setText(QApplication::translate("BLE_TOOLS", "DrawWave", Q_NULLPTR));
        StopDrawWave->setText(QApplication::translate("BLE_TOOLS", "StopDrawWave", Q_NULLPTR));
        updateRun->setText(QApplication::translate("BLE_TOOLS", "SynRun", Q_NULLPTR));
        updateWalk->setText(QApplication::translate("BLE_TOOLS", "SynWalk", Q_NULLPTR));
        total_steps->setText(QApplication::translate("BLE_TOOLS", "TotalStep", Q_NULLPTR));
        conn_label->setText(QApplication::translate("BLE_TOOLS", "Disconnected", Q_NULLPTR));
        RT_START->setText(QApplication::translate("BLE_TOOLS", "RealTimeStart", Q_NULLPTR));
        RT_END->setText(QApplication::translate("BLE_TOOLS", "RealTimeEnd", Q_NULLPTR));
        battery->setText(QApplication::translate("BLE_TOOLS", "Battery", Q_NULLPTR));
        breakdown->setText(QApplication::translate("BLE_TOOLS", "Breakdown", Q_NULLPTR));
        restart->setText(QApplication::translate("BLE_TOOLS", "Restart", Q_NULLPTR));
        scan->setText(QApplication::translate("BLE_TOOLS", "Scan", Q_NULLPTR));
        clear_list->setText(QApplication::translate("BLE_TOOLS", "Clear", Q_NULLPTR));
        clear_log->setText(QApplication::translate("BLE_TOOLS", "Clear", Q_NULLPTR));
        clear_proto_result->setText(QApplication::translate("BLE_TOOLS", "Clear", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BLE_TOOLS: public Ui_BLE_TOOLS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLE_TOOLS_H
