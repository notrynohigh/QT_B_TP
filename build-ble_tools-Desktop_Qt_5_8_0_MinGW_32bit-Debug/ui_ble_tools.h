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
#include <QtWidgets/QGridLayout>
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
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QDateEdit *total_step_time;
    QPushButton *updateWalk;
    QPushButton *total_steps;
    QLabel *conn_label;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout;
    QPushButton *setDate;
    QPushButton *getdata;
    QPushButton *setID;
    QPushButton *getuserid;
    QPushButton *bridge_start;
    QPushButton *terminal_mode;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QPushButton *scan;
    QPushButton *clear_list;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *uartRecText;
    QPushButton *clear_log;
    QWidget *layoutWidget5;
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
        BLE_TOOLS->resize(900, 759);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BLE_TOOLS->sizePolicy().hasHeightForWidth());
        BLE_TOOLS->setSizePolicy(sizePolicy);
        BLE_TOOLS->setMinimumSize(QSize(900, 759));
        BLE_TOOLS->setMaximumSize(QSize(900, 759));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icon/resources/ble_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        BLE_TOOLS->setWindowIcon(icon);
        BLE_TOOLS->setAutoFillBackground(true);
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
        Cmd->setGeometry(QRect(420, 10, 1051, 191));
        layoutWidget1 = new QWidget(Cmd);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(250, 20, 171, 101));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        total_step_time = new QDateEdit(layoutWidget1);
        total_step_time->setObjectName(QStringLiteral("total_step_time"));

        verticalLayout_3->addWidget(total_step_time);

        updateWalk = new QPushButton(layoutWidget1);
        updateWalk->setObjectName(QStringLiteral("updateWalk"));

        verticalLayout_3->addWidget(updateWalk);

        total_steps = new QPushButton(layoutWidget1);
        total_steps->setObjectName(QStringLiteral("total_steps"));

        verticalLayout_3->addWidget(total_steps);

        conn_label = new QLabel(Cmd);
        conn_label->setObjectName(QStringLiteral("conn_label"));
        conn_label->setGeometry(QRect(290, 150, 131, 21));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        conn_label->setFont(font);
        conn_label->setStyleSheet(QStringLiteral("QLabel{color:rgb(255, 0, 0)}"));
        layoutWidget2 = new QWidget(Cmd);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 20, 201, 151));
        gridLayout = new QGridLayout(layoutWidget2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        setDate = new QPushButton(layoutWidget2);
        setDate->setObjectName(QStringLiteral("setDate"));
        setDate->setEnabled(true);
        setDate->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(setDate, 0, 0, 1, 1);

        getdata = new QPushButton(layoutWidget2);
        getdata->setObjectName(QStringLiteral("getdata"));

        gridLayout->addWidget(getdata, 1, 0, 1, 1);

        setID = new QPushButton(layoutWidget2);
        setID->setObjectName(QStringLiteral("setID"));
        setID->setEnabled(true);

        gridLayout->addWidget(setID, 0, 1, 1, 1);

        getuserid = new QPushButton(layoutWidget2);
        getuserid->setObjectName(QStringLiteral("getuserid"));

        gridLayout->addWidget(getuserid, 1, 1, 1, 1);

        bridge_start = new QPushButton(layoutWidget2);
        bridge_start->setObjectName(QStringLiteral("bridge_start"));

        gridLayout->addWidget(bridge_start, 2, 0, 1, 1);

        terminal_mode = new QPushButton(layoutWidget2);
        terminal_mode->setObjectName(QStringLiteral("terminal_mode"));

        gridLayout->addWidget(terminal_mode, 2, 1, 1, 1);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(34, 62, 331, 311));
        verticalLayout = new QVBoxLayout(layoutWidget3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(layoutWidget3);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        scan = new QPushButton(layoutWidget3);
        scan->setObjectName(QStringLiteral("scan"));

        verticalLayout->addWidget(scan);

        clear_list = new QPushButton(layoutWidget3);
        clear_list->setObjectName(QStringLiteral("clear_list"));

        verticalLayout->addWidget(clear_list);

        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(30, 380, 331, 301));
        verticalLayout_2 = new QVBoxLayout(layoutWidget4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        uartRecText = new QTextEdit(layoutWidget4);
        uartRecText->setObjectName(QStringLiteral("uartRecText"));

        verticalLayout_2->addWidget(uartRecText);

        clear_log = new QPushButton(layoutWidget4);
        clear_log->setObjectName(QStringLiteral("clear_log"));

        verticalLayout_2->addWidget(clear_log);

        layoutWidget5 = new QWidget(centralWidget);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(420, 220, 451, 451));
        verticalLayout_4 = new QVBoxLayout(layoutWidget5);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        protocol_result = new QTextEdit(layoutWidget5);
        protocol_result->setObjectName(QStringLiteral("protocol_result"));

        verticalLayout_4->addWidget(protocol_result);

        clear_proto_result = new QPushButton(layoutWidget5);
        clear_proto_result->setObjectName(QStringLiteral("clear_proto_result"));

        verticalLayout_4->addWidget(clear_proto_result);

        BLE_TOOLS->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(BLE_TOOLS);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 23));
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
        refresh_com->setText(QApplication::translate("BLE_TOOLS", "\345\210\267\346\226\260\347\253\257\345\217\243", Q_NULLPTR));
        opencom->setText(QApplication::translate("BLE_TOOLS", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        Cmd->setTitle(QApplication::translate("BLE_TOOLS", "\346\214\207\344\273\244\346\265\213\350\257\225", Q_NULLPTR));
        updateWalk->setText(QApplication::translate("BLE_TOOLS", "\345\220\214\346\255\245\350\265\260\350\267\257\346\225\260\346\215\256", Q_NULLPTR));
        total_steps->setText(QApplication::translate("BLE_TOOLS", "\350\216\267\345\217\226\346\200\273\346\255\245\346\225\260", Q_NULLPTR));
        conn_label->setText(QApplication::translate("BLE_TOOLS", "\350\277\236\346\216\245\346\226\255\345\274\200......", Q_NULLPTR));
        setDate->setText(QApplication::translate("BLE_TOOLS", "\350\256\276\347\275\256\346\227\266\351\227\264", Q_NULLPTR));
        getdata->setText(QApplication::translate("BLE_TOOLS", "\350\216\267\345\217\226\346\227\266\351\227\264", Q_NULLPTR));
        setID->setText(QApplication::translate("BLE_TOOLS", "\350\256\276\347\275\256\347\224\250\346\210\267ID", Q_NULLPTR));
        getuserid->setText(QApplication::translate("BLE_TOOLS", "\350\216\267\345\217\226\347\224\250\346\210\267ID", Q_NULLPTR));
        bridge_start->setText(QApplication::translate("BLE_TOOLS", "\351\200\217\344\274\240\346\250\241\345\274\217", Q_NULLPTR));
        terminal_mode->setText(QApplication::translate("BLE_TOOLS", "\347\273\210\347\253\257\346\250\241\345\274\217", Q_NULLPTR));
        scan->setText(QApplication::translate("BLE_TOOLS", "\345\274\200\345\247\213\346\211\253\346\217\217", Q_NULLPTR));
        clear_list->setText(QApplication::translate("BLE_TOOLS", "\346\270\205\351\231\244\346\211\253\346\217\217\350\256\260\345\275\225", Q_NULLPTR));
        clear_log->setText(QApplication::translate("BLE_TOOLS", "\346\270\205\351\231\244\351\200\232\350\256\257\350\256\260\345\275\225", Q_NULLPTR));
        clear_proto_result->setText(QApplication::translate("BLE_TOOLS", "\346\270\205\351\231\244\350\247\243\346\236\220\346\225\260\346\215\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BLE_TOOLS: public Ui_BLE_TOOLS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLE_TOOLS_H
