/********************************************************************************
** Form generated from reading UI file 'Read_Html.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READ_HTML_H
#define UI_READ_HTML_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Read_HtmlClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QTableWidget *table_header;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QRadioButton *radioButton_2;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *radioButton;
    QPushButton *pushButton_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Read_HtmlClass)
    {
        if (Read_HtmlClass->objectName().isEmpty())
            Read_HtmlClass->setObjectName(QString::fromUtf8("Read_HtmlClass"));
        Read_HtmlClass->resize(1064, 594);
        centralWidget = new QWidget(Read_HtmlClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        table_header = new QTableWidget(widget_2);
        table_header->setObjectName(QString::fromUtf8("table_header"));
        table_header->setMinimumSize(QSize(1020, 200));
        table_header->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(table_header, 0, 0, 1, 3);

        pushButton_5 = new QPushButton(widget_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(150, 50));

        gridLayout_2->addWidget(pushButton_5, 1, 2, 1, 1);

        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(150, 50));

        gridLayout_2->addWidget(pushButton_2, 1, 1, 1, 1);

        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(150, 50));

        gridLayout_2->addWidget(pushButton, 1, 0, 1, 1);


        gridLayout_3->addWidget(widget_2, 0, 0, 1, 2);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMinimumSize(QSize(250, 100));
        textEdit->setMaximumSize(QSize(300, 150));

        gridLayout_3->addWidget(textEdit, 2, 0, 1, 1);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);

        radioButton_2 = new QRadioButton(widget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setMinimumSize(QSize(150, 50));

        gridLayout->addWidget(radioButton_2, 4, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 4, 1, 1);

        radioButton = new QRadioButton(widget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setMinimumSize(QSize(150, 50));

        gridLayout->addWidget(radioButton, 2, 2, 1, 1);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(150, 50));

        gridLayout->addWidget(pushButton_4, 2, 3, 1, 1);


        gridLayout_3->addWidget(widget, 2, 1, 1, 1);

        Read_HtmlClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Read_HtmlClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1064, 26));
        Read_HtmlClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Read_HtmlClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Read_HtmlClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Read_HtmlClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Read_HtmlClass->setStatusBar(statusBar);

        retranslateUi(Read_HtmlClass);

        QMetaObject::connectSlotsByName(Read_HtmlClass);
    } // setupUi

    void retranslateUi(QMainWindow *Read_HtmlClass)
    {
        Read_HtmlClass->setWindowTitle(QApplication::translate("Read_HtmlClass", "Read_Html", nullptr));
        pushButton_5->setText(QApplication::translate("Read_HtmlClass", "\346\270\205\351\231\244\346\225\260\346\215\256", nullptr));
        pushButton_2->setText(QApplication::translate("Read_HtmlClass", "\346\225\260\346\215\256\346\233\264\346\226\260", nullptr));
        pushButton->setText(QApplication::translate("Read_HtmlClass", "\346\225\260\346\215\256\345\257\274\345\205\245", nullptr));
        radioButton_2->setText(QApplication::translate("Read_HtmlClass", "\346\234\211\345\210\200\345\272\223", nullptr));
        radioButton->setText(QApplication::translate("Read_HtmlClass", "\346\227\240\345\210\200\345\272\223", nullptr));
        pushButton_4->setText(QApplication::translate("Read_HtmlClass", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Read_HtmlClass: public Ui_Read_HtmlClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READ_HTML_H
