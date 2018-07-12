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
#include <QtWidgets/QRadioButton>
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
    QPushButton *updateRun;
    QPushButton *updateWalk;
    QPushButton *total_steps;
    QLabel *conn_label;
    QRadioButton *namefilter;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout;
    QPushButton *setDate;
    QPushButton *battery;
    QPushButton *resetid;
    QPushButton *getalgoparam;
    QPushButton *getdata;
    QPushButton *breakdown;
    QPushButton *getuserid;
    QPushButton *restart_record;
    QPushButton *version;
    QPushButton *restart;
    QPushButton *setID;
    QPushButton *wave;
    QPushButton *AdjustChip;
    QPushButton *erase_chip;
    QPushButton *StopDrawWave;
    QPushButton *RT_END;
    QPushButton *RT_START;
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
    QWidget *layoutWidget6;
    QVBoxLayout *verticalLayout_5;
    QListWidget *mac_list;
    QPushButton *savemac;
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
        BLE_TOOLS->setMinimumSize(QSize(1500, 759));
        BLE_TOOLS->setMaximumSize(QSize(1500, 759));
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
        layoutWidget1->setGeometry(QRect(580, 20, 192, 151));
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
        conn_label->setGeometry(QRect(810, 40, 131, 21));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        conn_label->setFont(font);
        conn_label->setStyleSheet(QStringLiteral("QLabel{color:rgb(255, 0, 0)}"));
        namefilter = new QRadioButton(Cmd);
        namefilter->setObjectName(QStringLiteral("namefilter"));
        namefilter->setGeometry(QRect(800, 80, 221, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        namefilter->setFont(font1);
        namefilter->setAcceptDrops(false);
        namefilter->setStyleSheet(QStringLiteral("color:rgb(255, 0, 0)"));
        namefilter->setChecked(false);
        layoutWidget2 = new QWidget(Cmd);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 20, 531, 161));
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

        battery = new QPushButton(layoutWidget2);
        battery->setObjectName(QStringLiteral("battery"));

        gridLayout->addWidget(battery, 0, 1, 1, 1);

        resetid = new QPushButton(layoutWidget2);
        resetid->setObjectName(QStringLiteral("resetid"));
        resetid->setEnabled(true);

        gridLayout->addWidget(resetid, 0, 2, 1, 1);

        getalgoparam = new QPushButton(layoutWidget2);
        getalgoparam->setObjectName(QStringLiteral("getalgoparam"));

        gridLayout->addWidget(getalgoparam, 0, 3, 1, 1);

        getdata = new QPushButton(layoutWidget2);
        getdata->setObjectName(QStringLiteral("getdata"));

        gridLayout->addWidget(getdata, 1, 0, 1, 1);

        breakdown = new QPushButton(layoutWidget2);
        breakdown->setObjectName(QStringLiteral("breakdown"));

        gridLayout->addWidget(breakdown, 1, 1, 1, 1);

        getuserid = new QPushButton(layoutWidget2);
        getuserid->setObjectName(QStringLiteral("getuserid"));

        gridLayout->addWidget(getuserid, 1, 2, 1, 1);

        restart_record = new QPushButton(layoutWidget2);
        restart_record->setObjectName(QStringLiteral("restart_record"));

        gridLayout->addWidget(restart_record, 1, 3, 1, 1);

        version = new QPushButton(layoutWidget2);
        version->setObjectName(QStringLiteral("version"));

        gridLayout->addWidget(version, 2, 0, 1, 1);

        restart = new QPushButton(layoutWidget2);
        restart->setObjectName(QStringLiteral("restart"));
        restart->setEnabled(true);

        gridLayout->addWidget(restart, 2, 1, 1, 1);

        setID = new QPushButton(layoutWidget2);
        setID->setObjectName(QStringLiteral("setID"));
        setID->setEnabled(true);

        gridLayout->addWidget(setID, 2, 2, 1, 1);

        wave = new QPushButton(layoutWidget2);
        wave->setObjectName(QStringLiteral("wave"));

        gridLayout->addWidget(wave, 2, 3, 1, 1);

        AdjustChip = new QPushButton(layoutWidget2);
        AdjustChip->setObjectName(QStringLiteral("AdjustChip"));
        AdjustChip->setEnabled(true);

        gridLayout->addWidget(AdjustChip, 3, 0, 1, 1);

        erase_chip = new QPushButton(layoutWidget2);
        erase_chip->setObjectName(QStringLiteral("erase_chip"));
        erase_chip->setEnabled(true);

        gridLayout->addWidget(erase_chip, 3, 1, 1, 1);

        StopDrawWave = new QPushButton(layoutWidget2);
        StopDrawWave->setObjectName(QStringLiteral("StopDrawWave"));

        gridLayout->addWidget(StopDrawWave, 3, 3, 1, 1);

        RT_END = new QPushButton(layoutWidget2);
        RT_END->setObjectName(QStringLiteral("RT_END"));

        gridLayout->addWidget(RT_END, 4, 0, 1, 1);

        RT_START = new QPushButton(layoutWidget2);
        RT_START->setObjectName(QStringLiteral("RT_START"));

        gridLayout->addWidget(RT_START, 4, 1, 1, 1);

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
        layoutWidget5->setGeometry(QRect(420, 220, 1061, 251));
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

        layoutWidget6 = new QWidget(centralWidget);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(420, 490, 1061, 201));
        verticalLayout_5 = new QVBoxLayout(layoutWidget6);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        mac_list = new QListWidget(layoutWidget6);
        mac_list->setObjectName(QStringLiteral("mac_list"));

        verticalLayout_5->addWidget(mac_list);

        savemac = new QPushButton(layoutWidget6);
        savemac->setObjectName(QStringLiteral("savemac"));

        verticalLayout_5->addWidget(savemac);

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
        refresh_com->setText(QApplication::translate("BLE_TOOLS", "\345\210\267\346\226\260\347\253\257\345\217\243", Q_NULLPTR));
        opencom->setText(QApplication::translate("BLE_TOOLS", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        Cmd->setTitle(QApplication::translate("BLE_TOOLS", "\346\214\207\344\273\244\346\265\213\350\257\225", Q_NULLPTR));
        updateRun->setText(QApplication::translate("BLE_TOOLS", "\345\220\214\346\255\245\350\267\221\346\255\245\346\225\260\346\215\256", Q_NULLPTR));
        updateWalk->setText(QApplication::translate("BLE_TOOLS", "\345\220\214\346\255\245\350\265\260\350\267\257\346\225\260\346\215\256", Q_NULLPTR));
        total_steps->setText(QApplication::translate("BLE_TOOLS", "\350\216\267\345\217\226\346\200\273\346\255\245\346\225\260", Q_NULLPTR));
        conn_label->setText(QApplication::translate("BLE_TOOLS", "\350\277\236\346\216\245\346\226\255\345\274\200......", Q_NULLPTR));
        namefilter->setText(QApplication::translate("BLE_TOOLS", "\346\211\253\346\217\217Odun_xxxx", Q_NULLPTR));
        setDate->setText(QApplication::translate("BLE_TOOLS", "\350\256\276\347\275\256\346\227\266\351\227\264", Q_NULLPTR));
        battery->setText(QApplication::translate("BLE_TOOLS", "\347\224\265\346\261\240\347\224\265\351\207\217", Q_NULLPTR));
        resetid->setText(QApplication::translate("BLE_TOOLS", "\351\207\215\347\275\256\347\224\250\346\210\267ID", Q_NULLPTR));
        getalgoparam->setText(QApplication::translate("BLE_TOOLS", "\350\216\267\345\217\226\347\256\227\346\263\225\345\217\202\346\225\260", Q_NULLPTR));
        getdata->setText(QApplication::translate("BLE_TOOLS", "\350\216\267\345\217\226\346\227\266\351\227\264", Q_NULLPTR));
        breakdown->setText(QApplication::translate("BLE_TOOLS", "\347\241\254\344\273\266\346\243\200\346\265\213", Q_NULLPTR));
        getuserid->setText(QApplication::translate("BLE_TOOLS", "\350\216\267\345\217\226\347\224\250\346\210\267ID", Q_NULLPTR));
        restart_record->setText(QApplication::translate("BLE_TOOLS", "\350\216\267\345\217\226\351\207\215\345\220\257\350\256\260\345\275\225", Q_NULLPTR));
        version->setText(QApplication::translate("BLE_TOOLS", "\350\216\267\345\217\226\347\211\210\346\234\254\345\217\267", Q_NULLPTR));
        restart->setText(QApplication::translate("BLE_TOOLS", "\351\207\215\345\220\257", Q_NULLPTR));
        setID->setText(QApplication::translate("BLE_TOOLS", "\350\256\276\347\275\256\347\224\250\346\210\267ID", Q_NULLPTR));
        wave->setText(QApplication::translate("BLE_TOOLS", "\347\273\230\345\210\266\346\263\242\345\275\242", Q_NULLPTR));
        AdjustChip->setText(QApplication::translate("BLE_TOOLS", "\350\212\257\347\211\207\346\240\241\345\207\206", Q_NULLPTR));
        erase_chip->setText(QApplication::translate("BLE_TOOLS", "\346\223\246\351\231\244FLASH", Q_NULLPTR));
        StopDrawWave->setText(QApplication::translate("BLE_TOOLS", "\347\273\230\345\210\266\346\263\242\345\275\242\345\201\234\346\255\242", Q_NULLPTR));
        RT_END->setText(QApplication::translate("BLE_TOOLS", "\345\256\236\346\227\266\346\250\241\345\274\217\347\273\223\346\235\237", Q_NULLPTR));
        RT_START->setText(QApplication::translate("BLE_TOOLS", "\345\274\200\345\220\257\345\256\236\346\227\266\346\250\241\345\274\217", Q_NULLPTR));
        scan->setText(QApplication::translate("BLE_TOOLS", "\345\274\200\345\247\213\346\211\253\346\217\217", Q_NULLPTR));
        clear_list->setText(QApplication::translate("BLE_TOOLS", "\346\270\205\351\231\244\346\211\253\346\217\217\350\256\260\345\275\225", Q_NULLPTR));
        clear_log->setText(QApplication::translate("BLE_TOOLS", "\346\270\205\351\231\244\351\200\232\350\256\257\350\256\260\345\275\225", Q_NULLPTR));
        clear_proto_result->setText(QApplication::translate("BLE_TOOLS", "\346\270\205\351\231\244\350\247\243\346\236\220\346\225\260\346\215\256", Q_NULLPTR));
        savemac->setText(QApplication::translate("BLE_TOOLS", "\344\277\235\345\255\230MAC\345\234\260\345\235\200\345\210\260\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BLE_TOOLS: public Ui_BLE_TOOLS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLE_TOOLS_H
