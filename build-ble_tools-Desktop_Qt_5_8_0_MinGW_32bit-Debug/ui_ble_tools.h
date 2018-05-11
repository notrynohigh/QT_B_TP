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
    QTextEdit *protocol_result;
    QPushButton *total_steps;
    QDateEdit *dateEdit;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QPushButton *scan;
    QPushButton *clear_list;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *uartRecText;
    QPushButton *clear_log;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BLE_TOOLS)
    {
        if (BLE_TOOLS->objectName().isEmpty())
            BLE_TOOLS->setObjectName(QStringLiteral("BLE_TOOLS"));
        BLE_TOOLS->resize(1162, 759);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BLE_TOOLS->sizePolicy().hasHeightForWidth());
        BLE_TOOLS->setSizePolicy(sizePolicy);
        BLE_TOOLS->setMinimumSize(QSize(1162, 759));
        BLE_TOOLS->setMaximumSize(QSize(1162, 759));
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
        Cmd->setGeometry(QRect(410, 20, 141, 281));
        setDate = new QPushButton(Cmd);
        setDate->setObjectName(QStringLiteral("setDate"));
        setDate->setGeometry(QRect(30, 40, 75, 23));
        getdata = new QPushButton(Cmd);
        getdata->setObjectName(QStringLiteral("getdata"));
        getdata->setGeometry(QRect(30, 80, 75, 23));
        version = new QPushButton(Cmd);
        version->setObjectName(QStringLiteral("version"));
        version->setGeometry(QRect(30, 120, 75, 23));
        AdjustChip = new QPushButton(Cmd);
        AdjustChip->setObjectName(QStringLiteral("AdjustChip"));
        AdjustChip->setGeometry(QRect(30, 160, 75, 23));
        wave = new QPushButton(Cmd);
        wave->setObjectName(QStringLiteral("wave"));
        wave->setGeometry(QRect(30, 200, 75, 23));
        StopDrawWave = new QPushButton(Cmd);
        StopDrawWave->setObjectName(QStringLiteral("StopDrawWave"));
        StopDrawWave->setGeometry(QRect(30, 240, 81, 23));
        protocol_result = new QTextEdit(centralWidget);
        protocol_result->setObjectName(QStringLiteral("protocol_result"));
        protocol_result->setGeometry(QRect(420, 400, 711, 281));
        total_steps = new QPushButton(centralWidget);
        total_steps->setObjectName(QStringLiteral("total_steps"));
        total_steps->setGeometry(QRect(720, 30, 75, 23));
        dateEdit = new QDateEdit(centralWidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(580, 30, 130, 22));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(34, 62, 331, 311));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(widget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        scan = new QPushButton(widget);
        scan->setObjectName(QStringLiteral("scan"));

        verticalLayout->addWidget(scan);

        clear_list = new QPushButton(widget);
        clear_list->setObjectName(QStringLiteral("clear_list"));

        verticalLayout->addWidget(clear_list);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(30, 380, 331, 301));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        uartRecText = new QTextEdit(widget1);
        uartRecText->setObjectName(QStringLiteral("uartRecText"));

        verticalLayout_2->addWidget(uartRecText);

        clear_log = new QPushButton(widget1);
        clear_log->setObjectName(QStringLiteral("clear_log"));

        verticalLayout_2->addWidget(clear_log);

        BLE_TOOLS->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(BLE_TOOLS);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1162, 23));
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
        total_steps->setText(QApplication::translate("BLE_TOOLS", "TotalStep", Q_NULLPTR));
        scan->setText(QApplication::translate("BLE_TOOLS", "Scan", Q_NULLPTR));
        clear_list->setText(QApplication::translate("BLE_TOOLS", "Clear", Q_NULLPTR));
        clear_log->setText(QApplication::translate("BLE_TOOLS", "Clear", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BLE_TOOLS: public Ui_BLE_TOOLS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLE_TOOLS_H
