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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BLE_TOOLS
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QComboBox *COMx;
    QPushButton *opencom;
    QWidget *widget;
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QTextEdit *uartRecText;
    QPushButton *scan;
    QPushButton *clear_list;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BLE_TOOLS)
    {
        if (BLE_TOOLS->objectName().isEmpty())
            BLE_TOOLS->setObjectName(QStringLiteral("BLE_TOOLS"));
        BLE_TOOLS->resize(768, 637);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icon/resources/ble_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        BLE_TOOLS->setWindowIcon(icon);
        centralWidget = new QWidget(BLE_TOOLS);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 10, 221, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        COMx = new QComboBox(layoutWidget);
        COMx->setObjectName(QStringLiteral("COMx"));
        COMx->setEnabled(true);

        horizontalLayout->addWidget(COMx);

        opencom = new QPushButton(layoutWidget);
        opencom->setObjectName(QStringLiteral("opencom"));

        horizontalLayout->addWidget(opencom);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(21, 80, 721, 481));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(widget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout->addWidget(listWidget, 0, 0, 1, 1);

        uartRecText = new QTextEdit(widget);
        uartRecText->setObjectName(QStringLiteral("uartRecText"));

        gridLayout->addWidget(uartRecText, 0, 1, 3, 1);

        scan = new QPushButton(widget);
        scan->setObjectName(QStringLiteral("scan"));

        gridLayout->addWidget(scan, 1, 0, 1, 1);

        clear_list = new QPushButton(widget);
        clear_list->setObjectName(QStringLiteral("clear_list"));

        gridLayout->addWidget(clear_list, 2, 0, 1, 1);

        BLE_TOOLS->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(BLE_TOOLS);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 768, 23));
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
        opencom->setText(QApplication::translate("BLE_TOOLS", "Open", Q_NULLPTR));
        scan->setText(QApplication::translate("BLE_TOOLS", "Scan", Q_NULLPTR));
        clear_list->setText(QApplication::translate("BLE_TOOLS", "Clear", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BLE_TOOLS: public Ui_BLE_TOOLS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLE_TOOLS_H
