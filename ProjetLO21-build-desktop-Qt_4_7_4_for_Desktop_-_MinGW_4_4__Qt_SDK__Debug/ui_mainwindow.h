/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri 8. Jun 03:20:03 2012
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
#include <QtGui/QFrame>
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
    QWidget *centralWidget;
    QGridLayout *gridLayout_7;
    QLineEdit *lineSaisie;
    QTabWidget *tabWidget_pile;
    QWidget *tab_7;
    QHBoxLayout *horizontalLayout;
    QListView *listView_pile;
    QWidget *tab_8;
    QHBoxLayout *horizontalLayout_3;
    QListView *listView_2;
    QHBoxLayout *paramSaisie;
    QCheckBox *checkBox_complexe;
    QRadioButton *radioButton_reel;
    QRadioButton *radioButton_rationnel;
    QRadioButton *radioButton_entier;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBox_calculAuto;
    QSpacerItem *verticalSpacer;
    QTabWidget *tabWidget_saisie;
    QWidget *tab_basique;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_tabBasique;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_diviser;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_fois;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_moins;
    QPushButton *pushButton_0;
    QPushButton *pushButton_del;
    QPushButton *pushButton_plus;
    QWidget *tab_divers;
    QHBoxLayout *horizontalLayout_4;
    QGridLayout *gridLayout_tabDivers;
    QPushButton *pushButton_pow;
    QPushButton *pushButton_inv;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_sign;
    QPushButton *pushButton_fact;
    QPushButton *pushButton_sqr;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_cube;
    QPushButton *pushButton_log;
    QPushButton *pushButton_eval;
    QWidget *tab_trigo;
    QHBoxLayout *horizontalLayout_5;
    QGridLayout *gridLayout_tabTrigo;
    QPushButton *pushButton_sin;
    QRadioButton *radioButton_radian;
    QPushButton *pushButton_cos;
    QRadioButton *radioButton_degre;
    QPushButton *pushButton_tan;
    QCheckBox *checkBox_hyperbolic;
    QFrame *line;
    QWidget *tab_pile;
    QHBoxLayout *horizontalLayout_6;
    QGridLayout *gridLayout_tabPile;
    QPushButton *pushButton_swap;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_sum;
    QPushButton *pushButton_dup;
    QPushButton *pushButton_mean;
    QPushButton *pushButton_drop;
    QPushButton *pushButton_space;
    QStatusBar *statusBar;
    QButtonGroup *buttonGroup_type;
    QButtonGroup *buttonGroup_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(750, 360);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_7 = new QGridLayout(centralWidget);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        lineSaisie = new QLineEdit(centralWidget);
        lineSaisie->setObjectName(QString::fromUtf8("lineSaisie"));
        lineSaisie->setMouseTracking(false);
        lineSaisie->setAcceptDrops(false);
        lineSaisie->setInputMethodHints(Qt::ImhUppercaseOnly);
        lineSaisie->setReadOnly(true);

        gridLayout_7->addWidget(lineSaisie, 0, 0, 1, 1);

        tabWidget_pile = new QTabWidget(centralWidget);
        tabWidget_pile->setObjectName(QString::fromUtf8("tabWidget_pile"));
        tabWidget_pile->setMinimumSize(QSize(250, 0));
        tabWidget_pile->setTabsClosable(true);
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        horizontalLayout = new QHBoxLayout(tab_7);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        listView_pile = new QListView(tab_7);
        listView_pile->setObjectName(QString::fromUtf8("listView_pile"));

        horizontalLayout->addWidget(listView_pile);

        tabWidget_pile->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        horizontalLayout_3 = new QHBoxLayout(tab_8);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        listView_2 = new QListView(tab_8);
        listView_2->setObjectName(QString::fromUtf8("listView_2"));

        horizontalLayout_3->addWidget(listView_2);

        tabWidget_pile->addTab(tab_8, QString());

        gridLayout_7->addWidget(tabWidget_pile, 0, 1, 5, 1);

        paramSaisie = new QHBoxLayout();
        paramSaisie->setSpacing(6);
        paramSaisie->setObjectName(QString::fromUtf8("paramSaisie"));
        checkBox_complexe = new QCheckBox(centralWidget);
        checkBox_complexe->setObjectName(QString::fromUtf8("checkBox_complexe"));

        paramSaisie->addWidget(checkBox_complexe);

        radioButton_reel = new QRadioButton(centralWidget);
        buttonGroup_type = new QButtonGroup(MainWindow);
        buttonGroup_type->setObjectName(QString::fromUtf8("buttonGroup_type"));
        buttonGroup_type->addButton(radioButton_reel);
        radioButton_reel->setObjectName(QString::fromUtf8("radioButton_reel"));
        radioButton_reel->setEnabled(true);
        radioButton_reel->setCheckable(true);
        radioButton_reel->setChecked(true);

        paramSaisie->addWidget(radioButton_reel);

        radioButton_rationnel = new QRadioButton(centralWidget);
        buttonGroup_type->addButton(radioButton_rationnel);
        radioButton_rationnel->setObjectName(QString::fromUtf8("radioButton_rationnel"));
        radioButton_rationnel->setCheckable(true);

        paramSaisie->addWidget(radioButton_rationnel);

        radioButton_entier = new QRadioButton(centralWidget);
        buttonGroup_type->addButton(radioButton_entier);
        radioButton_entier->setObjectName(QString::fromUtf8("radioButton_entier"));

        paramSaisie->addWidget(radioButton_entier);

        horizontalSpacer = new QSpacerItem(13, 16, QSizePolicy::Expanding, QSizePolicy::Minimum);

        paramSaisie->addItem(horizontalSpacer);

        checkBox_calculAuto = new QCheckBox(centralWidget);
        checkBox_calculAuto->setObjectName(QString::fromUtf8("checkBox_calculAuto"));
        checkBox_calculAuto->setChecked(true);

        paramSaisie->addWidget(checkBox_calculAuto);


        gridLayout_7->addLayout(paramSaisie, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 1000, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer, 4, 0, 1, 1);

        tabWidget_saisie = new QTabWidget(centralWidget);
        tabWidget_saisie->setObjectName(QString::fromUtf8("tabWidget_saisie"));
        tab_basique = new QWidget();
        tab_basique->setObjectName(QString::fromUtf8("tab_basique"));
        gridLayout_2 = new QGridLayout(tab_basique);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_tabBasique = new QGridLayout();
        gridLayout_tabBasique->setSpacing(6);
        gridLayout_tabBasique->setObjectName(QString::fromUtf8("gridLayout_tabBasique"));
        pushButton_7 = new QPushButton(tab_basique);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        gridLayout_tabBasique->addWidget(pushButton_7, 0, 0, 1, 1);

        pushButton_8 = new QPushButton(tab_basique);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        gridLayout_tabBasique->addWidget(pushButton_8, 0, 1, 1, 1);

        pushButton_9 = new QPushButton(tab_basique);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        gridLayout_tabBasique->addWidget(pushButton_9, 0, 3, 1, 1);

        pushButton_diviser = new QPushButton(tab_basique);
        pushButton_diviser->setObjectName(QString::fromUtf8("pushButton_diviser"));

        gridLayout_tabBasique->addWidget(pushButton_diviser, 0, 4, 1, 1);

        pushButton_4 = new QPushButton(tab_basique);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout_tabBasique->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton_5 = new QPushButton(tab_basique);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout_tabBasique->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_6 = new QPushButton(tab_basique);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout_tabBasique->addWidget(pushButton_6, 1, 3, 1, 1);

        pushButton_fois = new QPushButton(tab_basique);
        pushButton_fois->setObjectName(QString::fromUtf8("pushButton_fois"));

        gridLayout_tabBasique->addWidget(pushButton_fois, 1, 4, 1, 1);

        pushButton_1 = new QPushButton(tab_basique);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));

        gridLayout_tabBasique->addWidget(pushButton_1, 2, 0, 1, 1);

        pushButton_2 = new QPushButton(tab_basique);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_tabBasique->addWidget(pushButton_2, 2, 1, 1, 1);

        pushButton_3 = new QPushButton(tab_basique);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout_tabBasique->addWidget(pushButton_3, 2, 3, 1, 1);

        pushButton_moins = new QPushButton(tab_basique);
        pushButton_moins->setObjectName(QString::fromUtf8("pushButton_moins"));

        gridLayout_tabBasique->addWidget(pushButton_moins, 2, 4, 1, 1);

        pushButton_0 = new QPushButton(tab_basique);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));

        gridLayout_tabBasique->addWidget(pushButton_0, 3, 0, 1, 2);

        pushButton_del = new QPushButton(tab_basique);
        pushButton_del->setObjectName(QString::fromUtf8("pushButton_del"));

        gridLayout_tabBasique->addWidget(pushButton_del, 3, 3, 1, 1);

        pushButton_plus = new QPushButton(tab_basique);
        pushButton_plus->setObjectName(QString::fromUtf8("pushButton_plus"));

        gridLayout_tabBasique->addWidget(pushButton_plus, 3, 4, 1, 1);


        gridLayout_2->addLayout(gridLayout_tabBasique, 0, 0, 1, 1);

        tabWidget_saisie->addTab(tab_basique, QString());
        tab_divers = new QWidget();
        tab_divers->setObjectName(QString::fromUtf8("tab_divers"));
        horizontalLayout_4 = new QHBoxLayout(tab_divers);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        gridLayout_tabDivers = new QGridLayout();
        gridLayout_tabDivers->setSpacing(6);
        gridLayout_tabDivers->setObjectName(QString::fromUtf8("gridLayout_tabDivers"));
        pushButton_pow = new QPushButton(tab_divers);
        pushButton_pow->setObjectName(QString::fromUtf8("pushButton_pow"));

        gridLayout_tabDivers->addWidget(pushButton_pow, 0, 0, 1, 1);

        pushButton_inv = new QPushButton(tab_divers);
        pushButton_inv->setObjectName(QString::fromUtf8("pushButton_inv"));

        gridLayout_tabDivers->addWidget(pushButton_inv, 0, 1, 1, 1);

        pushButton_mod = new QPushButton(tab_divers);
        pushButton_mod->setObjectName(QString::fromUtf8("pushButton_mod"));

        gridLayout_tabDivers->addWidget(pushButton_mod, 0, 2, 1, 1);

        pushButton_sqrt = new QPushButton(tab_divers);
        pushButton_sqrt->setObjectName(QString::fromUtf8("pushButton_sqrt"));

        gridLayout_tabDivers->addWidget(pushButton_sqrt, 1, 0, 1, 1);

        pushButton_sign = new QPushButton(tab_divers);
        pushButton_sign->setObjectName(QString::fromUtf8("pushButton_sign"));

        gridLayout_tabDivers->addWidget(pushButton_sign, 1, 1, 1, 1);

        pushButton_fact = new QPushButton(tab_divers);
        pushButton_fact->setObjectName(QString::fromUtf8("pushButton_fact"));

        gridLayout_tabDivers->addWidget(pushButton_fact, 1, 2, 1, 1);

        pushButton_sqr = new QPushButton(tab_divers);
        pushButton_sqr->setObjectName(QString::fromUtf8("pushButton_sqr"));

        gridLayout_tabDivers->addWidget(pushButton_sqr, 3, 0, 1, 1);

        pushButton_ln = new QPushButton(tab_divers);
        pushButton_ln->setObjectName(QString::fromUtf8("pushButton_ln"));

        gridLayout_tabDivers->addWidget(pushButton_ln, 3, 1, 1, 1);

        pushButton_cube = new QPushButton(tab_divers);
        pushButton_cube->setObjectName(QString::fromUtf8("pushButton_cube"));

        gridLayout_tabDivers->addWidget(pushButton_cube, 4, 0, 1, 1);

        pushButton_log = new QPushButton(tab_divers);
        pushButton_log->setObjectName(QString::fromUtf8("pushButton_log"));

        gridLayout_tabDivers->addWidget(pushButton_log, 4, 1, 1, 1);

        pushButton_eval = new QPushButton(tab_divers);
        pushButton_eval->setObjectName(QString::fromUtf8("pushButton_eval"));

        gridLayout_tabDivers->addWidget(pushButton_eval, 3, 2, 1, 1);


        horizontalLayout_4->addLayout(gridLayout_tabDivers);

        tabWidget_saisie->addTab(tab_divers, QString());
        tab_trigo = new QWidget();
        tab_trigo->setObjectName(QString::fromUtf8("tab_trigo"));
        horizontalLayout_5 = new QHBoxLayout(tab_trigo);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        gridLayout_tabTrigo = new QGridLayout();
        gridLayout_tabTrigo->setSpacing(6);
        gridLayout_tabTrigo->setObjectName(QString::fromUtf8("gridLayout_tabTrigo"));
        pushButton_sin = new QPushButton(tab_trigo);
        pushButton_sin->setObjectName(QString::fromUtf8("pushButton_sin"));

        gridLayout_tabTrigo->addWidget(pushButton_sin, 0, 0, 1, 1);

        radioButton_radian = new QRadioButton(tab_trigo);
        buttonGroup_2 = new QButtonGroup(MainWindow);
        buttonGroup_2->setObjectName(QString::fromUtf8("buttonGroup_2"));
        buttonGroup_2->addButton(radioButton_radian);
        radioButton_radian->setObjectName(QString::fromUtf8("radioButton_radian"));
        radioButton_radian->setChecked(true);

        gridLayout_tabTrigo->addWidget(radioButton_radian, 0, 2, 1, 1);

        pushButton_cos = new QPushButton(tab_trigo);
        pushButton_cos->setObjectName(QString::fromUtf8("pushButton_cos"));

        gridLayout_tabTrigo->addWidget(pushButton_cos, 1, 0, 1, 1);

        radioButton_degre = new QRadioButton(tab_trigo);
        buttonGroup_2->addButton(radioButton_degre);
        radioButton_degre->setObjectName(QString::fromUtf8("radioButton_degre"));

        gridLayout_tabTrigo->addWidget(radioButton_degre, 1, 2, 1, 1);

        pushButton_tan = new QPushButton(tab_trigo);
        pushButton_tan->setObjectName(QString::fromUtf8("pushButton_tan"));

        gridLayout_tabTrigo->addWidget(pushButton_tan, 2, 0, 1, 1);

        checkBox_hyperbolic = new QCheckBox(tab_trigo);
        checkBox_hyperbolic->setObjectName(QString::fromUtf8("checkBox_hyperbolic"));

        gridLayout_tabTrigo->addWidget(checkBox_hyperbolic, 2, 2, 1, 1);

        line = new QFrame(tab_trigo);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_tabTrigo->addWidget(line, 0, 1, 3, 1);


        horizontalLayout_5->addLayout(gridLayout_tabTrigo);

        tabWidget_saisie->addTab(tab_trigo, QString());
        tab_pile = new QWidget();
        tab_pile->setObjectName(QString::fromUtf8("tab_pile"));
        horizontalLayout_6 = new QHBoxLayout(tab_pile);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        gridLayout_tabPile = new QGridLayout();
        gridLayout_tabPile->setSpacing(6);
        gridLayout_tabPile->setObjectName(QString::fromUtf8("gridLayout_tabPile"));
        pushButton_swap = new QPushButton(tab_pile);
        pushButton_swap->setObjectName(QString::fromUtf8("pushButton_swap"));

        gridLayout_tabPile->addWidget(pushButton_swap, 0, 0, 1, 1);

        pushButton_clear = new QPushButton(tab_pile);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));

        gridLayout_tabPile->addWidget(pushButton_clear, 0, 1, 1, 1);

        pushButton_sum = new QPushButton(tab_pile);
        pushButton_sum->setObjectName(QString::fromUtf8("pushButton_sum"));

        gridLayout_tabPile->addWidget(pushButton_sum, 1, 0, 1, 1);

        pushButton_dup = new QPushButton(tab_pile);
        pushButton_dup->setObjectName(QString::fromUtf8("pushButton_dup"));

        gridLayout_tabPile->addWidget(pushButton_dup, 1, 1, 1, 1);

        pushButton_mean = new QPushButton(tab_pile);
        pushButton_mean->setObjectName(QString::fromUtf8("pushButton_mean"));

        gridLayout_tabPile->addWidget(pushButton_mean, 2, 0, 1, 1);

        pushButton_drop = new QPushButton(tab_pile);
        pushButton_drop->setObjectName(QString::fromUtf8("pushButton_drop"));

        gridLayout_tabPile->addWidget(pushButton_drop, 2, 1, 1, 1);


        horizontalLayout_6->addLayout(gridLayout_tabPile);

        tabWidget_saisie->addTab(tab_pile, QString());

        gridLayout_7->addWidget(tabWidget_saisie, 2, 0, 1, 1);

        pushButton_space = new QPushButton(centralWidget);
        pushButton_space->setObjectName(QString::fromUtf8("pushButton_space"));

        gridLayout_7->addWidget(pushButton_space, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(tabWidget_saisie, checkBox_complexe);
        QWidget::setTabOrder(checkBox_complexe, radioButton_reel);
        QWidget::setTabOrder(radioButton_reel, radioButton_rationnel);
        QWidget::setTabOrder(radioButton_rationnel, radioButton_entier);
        QWidget::setTabOrder(radioButton_entier, checkBox_calculAuto);
        QWidget::setTabOrder(checkBox_calculAuto, tabWidget_pile);
        QWidget::setTabOrder(tabWidget_pile, pushButton_space);
        QWidget::setTabOrder(pushButton_space, pushButton_pow);
        QWidget::setTabOrder(pushButton_pow, pushButton_inv);
        QWidget::setTabOrder(pushButton_inv, pushButton_mod);
        QWidget::setTabOrder(pushButton_mod, pushButton_sqrt);
        QWidget::setTabOrder(pushButton_sqrt, pushButton_sign);
        QWidget::setTabOrder(pushButton_sign, pushButton_fact);
        QWidget::setTabOrder(pushButton_fact, pushButton_sqr);
        QWidget::setTabOrder(pushButton_sqr, pushButton_ln);
        QWidget::setTabOrder(pushButton_ln, pushButton_cube);
        QWidget::setTabOrder(pushButton_cube, pushButton_log);
        QWidget::setTabOrder(pushButton_log, pushButton_sin);
        QWidget::setTabOrder(pushButton_sin, pushButton_cos);
        QWidget::setTabOrder(pushButton_cos, pushButton_tan);
        QWidget::setTabOrder(pushButton_tan, radioButton_radian);
        QWidget::setTabOrder(radioButton_radian, radioButton_degre);
        QWidget::setTabOrder(radioButton_degre, checkBox_hyperbolic);
        QWidget::setTabOrder(checkBox_hyperbolic, pushButton_swap);
        QWidget::setTabOrder(pushButton_swap, pushButton_clear);
        QWidget::setTabOrder(pushButton_clear, pushButton_sum);
        QWidget::setTabOrder(pushButton_sum, pushButton_dup);
        QWidget::setTabOrder(pushButton_dup, pushButton_mean);
        QWidget::setTabOrder(pushButton_mean, pushButton_drop);
        QWidget::setTabOrder(pushButton_drop, listView_pile);
        QWidget::setTabOrder(listView_pile, listView_2);
        QWidget::setTabOrder(listView_2, lineSaisie);

        retranslateUi(MainWindow);

        tabWidget_pile->setCurrentIndex(1);
        tabWidget_saisie->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Calculatrice \303\240 Notation Polonaise Invers\303\251e - Amhed & JB", 0, QApplication::UnicodeUTF8));
        tabWidget_pile->setTabText(tabWidget_pile->indexOf(tab_7), QApplication::translate("MainWindow", "Pile 1", 0, QApplication::UnicodeUTF8));
        tabWidget_pile->setTabText(tabWidget_pile->indexOf(tab_8), QApplication::translate("MainWindow", "Pile 2", 0, QApplication::UnicodeUTF8));
        checkBox_complexe->setText(QApplication::translate("MainWindow", "Complexe", 0, QApplication::UnicodeUTF8));
        checkBox_complexe->setShortcut(QApplication::translate("MainWindow", "F1", 0, QApplication::UnicodeUTF8));
        radioButton_reel->setText(QApplication::translate("MainWindow", "Reel", 0, QApplication::UnicodeUTF8));
        radioButton_reel->setShortcut(QApplication::translate("MainWindow", "F2", 0, QApplication::UnicodeUTF8));
        radioButton_rationnel->setText(QApplication::translate("MainWindow", "Rationnel", 0, QApplication::UnicodeUTF8));
        radioButton_rationnel->setShortcut(QApplication::translate("MainWindow", "F3", 0, QApplication::UnicodeUTF8));
        radioButton_entier->setText(QApplication::translate("MainWindow", "Entier", 0, QApplication::UnicodeUTF8));
        radioButton_entier->setShortcut(QApplication::translate("MainWindow", "F4", 0, QApplication::UnicodeUTF8));
        checkBox_calculAuto->setText(QApplication::translate("MainWindow", "Calcul auto", 0, QApplication::UnicodeUTF8));
        checkBox_calculAuto->setShortcut(QApplication::translate("MainWindow", "'", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tabWidget_saisie->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tabWidget_saisie->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        tab_basique->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        pushButton_7->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        pushButton_diviser->setText(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        pushButton_fois->setText(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        pushButton_1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        pushButton_moins->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        pushButton_0->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        pushButton_del->setText(QApplication::translate("MainWindow", "DEL", 0, QApplication::UnicodeUTF8));
        pushButton_plus->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        tabWidget_saisie->setTabText(tabWidget_saisie->indexOf(tab_basique), QApplication::translate("MainWindow", "Basiq&ue", 0, QApplication::UnicodeUTF8));
        tabWidget_saisie->setTabToolTip(tabWidget_saisie->indexOf(tab_basique), QApplication::translate("MainWindow", "Pav\303\251 num\303\251rique et de calcul de base\n"
"Raccourci : U\n"
"NB: les boutons sont perp\303\251tuellement rattach\303\251s aux touches de clavier correspondantes", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_pow->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">D\303\251pile X puis Y et effectue Y puissance X</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-style:italic;\">X: Entier, Rationnel, R\303\251el</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-style:italic;\">Y: Entier, Rationnel, R\303\251el</span></p>\n"
"<p align=\"right\" styl"
                        "e=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-style:italic;\">Rac.: **</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButton_pow->setText(QApplication::translate("MainWindow", "POW", 0, QApplication::UnicodeUTF8));
        pushButton_pow->setShortcut(QApplication::translate("MainWindow", "W", 0, QApplication::UnicodeUTF8));
        pushButton_inv->setText(QApplication::translate("MainWindow", "INV", 0, QApplication::UnicodeUTF8));
        pushButton_inv->setShortcut(QApplication::translate("MainWindow", "V", 0, QApplication::UnicodeUTF8));
        pushButton_mod->setText(QApplication::translate("MainWindow", "MOD", 0, QApplication::UnicodeUTF8));
        pushButton_mod->setShortcut(QApplication::translate("MainWindow", "%", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_sqrt->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">D\303\251pile X et rempile sa racine carr\303\251e</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-style:italic;\">X: Entier, Rationnel, R\303\251el</span></p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-style:italic;\">Rac.: </span><span style=\" font-size:8pt; font-weight"
                        ":600;\">^</span><span style=\" font-size:8pt; font-style:italic;\">+</span><span style=\" font-size:8pt; font-weight:600;\">/</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButton_sqrt->setText(QApplication::translate("MainWindow", "SQRT", 0, QApplication::UnicodeUTF8));
        pushButton_sqrt->setShortcut(QApplication::translate("MainWindow", "Q", 0, QApplication::UnicodeUTF8));
        pushButton_sign->setText(QApplication::translate("MainWindow", "SIGN", 0, QApplication::UnicodeUTF8));
        pushButton_sign->setShortcut(QApplication::translate("MainWindow", "S", 0, QApplication::UnicodeUTF8));
        pushButton_fact->setText(QApplication::translate("MainWindow", "FACT", 0, QApplication::UnicodeUTF8));
        pushButton_fact->setShortcut(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        pushButton_sqr->setText(QApplication::translate("MainWindow", "SQR", 0, QApplication::UnicodeUTF8));
        pushButton_sqr->setShortcut(QApplication::translate("MainWindow", "\302\262", 0, QApplication::UnicodeUTF8));
        pushButton_ln->setText(QApplication::translate("MainWindow", "LN", 0, QApplication::UnicodeUTF8));
        pushButton_ln->setShortcut(QApplication::translate("MainWindow", "L", 0, QApplication::UnicodeUTF8));
        pushButton_cube->setText(QApplication::translate("MainWindow", "CUBE", 0, QApplication::UnicodeUTF8));
        pushButton_cube->setShortcut(QApplication::translate("MainWindow", "B", 0, QApplication::UnicodeUTF8));
        pushButton_log->setText(QApplication::translate("MainWindow", "LOG", 0, QApplication::UnicodeUTF8));
        pushButton_log->setShortcut(QApplication::translate("MainWindow", "O", 0, QApplication::UnicodeUTF8));
        pushButton_eval->setText(QApplication::translate("MainWindow", "EVAL", 0, QApplication::UnicodeUTF8));
        pushButton_eval->setShortcut(QApplication::translate("MainWindow", "=", 0, QApplication::UnicodeUTF8));
        tabWidget_saisie->setTabText(tabWidget_saisie->indexOf(tab_divers), QApplication::translate("MainWindow", "D&ivers", 0, QApplication::UnicodeUTF8));
        tabWidget_saisie->setTabToolTip(tabWidget_saisie->indexOf(tab_divers), QApplication::translate("MainWindow", "Diverses fonctions math\303\251matiques\n"
"Raccourci : I", 0, QApplication::UnicodeUTF8));
        pushButton_sin->setText(QApplication::translate("MainWindow", "SIN", 0, QApplication::UnicodeUTF8));
        pushButton_sin->setShortcut(QApplication::translate("MainWindow", "S", 0, QApplication::UnicodeUTF8));
        radioButton_radian->setText(QApplication::translate("MainWindow", "Radian", 0, QApplication::UnicodeUTF8));
        radioButton_radian->setShortcut(QApplication::translate("MainWindow", "R", 0, QApplication::UnicodeUTF8));
        pushButton_cos->setText(QApplication::translate("MainWindow", "COS", 0, QApplication::UnicodeUTF8));
        pushButton_cos->setShortcut(QApplication::translate("MainWindow", "C", 0, QApplication::UnicodeUTF8));
        radioButton_degre->setText(QApplication::translate("MainWindow", "Degr\303\251", 0, QApplication::UnicodeUTF8));
        radioButton_degre->setShortcut(QApplication::translate("MainWindow", "D", 0, QApplication::UnicodeUTF8));
        pushButton_tan->setText(QApplication::translate("MainWindow", "TAN", 0, QApplication::UnicodeUTF8));
        pushButton_tan->setShortcut(QApplication::translate("MainWindow", "T", 0, QApplication::UnicodeUTF8));
        checkBox_hyperbolic->setText(QApplication::translate("MainWindow", "Hyperbolic", 0, QApplication::UnicodeUTF8));
        checkBox_hyperbolic->setShortcut(QApplication::translate("MainWindow", "H", 0, QApplication::UnicodeUTF8));
        tabWidget_saisie->setTabText(tabWidget_saisie->indexOf(tab_trigo), QApplication::translate("MainWindow", "Trig&o", 0, QApplication::UnicodeUTF8));
        tabWidget_saisie->setTabToolTip(tabWidget_saisie->indexOf(tab_trigo), QApplication::translate("MainWindow", "Fonctions trigonom\303\251triques\n"
"Raccourci : O", 0, QApplication::UnicodeUTF8));
        pushButton_swap->setText(QApplication::translate("MainWindow", "SWAP", 0, QApplication::UnicodeUTF8));
        pushButton_swap->setShortcut(QApplication::translate("MainWindow", "<", 0, QApplication::UnicodeUTF8));
        pushButton_clear->setText(QApplication::translate("MainWindow", "CLEAR", 0, QApplication::UnicodeUTF8));
        pushButton_clear->setShortcut(QApplication::translate("MainWindow", "Ctrl+Del", 0, QApplication::UnicodeUTF8));
        pushButton_sum->setText(QApplication::translate("MainWindow", "SUM", 0, QApplication::UnicodeUTF8));
        pushButton_sum->setShortcut(QApplication::translate("MainWindow", "Ctrl++", 0, QApplication::UnicodeUTF8));
        pushButton_dup->setText(QApplication::translate("MainWindow", "DUP", 0, QApplication::UnicodeUTF8));
        pushButton_dup->setShortcut(QApplication::translate("MainWindow", "Return", 0, QApplication::UnicodeUTF8));
        pushButton_mean->setText(QApplication::translate("MainWindow", "MEAN", 0, QApplication::UnicodeUTF8));
        pushButton_mean->setShortcut(QApplication::translate("MainWindow", "Ctrl+/", 0, QApplication::UnicodeUTF8));
        pushButton_drop->setText(QApplication::translate("MainWindow", "DROP", 0, QApplication::UnicodeUTF8));
        pushButton_drop->setShortcut(QApplication::translate("MainWindow", "Del", 0, QApplication::UnicodeUTF8));
        tabWidget_saisie->setTabText(tabWidget_saisie->indexOf(tab_pile), QApplication::translate("MainWindow", "&Pile", 0, QApplication::UnicodeUTF8));
        tabWidget_saisie->setTabToolTip(tabWidget_saisie->indexOf(tab_pile), QApplication::translate("MainWindow", "Fonctions pour agir sur la pile.\n"
"Raccourci : P", 0, QApplication::UnicodeUTF8));
        pushButton_space->setText(QApplication::translate("MainWindow", "Espace / Valider / Point / Virgule / Dollar / Slash", 0, QApplication::UnicodeUTF8));
        pushButton_space->setShortcut(QApplication::translate("MainWindow", "Space", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
