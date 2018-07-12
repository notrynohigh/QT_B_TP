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
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QPushButton *scan;
    QPushButton *clear_list;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *protocol_result;
    QPushButton *clear_proto_result;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_5;
    QListWidget *mac_list;
    QPushButton *savemac;
    QLabel *label;
    QLabel *ok_number;
    QLabel *ok_number_txt;
    QLabel *err_number;
    QLabel *err_number_txt;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BLE_TOOLS)
    {
        if (BLE_TOOLS->objectName().isEmpty())
            BLE_TOOLS->setObjectName(QStringLiteral("BLE_TOOLS"));
        BLE_TOOLS->resize(750, 804);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BLE_TOOLS->sizePolicy().hasHeightForWidth());
        BLE_TOOLS->setSizePolicy(sizePolicy);
        BLE_TOOLS->setMinimumSize(QSize(750, 804));
        BLE_TOOLS->setMaximumSize(QSize(750, 804));
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

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(34, 62, 331, 311));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(layoutWidget1);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        scan = new QPushButton(layoutWidget1);
        scan->setObjectName(QStringLiteral("scan"));

        verticalLayout->addWidget(scan);

        clear_list = new QPushButton(layoutWidget1);
        clear_list->setObjectName(QStringLiteral("clear_list"));

        verticalLayout->addWidget(clear_list);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(30, 380, 341, 311));
        verticalLayout_4 = new QVBoxLayout(layoutWidget2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        protocol_result = new QTextEdit(layoutWidget2);
        protocol_result->setObjectName(QStringLiteral("protocol_result"));

        verticalLayout_4->addWidget(protocol_result);

        clear_proto_result = new QPushButton(layoutWidget2);
        clear_proto_result->setObjectName(QStringLiteral("clear_proto_result"));

        verticalLayout_4->addWidget(clear_proto_result);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(400, 60, 321, 631));
        verticalLayout_5 = new QVBoxLayout(layoutWidget3);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        mac_list = new QListWidget(layoutWidget3);
        mac_list->setObjectName(QStringLiteral("mac_list"));

        verticalLayout_5->addWidget(mac_list);

        savemac = new QPushButton(layoutWidget3);
        savemac->setObjectName(QStringLiteral("savemac"));

        verticalLayout_5->addWidget(savemac);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 705, 561, 41));
        ok_number = new QLabel(centralWidget);
        ok_number->setObjectName(QStringLiteral("ok_number"));
        ok_number->setGeometry(QRect(400, 20, 81, 21));
        ok_number_txt = new QLabel(centralWidget);
        ok_number_txt->setObjectName(QStringLiteral("ok_number_txt"));
        ok_number_txt->setGeometry(QRect(490, 20, 51, 21));
        err_number = new QLabel(centralWidget);
        err_number->setObjectName(QStringLiteral("err_number"));
        err_number->setGeometry(QRect(560, 20, 81, 21));
        err_number_txt = new QLabel(centralWidget);
        err_number_txt->setObjectName(QStringLiteral("err_number_txt"));
        err_number_txt->setGeometry(QRect(650, 20, 61, 21));
        BLE_TOOLS->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        protocol_result->raise();
        label->raise();
        ok_number->raise();
        ok_number_txt->raise();
        err_number->raise();
        err_number_txt->raise();
        menuBar = new QMenuBar(BLE_TOOLS);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 750, 23));
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
        scan->setText(QApplication::translate("BLE_TOOLS", "\345\274\200\345\247\213\346\211\253\346\217\217", Q_NULLPTR));
        clear_list->setText(QApplication::translate("BLE_TOOLS", "\346\270\205\351\231\244\346\211\253\346\217\217\350\256\260\345\275\225", Q_NULLPTR));
        clear_proto_result->setText(QApplication::translate("BLE_TOOLS", "\346\270\205\351\231\244\350\247\243\346\236\220\346\225\260\346\215\256", Q_NULLPTR));
        savemac->setText(QApplication::translate("BLE_TOOLS", "\344\277\235\345\255\230MAC\345\234\260\345\235\200\345\210\260\346\226\207\344\273\266", Q_NULLPTR));
        label->setText(QApplication::translate("BLE_TOOLS", "<html><head/><body><p align=\"center\">\346\267\261\345\234\263\345\270\202\346\254\247\347\233\276\346\231\272\350\203\275\347\247\221\346\212\200\346\234\211\351\231\220\345\205\254\345\217\270 </p><p align=\"center\"><a href=\"www.runstep.com\"><span style=\" text-decoration: underline; color:#0000ff;\">www.runstep.com</span></a></p></body></html>", Q_NULLPTR));
        ok_number->setText(QApplication::translate("BLE_TOOLS", "\346\255\243\345\270\270\350\256\276\345\244\207\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        ok_number_txt->setText(QApplication::translate("BLE_TOOLS", "0000000", Q_NULLPTR));
        err_number->setText(QApplication::translate("BLE_TOOLS", "\346\225\205\351\232\234\350\256\276\345\244\207\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        err_number_txt->setText(QApplication::translate("BLE_TOOLS", "0000000", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BLE_TOOLS: public Ui_BLE_TOOLS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLE_TOOLS_H
