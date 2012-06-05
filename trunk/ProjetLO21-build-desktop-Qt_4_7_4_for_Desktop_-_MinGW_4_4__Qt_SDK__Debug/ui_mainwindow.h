/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue 5. Jun 16:02:34 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSinus;
    QAction *actionCos;
    QAction *actionTan;
    QAction *actionSinus_2;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QTabWidget *tabWidget_2;
    QWidget *tab_7;
    QHBoxLayout *horizontalLayout;
    QListView *listView;
    QWidget *tab_8;
    QHBoxLayout *horizontalLayout_3;
    QListView *listView_2;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBox_2;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_25;
    QPushButton *pushButton_26;
    QPushButton *pushButton_27;
    QPushButton *pushButton_28;
    QPushButton *pushButton_29;
    QPushButton *pushButton_30;
    QPushButton *pushButton_31;
    QPushButton *pushButton_32;
    QPushButton *pushButton_33;
    QPushButton *pushButton_34;
    QPushButton *pushButton_35;
    QPushButton *pushButton_36;
    QPushButton *pushButton_37;
    QPushButton *pushButton_38;
    QPushButton *pushButton_39;
    QPushButton *pushButton_40;
    QWidget *tab_6;
    QGridLayout *gridLayout_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton_10;
    QPushButton *pushButton_6;
    QPushButton *pushButton_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_11;
    QPushButton *pushButton_4;
    QPushButton *pushButton_8;
    QPushButton *pushButton_5;
    QPushButton *pushButton_9;
    QPushButton *pushButton_12;
    QWidget *tab_4;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_65;
    QRadioButton *radioButton_5;
    QPushButton *pushButton_66;
    QRadioButton *radioButton_6;
    QPushButton *pushButton_67;
    QCheckBox *checkBox_4;
    QWidget *tab_5;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton;
    QPushButton *pushButton_68;
    QPushButton *pushButton_72;
    QPushButton *pushButton_69;
    QPushButton *pushButton_71;
    QPushButton *pushButton_70;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(700, 294);
        actionSinus = new QAction(MainWindow);
        actionSinus->setObjectName(QString::fromUtf8("actionSinus"));
        actionCos = new QAction(MainWindow);
        actionCos->setObjectName(QString::fromUtf8("actionCos"));
        actionTan = new QAction(MainWindow);
        actionTan->setObjectName(QString::fromUtf8("actionTan"));
        actionSinus_2 = new QAction(MainWindow);
        actionSinus_2->setObjectName(QString::fromUtf8("actionSinus_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setReadOnly(true);

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        tabWidget_2 = new QTabWidget(centralWidget);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setMinimumSize(QSize(250, 0));
        tabWidget_2->setTabsClosable(true);
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        horizontalLayout = new QHBoxLayout(tab_7);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        listView = new QListView(tab_7);
        listView->setObjectName(QString::fromUtf8("listView"));

        horizontalLayout->addWidget(listView);

        tabWidget_2->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        horizontalLayout_3 = new QHBoxLayout(tab_8);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        listView_2 = new QListView(tab_8);
        listView_2->setObjectName(QString::fromUtf8("listView_2"));

        horizontalLayout_3->addWidget(listView_2);

        tabWidget_2->addTab(tab_8, QString());

        gridLayout->addWidget(tabWidget_2, 0, 1, 3, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout_2->addWidget(checkBox);

        radioButton_2 = new QRadioButton(centralWidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setChecked(true);

        horizontalLayout_2->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(centralWidget);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        horizontalLayout_2->addWidget(radioButton_3);

        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        horizontalLayout_2->addWidget(radioButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        checkBox_2 = new QCheckBox(centralWidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        horizontalLayout_2->addWidget(checkBox_2);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabsClosable(false);
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_2 = new QGridLayout(tab_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_25 = new QPushButton(tab_3);
        pushButton_25->setObjectName(QString::fromUtf8("pushButton_25"));

        gridLayout_2->addWidget(pushButton_25, 0, 0, 1, 1);

        pushButton_26 = new QPushButton(tab_3);
        pushButton_26->setObjectName(QString::fromUtf8("pushButton_26"));

        gridLayout_2->addWidget(pushButton_26, 0, 1, 1, 1);

        pushButton_27 = new QPushButton(tab_3);
        pushButton_27->setObjectName(QString::fromUtf8("pushButton_27"));

        gridLayout_2->addWidget(pushButton_27, 0, 2, 1, 1);

        pushButton_28 = new QPushButton(tab_3);
        pushButton_28->setObjectName(QString::fromUtf8("pushButton_28"));

        gridLayout_2->addWidget(pushButton_28, 0, 3, 1, 1);

        pushButton_29 = new QPushButton(tab_3);
        pushButton_29->setObjectName(QString::fromUtf8("pushButton_29"));

        gridLayout_2->addWidget(pushButton_29, 1, 0, 1, 1);

        pushButton_30 = new QPushButton(tab_3);
        pushButton_30->setObjectName(QString::fromUtf8("pushButton_30"));

        gridLayout_2->addWidget(pushButton_30, 1, 1, 1, 1);

        pushButton_31 = new QPushButton(tab_3);
        pushButton_31->setObjectName(QString::fromUtf8("pushButton_31"));

        gridLayout_2->addWidget(pushButton_31, 1, 2, 1, 1);

        pushButton_32 = new QPushButton(tab_3);
        pushButton_32->setObjectName(QString::fromUtf8("pushButton_32"));

        gridLayout_2->addWidget(pushButton_32, 1, 3, 1, 1);

        pushButton_33 = new QPushButton(tab_3);
        pushButton_33->setObjectName(QString::fromUtf8("pushButton_33"));

        gridLayout_2->addWidget(pushButton_33, 2, 0, 1, 1);

        pushButton_34 = new QPushButton(tab_3);
        pushButton_34->setObjectName(QString::fromUtf8("pushButton_34"));

        gridLayout_2->addWidget(pushButton_34, 2, 1, 1, 1);

        pushButton_35 = new QPushButton(tab_3);
        pushButton_35->setObjectName(QString::fromUtf8("pushButton_35"));

        gridLayout_2->addWidget(pushButton_35, 2, 2, 1, 1);

        pushButton_36 = new QPushButton(tab_3);
        pushButton_36->setObjectName(QString::fromUtf8("pushButton_36"));

        gridLayout_2->addWidget(pushButton_36, 2, 3, 1, 1);

        pushButton_37 = new QPushButton(tab_3);
        pushButton_37->setObjectName(QString::fromUtf8("pushButton_37"));

        gridLayout_2->addWidget(pushButton_37, 3, 0, 1, 1);

        pushButton_38 = new QPushButton(tab_3);
        pushButton_38->setObjectName(QString::fromUtf8("pushButton_38"));

        gridLayout_2->addWidget(pushButton_38, 3, 1, 1, 1);

        pushButton_39 = new QPushButton(tab_3);
        pushButton_39->setObjectName(QString::fromUtf8("pushButton_39"));

        gridLayout_2->addWidget(pushButton_39, 3, 2, 1, 1);

        pushButton_40 = new QPushButton(tab_3);
        pushButton_40->setObjectName(QString::fromUtf8("pushButton_40"));

        gridLayout_2->addWidget(pushButton_40, 3, 3, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        gridLayout_6 = new QGridLayout(tab_6);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        pushButton_2 = new QPushButton(tab_6);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_6->addWidget(pushButton_2, 0, 0, 1, 1);

        pushButton_10 = new QPushButton(tab_6);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        gridLayout_6->addWidget(pushButton_10, 0, 1, 1, 1);

        pushButton_6 = new QPushButton(tab_6);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout_6->addWidget(pushButton_6, 0, 2, 1, 1);

        pushButton_3 = new QPushButton(tab_6);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout_6->addWidget(pushButton_3, 1, 0, 1, 1);

        pushButton_7 = new QPushButton(tab_6);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        gridLayout_6->addWidget(pushButton_7, 1, 1, 1, 1);

        pushButton_11 = new QPushButton(tab_6);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        gridLayout_6->addWidget(pushButton_11, 1, 2, 1, 1);

        pushButton_4 = new QPushButton(tab_6);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout_6->addWidget(pushButton_4, 3, 0, 1, 1);

        pushButton_8 = new QPushButton(tab_6);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        gridLayout_6->addWidget(pushButton_8, 3, 1, 1, 1);

        pushButton_5 = new QPushButton(tab_6);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout_6->addWidget(pushButton_5, 4, 0, 1, 1);

        pushButton_9 = new QPushButton(tab_6);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        gridLayout_6->addWidget(pushButton_9, 4, 1, 1, 1);

        pushButton_12 = new QPushButton(tab_6);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));

        gridLayout_6->addWidget(pushButton_12, 3, 2, 1, 1);

        tabWidget->addTab(tab_6, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_3 = new QGridLayout(tab_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton_65 = new QPushButton(tab_4);
        pushButton_65->setObjectName(QString::fromUtf8("pushButton_65"));

        gridLayout_3->addWidget(pushButton_65, 0, 0, 1, 1);

        radioButton_5 = new QRadioButton(tab_4);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));
        radioButton_5->setChecked(true);

        gridLayout_3->addWidget(radioButton_5, 0, 1, 1, 1);

        pushButton_66 = new QPushButton(tab_4);
        pushButton_66->setObjectName(QString::fromUtf8("pushButton_66"));

        gridLayout_3->addWidget(pushButton_66, 1, 0, 1, 1);

        radioButton_6 = new QRadioButton(tab_4);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));

        gridLayout_3->addWidget(radioButton_6, 1, 1, 1, 1);

        pushButton_67 = new QPushButton(tab_4);
        pushButton_67->setObjectName(QString::fromUtf8("pushButton_67"));

        gridLayout_3->addWidget(pushButton_67, 2, 0, 1, 1);

        checkBox_4 = new QCheckBox(tab_4);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        gridLayout_3->addWidget(checkBox_4, 2, 1, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        gridLayout_4 = new QGridLayout(tab_5);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        pushButton = new QPushButton(tab_5);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_4->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_68 = new QPushButton(tab_5);
        pushButton_68->setObjectName(QString::fromUtf8("pushButton_68"));

        gridLayout_4->addWidget(pushButton_68, 0, 1, 1, 1);

        pushButton_72 = new QPushButton(tab_5);
        pushButton_72->setObjectName(QString::fromUtf8("pushButton_72"));

        gridLayout_4->addWidget(pushButton_72, 1, 0, 1, 1);

        pushButton_69 = new QPushButton(tab_5);
        pushButton_69->setObjectName(QString::fromUtf8("pushButton_69"));

        gridLayout_4->addWidget(pushButton_69, 1, 1, 1, 1);

        pushButton_71 = new QPushButton(tab_5);
        pushButton_71->setObjectName(QString::fromUtf8("pushButton_71"));

        gridLayout_4->addWidget(pushButton_71, 2, 0, 1, 1);

        pushButton_70 = new QPushButton(tab_5);
        pushButton_70->setObjectName(QString::fromUtf8("pushButton_70"));

        gridLayout_4->addWidget(pushButton_70, 2, 1, 1, 1);

        tabWidget->addTab(tab_5, QString());

        gridLayout->addWidget(tabWidget, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget_2->setCurrentIndex(1);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Calculatrice \303\240 Notation Polonaise Invers\303\251e - Amhed & JB", 0, QApplication::UnicodeUTF8));
        actionSinus->setText(QApplication::translate("MainWindow", "Sinus", 0, QApplication::UnicodeUTF8));
        actionCos->setText(QApplication::translate("MainWindow", "Cosinus", 0, QApplication::UnicodeUTF8));
        actionTan->setText(QApplication::translate("MainWindow", "Tangente", 0, QApplication::UnicodeUTF8));
        actionSinus_2->setText(QApplication::translate("MainWindow", "Sinus", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QApplication::translate("MainWindow", "Pile 1", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QApplication::translate("MainWindow", "Pile 2", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MainWindow", "Complexe", 0, QApplication::UnicodeUTF8));
        checkBox->setShortcut(QApplication::translate("MainWindow", "F1", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("MainWindow", "Reel", 0, QApplication::UnicodeUTF8));
        radioButton_2->setShortcut(QApplication::translate("MainWindow", "F2", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("MainWindow", "Rationnel", 0, QApplication::UnicodeUTF8));
        radioButton_3->setShortcut(QApplication::translate("MainWindow", "F3", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("MainWindow", "Entier", 0, QApplication::UnicodeUTF8));
        radioButton->setShortcut(QApplication::translate("MainWindow", "F4", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("MainWindow", "Calcul auto", 0, QApplication::UnicodeUTF8));
        checkBox_2->setShortcut(QApplication::translate("MainWindow", "F5", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tabWidget->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        pushButton_25->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        pushButton_25->setShortcut(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        pushButton_26->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        pushButton_26->setShortcut(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        pushButton_27->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        pushButton_27->setShortcut(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        pushButton_28->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        pushButton_28->setShortcut(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        pushButton_29->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        pushButton_29->setShortcut(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        pushButton_30->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        pushButton_30->setShortcut(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        pushButton_31->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        pushButton_31->setShortcut(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        pushButton_32->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        pushButton_32->setShortcut(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        pushButton_33->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        pushButton_33->setShortcut(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        pushButton_34->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        pushButton_34->setShortcut(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        pushButton_35->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        pushButton_35->setShortcut(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        pushButton_36->setText(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        pushButton_36->setShortcut(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        pushButton_37->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        pushButton_37->setShortcut(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        pushButton_38->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        pushButton_38->setShortcut(QApplication::translate("MainWindow", "., ,", 0, QApplication::UnicodeUTF8));
        pushButton_39->setText(QApplication::translate("MainWindow", "space", 0, QApplication::UnicodeUTF8));
        pushButton_39->setShortcut(QApplication::translate("MainWindow", "Space", 0, QApplication::UnicodeUTF8));
        pushButton_40->setText(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        pushButton_40->setShortcut(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Basique", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">D\303\251pile X puis Y et effectue Y puissance X</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-style:italic;\">X: Entier, Rationnel, R\303\251el</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-style:italic;\">Y: Entier, Rationnel, R\303\251el</span></p>\n"
"<p align=\"right\" styl"
                        "e=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-style:italic;\">Rac.: **</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButton_2->setText(QApplication::translate("MainWindow", "POW", 0, QApplication::UnicodeUTF8));
        pushButton_2->setShortcut(QApplication::translate("MainWindow", "P", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("MainWindow", "INV", 0, QApplication::UnicodeUTF8));
        pushButton_10->setShortcut(QApplication::translate("MainWindow", "I", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("MainWindow", "MOD", 0, QApplication::UnicodeUTF8));
        pushButton_6->setShortcut(QApplication::translate("MainWindow", "%", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">D\303\251pile X et rempile sa racine carr\303\251e</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-style:italic;\">X: Entier, Rationnel, R\303\251el</span></p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-style:italic;\">Rac.: </span><span style=\" font-size:8pt; font-weight"
                        ":600;\">^</span><span style=\" font-size:8pt; font-style:italic;\">+</span><span style=\" font-size:8pt; font-weight:600;\">/</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButton_3->setText(QApplication::translate("MainWindow", "SQRT", 0, QApplication::UnicodeUTF8));
        pushButton_3->setShortcut(QApplication::translate("MainWindow", "Q", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("MainWindow", "SIGN", 0, QApplication::UnicodeUTF8));
        pushButton_7->setShortcut(QApplication::translate("MainWindow", "_", 0, QApplication::UnicodeUTF8));
        pushButton_11->setText(QApplication::translate("MainWindow", "FACT (!)", 0, QApplication::UnicodeUTF8));
        pushButton_11->setShortcut(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("MainWindow", "SQR", 0, QApplication::UnicodeUTF8));
        pushButton_4->setShortcut(QApplication::translate("MainWindow", "\302\262", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("MainWindow", "LN", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("MainWindow", "CUBE", 0, QApplication::UnicodeUTF8));
        pushButton_5->setShortcut(QApplication::translate("MainWindow", "U", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("MainWindow", "LOG", 0, QApplication::UnicodeUTF8));
        pushButton_9->setShortcut(QApplication::translate("MainWindow", "O", 0, QApplication::UnicodeUTF8));
        pushButton_12->setText(QApplication::translate("MainWindow", "EVAL", 0, QApplication::UnicodeUTF8));
        pushButton_12->setShortcut(QApplication::translate("MainWindow", "=", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "Divers", 0, QApplication::UnicodeUTF8));
        pushButton_65->setText(QApplication::translate("MainWindow", "SIN", 0, QApplication::UnicodeUTF8));
        pushButton_65->setShortcut(QApplication::translate("MainWindow", "S", 0, QApplication::UnicodeUTF8));
        radioButton_5->setText(QApplication::translate("MainWindow", "Radian", 0, QApplication::UnicodeUTF8));
        radioButton_5->setShortcut(QApplication::translate("MainWindow", "R", 0, QApplication::UnicodeUTF8));
        pushButton_66->setText(QApplication::translate("MainWindow", "COS", 0, QApplication::UnicodeUTF8));
        pushButton_66->setShortcut(QApplication::translate("MainWindow", "C", 0, QApplication::UnicodeUTF8));
        radioButton_6->setText(QApplication::translate("MainWindow", "Degr\303\251", 0, QApplication::UnicodeUTF8));
        radioButton_6->setShortcut(QApplication::translate("MainWindow", "D", 0, QApplication::UnicodeUTF8));
        pushButton_67->setText(QApplication::translate("MainWindow", "TAN", 0, QApplication::UnicodeUTF8));
        pushButton_67->setShortcut(QApplication::translate("MainWindow", "T", 0, QApplication::UnicodeUTF8));
        checkBox_4->setText(QApplication::translate("MainWindow", "Hyperbolic", 0, QApplication::UnicodeUTF8));
        checkBox_4->setShortcut(QApplication::translate("MainWindow", "H", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Trigo", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "SWAP", 0, QApplication::UnicodeUTF8));
        pushButton->setShortcut(QApplication::translate("MainWindow", "Ctrl+\\", 0, QApplication::UnicodeUTF8));
        pushButton_68->setText(QApplication::translate("MainWindow", "CLEAR", 0, QApplication::UnicodeUTF8));
        pushButton_68->setShortcut(QApplication::translate("MainWindow", "Ctrl+Del", 0, QApplication::UnicodeUTF8));
        pushButton_72->setText(QApplication::translate("MainWindow", "SUM", 0, QApplication::UnicodeUTF8));
        pushButton_72->setShortcut(QApplication::translate("MainWindow", "Ctrl++", 0, QApplication::UnicodeUTF8));
        pushButton_69->setText(QApplication::translate("MainWindow", "DUP", 0, QApplication::UnicodeUTF8));
        pushButton_69->setShortcut(QApplication::translate("MainWindow", "Return", 0, QApplication::UnicodeUTF8));
        pushButton_71->setText(QApplication::translate("MainWindow", "MEAN", 0, QApplication::UnicodeUTF8));
        pushButton_71->setShortcut(QApplication::translate("MainWindow", "Ctrl+/", 0, QApplication::UnicodeUTF8));
        pushButton_70->setText(QApplication::translate("MainWindow", "DROP", 0, QApplication::UnicodeUTF8));
        pushButton_70->setShortcut(QApplication::translate("MainWindow", "Del", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Pile", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
