/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Oct 10 13:45:12 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidgetMain;
    QWidget *tab1;
    QGroupBox *groupBoxDetail;
    QLabel *label;
    QLabel *labelARenouvelerPatient;
    QLabel *labelARenouvelerPresDateFin;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *labelARenouvelerPresType;
    QLabel *label_5;
    QLabel *labelARenouvelerPresModeR;
    QLabel *labelARenouvelerPresDuree;
    QLabel *label_6;
    QLabel *labelARenouvelerMedNumNom;
    QLabel *labelARenouvelerMedAd2;
    QLabel *label_20;
    QLabel *labelARenouvelerMedAd1;
    QLabel *labelARenouvelerMedCPVille;
    QLabel *labelARenouvelerMedTel;
    QGroupBox *groupBox;
    QListWidget *listWidgetPrescriptionsARenouveler;
    QGroupBox *groupBox_2;
    QPushButton *pushButtonARenouvelerRenouveler;
    QDateEdit *dateEditARenouvelerPresDateFin;
    QWidget *tab2;
    QGroupBox *groupBox_9;
    QListWidget *listWidgetPrescriptions;
    QGroupBox *groupBox_10;
    QLabel *label_17;
    QLabel *label_18;
    QComboBox *comboBoxPrescriptionPatient;
    QDateEdit *dateEditPrescriptionDateDebut;
    QLabel *label_19;
    QSpinBox *spinBoxPrescriptionDuree;
    QLabel *label_21;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButtonOrdonnance;
    QRadioButton *radioButtonDSI;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButtonPatient;
    QRadioButton *radioButtonMedecin;
    QGroupBox *groupBox_11;
    QPushButton *pushButtonPrescriptionAjouter;
    QPushButton *pushButtonPrescriptionModifier;
    QPushButton *pushButtonPrescriptionAbandonner;
    QPushButton *pushButtonPrescriptionSupprimer;
    QWidget *tab3;
    QGroupBox *groupBox_6;
    QPushButton *pushButtonPatientAjouter;
    QPushButton *pushButtonPatientModifier;
    QPushButton *pushButtonPatientAbandonner;
    QPushButton *pushButtonPatientSupprimer;
    QGroupBox *groupBox_7;
    QListWidget *listWidgetPatients;
    QGroupBox *groupBox_8;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *lineEditPatientNom;
    QLineEdit *lineEditPatientNumSS;
    QLabel *label_16;
    QComboBox *comboBoxPatientMedecin;
    QWidget *tab4;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QPushButton *pushButtonMedecinAjouter;
    QPushButton *pushButtonMedecinModifier;
    QPushButton *pushButtonMedecinAbandonner;
    QPushButton *pushButtonMedecinSupprimer;
    QGroupBox *groupBox_4;
    QListWidget *listWidgetMedecins;
    QGroupBox *groupBox_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEditMedecinNom;
    QLineEdit *lineEditMedecinNumSS;
    QLineEdit *lineEditMedecinAdr2;
    QLineEdit *lineEditMedecinAdr1;
    QLineEdit *lineEditMedecinCP;
    QLineEdit *lineEditMedecinVille;
    QLabel *label_10;
    QLineEdit *lineEditMedecinTel;
    QWidget *tab5;
    QGroupBox *groupBox_12;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEditParametresCPMedecin;
    QLineEdit *lineEditParametreVilleMedecin;
    QGroupBox *groupBox_13;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLabel *label_13;
    QSpinBox *spinBoxParametreDureeDSI;
    QLabel *label_24;
    QLabel *label_22;
    QSpinBox *spinBoxPrescriptionDureeOdronnance;
    QLabel *label_23;
    QGroupBox *groupBox_14;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_4;
    QPushButton *pushButtonPrescriptionEnregistrer;
    QPushButton *pushButtonReinitialiser;
    QGroupBox *groupBox_15;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout_5;
    QSpinBox *spinBoxParametreARenouvelerTemps;
    QLabel *label_25;
    QLabel *label_26;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(700, 518);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidgetMain = new QTabWidget(centralWidget);
        tabWidgetMain->setObjectName(QString::fromUtf8("tabWidgetMain"));
        tabWidgetMain->setMinimumSize(QSize(682, 432));
        tabWidgetMain->setMaximumSize(QSize(682, 432));
        QFont font;
        font.setPointSize(10);
        tabWidgetMain->setFont(font);
        tabWidgetMain->setTabPosition(QTabWidget::North);
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        groupBoxDetail = new QGroupBox(tab1);
        groupBoxDetail->setObjectName(QString::fromUtf8("groupBoxDetail"));
        groupBoxDetail->setGeometry(QRect(400, 0, 271, 321));
        groupBoxDetail->setCheckable(false);
        label = new QLabel(groupBoxDetail);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 71, 16));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        label->setFont(font1);
        labelARenouvelerPatient = new QLabel(groupBoxDetail);
        labelARenouvelerPatient->setObjectName(QString::fromUtf8("labelARenouvelerPatient"));
        labelARenouvelerPatient->setGeometry(QRect(10, 40, 251, 16));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        labelARenouvelerPatient->setFont(font2);
        labelARenouvelerPresDateFin = new QLabel(groupBoxDetail);
        labelARenouvelerPresDateFin->setObjectName(QString::fromUtf8("labelARenouvelerPresDateFin"));
        labelARenouvelerPresDateFin->setGeometry(QRect(120, 90, 111, 16));
        labelARenouvelerPresDateFin->setFont(font2);
        label_2 = new QLabel(groupBoxDetail);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 91, 16));
        QFont font3;
        font3.setBold(true);
        font3.setItalic(true);
        font3.setUnderline(true);
        font3.setWeight(75);
        font3.setStrikeOut(false);
        label_2->setFont(font3);
        label_3 = new QLabel(groupBoxDetail);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 90, 111, 16));
        label_4 = new QLabel(groupBoxDetail);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 130, 131, 16));
        labelARenouvelerPresType = new QLabel(groupBoxDetail);
        labelARenouvelerPresType->setObjectName(QString::fromUtf8("labelARenouvelerPresType"));
        labelARenouvelerPresType->setGeometry(QRect(150, 130, 111, 16));
        labelARenouvelerPresType->setFont(font2);
        label_5 = new QLabel(groupBoxDetail);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 150, 141, 16));
        labelARenouvelerPresModeR = new QLabel(groupBoxDetail);
        labelARenouvelerPresModeR->setObjectName(QString::fromUtf8("labelARenouvelerPresModeR"));
        labelARenouvelerPresModeR->setGeometry(QRect(160, 150, 111, 16));
        labelARenouvelerPresModeR->setFont(font2);
        labelARenouvelerPresDuree = new QLabel(groupBoxDetail);
        labelARenouvelerPresDuree->setObjectName(QString::fromUtf8("labelARenouvelerPresDuree"));
        labelARenouvelerPresDuree->setGeometry(QRect(180, 110, 81, 20));
        labelARenouvelerPresDuree->setFont(font2);
        label_6 = new QLabel(groupBoxDetail);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 110, 161, 16));
        labelARenouvelerMedNumNom = new QLabel(groupBoxDetail);
        labelARenouvelerMedNumNom->setObjectName(QString::fromUtf8("labelARenouvelerMedNumNom"));
        labelARenouvelerMedNumNom->setGeometry(QRect(10, 200, 251, 20));
        labelARenouvelerMedNumNom->setFont(font2);
        labelARenouvelerMedAd2 = new QLabel(groupBoxDetail);
        labelARenouvelerMedAd2->setObjectName(QString::fromUtf8("labelARenouvelerMedAd2"));
        labelARenouvelerMedAd2->setGeometry(QRect(10, 240, 251, 16));
        label_20 = new QLabel(groupBoxDetail);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 180, 91, 16));
        label_20->setFont(font3);
        labelARenouvelerMedAd1 = new QLabel(groupBoxDetail);
        labelARenouvelerMedAd1->setObjectName(QString::fromUtf8("labelARenouvelerMedAd1"));
        labelARenouvelerMedAd1->setGeometry(QRect(10, 220, 251, 16));
        labelARenouvelerMedCPVille = new QLabel(groupBoxDetail);
        labelARenouvelerMedCPVille->setObjectName(QString::fromUtf8("labelARenouvelerMedCPVille"));
        labelARenouvelerMedCPVille->setGeometry(QRect(10, 260, 251, 16));
        labelARenouvelerMedTel = new QLabel(groupBoxDetail);
        labelARenouvelerMedTel->setObjectName(QString::fromUtf8("labelARenouvelerMedTel"));
        labelARenouvelerMedTel->setGeometry(QRect(10, 280, 251, 16));
        groupBox = new QGroupBox(tab1);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 381, 391));
        listWidgetPrescriptionsARenouveler = new QListWidget(groupBox);
        listWidgetPrescriptionsARenouveler->setObjectName(QString::fromUtf8("listWidgetPrescriptionsARenouveler"));
        listWidgetPrescriptionsARenouveler->setGeometry(QRect(10, 20, 361, 361));
        groupBox_2 = new QGroupBox(tab1);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(400, 330, 271, 61));
        pushButtonARenouvelerRenouveler = new QPushButton(groupBox_2);
        pushButtonARenouvelerRenouveler->setObjectName(QString::fromUtf8("pushButtonARenouvelerRenouveler"));
        pushButtonARenouvelerRenouveler->setEnabled(false);
        pushButtonARenouvelerRenouveler->setGeometry(QRect(140, 20, 111, 23));
        dateEditARenouvelerPresDateFin = new QDateEdit(groupBox_2);
        dateEditARenouvelerPresDateFin->setObjectName(QString::fromUtf8("dateEditARenouvelerPresDateFin"));
        dateEditARenouvelerPresDateFin->setEnabled(false);
        dateEditARenouvelerPresDateFin->setGeometry(QRect(20, 20, 110, 22));
        dateEditARenouvelerPresDateFin->setAlignment(Qt::AlignCenter);
        dateEditARenouvelerPresDateFin->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));
        tabWidgetMain->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QString::fromUtf8("tab2"));
        groupBox_9 = new QGroupBox(tab2);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(10, 0, 381, 381));
        listWidgetPrescriptions = new QListWidget(groupBox_9);
        listWidgetPrescriptions->setObjectName(QString::fromUtf8("listWidgetPrescriptions"));
        listWidgetPrescriptions->setGeometry(QRect(10, 20, 361, 351));
        groupBox_10 = new QGroupBox(tab2);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setGeometry(QRect(400, 0, 271, 271));
        label_17 = new QLabel(groupBox_10);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 20, 61, 16));
        label_17->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_18 = new QLabel(groupBox_10);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 80, 171, 20));
        label_18->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        comboBoxPrescriptionPatient = new QComboBox(groupBox_10);
        comboBoxPrescriptionPatient->setObjectName(QString::fromUtf8("comboBoxPrescriptionPatient"));
        comboBoxPrescriptionPatient->setGeometry(QRect(10, 40, 251, 22));
        dateEditPrescriptionDateDebut = new QDateEdit(groupBox_10);
        dateEditPrescriptionDateDebut->setObjectName(QString::fromUtf8("dateEditPrescriptionDateDebut"));
        dateEditPrescriptionDateDebut->setGeometry(QRect(10, 100, 101, 22));
        dateEditPrescriptionDateDebut->setAlignment(Qt::AlignCenter);
        label_19 = new QLabel(groupBox_10);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 140, 171, 20));
        label_19->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        spinBoxPrescriptionDuree = new QSpinBox(groupBox_10);
        spinBoxPrescriptionDuree->setObjectName(QString::fromUtf8("spinBoxPrescriptionDuree"));
        spinBoxPrescriptionDuree->setGeometry(QRect(10, 160, 101, 22));
        spinBoxPrescriptionDuree->setAlignment(Qt::AlignCenter);
        label_21 = new QLabel(groupBox_10);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(120, 160, 71, 20));
        label_21->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        layoutWidget_2 = new QWidget(groupBox_10);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 220, 294, 30));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButtonOrdonnance = new QRadioButton(layoutWidget_2);
        radioButtonOrdonnance->setObjectName(QString::fromUtf8("radioButtonOrdonnance"));

        horizontalLayout_2->addWidget(radioButtonOrdonnance);

        radioButtonDSI = new QRadioButton(layoutWidget_2);
        radioButtonDSI->setObjectName(QString::fromUtf8("radioButtonDSI"));

        horizontalLayout_2->addWidget(radioButtonDSI);

        layoutWidget_3 = new QWidget(groupBox_10);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 190, 205, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioButtonPatient = new QRadioButton(layoutWidget_3);
        radioButtonPatient->setObjectName(QString::fromUtf8("radioButtonPatient"));

        horizontalLayout->addWidget(radioButtonPatient);

        radioButtonMedecin = new QRadioButton(layoutWidget_3);
        radioButtonMedecin->setObjectName(QString::fromUtf8("radioButtonMedecin"));

        horizontalLayout->addWidget(radioButtonMedecin);

        groupBox_11 = new QGroupBox(tab2);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        groupBox_11->setGeometry(QRect(400, 270, 271, 111));
        pushButtonPrescriptionAjouter = new QPushButton(groupBox_11);
        pushButtonPrescriptionAjouter->setObjectName(QString::fromUtf8("pushButtonPrescriptionAjouter"));
        pushButtonPrescriptionAjouter->setEnabled(false);
        pushButtonPrescriptionAjouter->setGeometry(QRect(20, 30, 111, 23));
        pushButtonPrescriptionModifier = new QPushButton(groupBox_11);
        pushButtonPrescriptionModifier->setObjectName(QString::fromUtf8("pushButtonPrescriptionModifier"));
        pushButtonPrescriptionModifier->setEnabled(false);
        pushButtonPrescriptionModifier->setGeometry(QRect(140, 30, 111, 23));
        pushButtonPrescriptionAbandonner = new QPushButton(groupBox_11);
        pushButtonPrescriptionAbandonner->setObjectName(QString::fromUtf8("pushButtonPrescriptionAbandonner"));
        pushButtonPrescriptionAbandonner->setEnabled(false);
        pushButtonPrescriptionAbandonner->setGeometry(QRect(20, 70, 111, 23));
        pushButtonPrescriptionSupprimer = new QPushButton(groupBox_11);
        pushButtonPrescriptionSupprimer->setObjectName(QString::fromUtf8("pushButtonPrescriptionSupprimer"));
        pushButtonPrescriptionSupprimer->setEnabled(false);
        pushButtonPrescriptionSupprimer->setGeometry(QRect(140, 70, 111, 23));
        tabWidgetMain->addTab(tab2, QString());
        tab3 = new QWidget();
        tab3->setObjectName(QString::fromUtf8("tab3"));
        groupBox_6 = new QGroupBox(tab3);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(400, 270, 271, 111));
        pushButtonPatientAjouter = new QPushButton(groupBox_6);
        pushButtonPatientAjouter->setObjectName(QString::fromUtf8("pushButtonPatientAjouter"));
        pushButtonPatientAjouter->setEnabled(false);
        pushButtonPatientAjouter->setGeometry(QRect(20, 30, 111, 23));
        pushButtonPatientModifier = new QPushButton(groupBox_6);
        pushButtonPatientModifier->setObjectName(QString::fromUtf8("pushButtonPatientModifier"));
        pushButtonPatientModifier->setEnabled(false);
        pushButtonPatientModifier->setGeometry(QRect(140, 30, 111, 23));
        pushButtonPatientAbandonner = new QPushButton(groupBox_6);
        pushButtonPatientAbandonner->setObjectName(QString::fromUtf8("pushButtonPatientAbandonner"));
        pushButtonPatientAbandonner->setEnabled(false);
        pushButtonPatientAbandonner->setGeometry(QRect(20, 70, 111, 23));
        pushButtonPatientSupprimer = new QPushButton(groupBox_6);
        pushButtonPatientSupprimer->setObjectName(QString::fromUtf8("pushButtonPatientSupprimer"));
        pushButtonPatientSupprimer->setEnabled(false);
        pushButtonPatientSupprimer->setGeometry(QRect(140, 70, 111, 23));
        groupBox_7 = new QGroupBox(tab3);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 0, 381, 381));
        listWidgetPatients = new QListWidget(groupBox_7);
        listWidgetPatients->setObjectName(QString::fromUtf8("listWidgetPatients"));
        listWidgetPatients->setGeometry(QRect(10, 20, 361, 351));
        groupBox_8 = new QGroupBox(tab3);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(400, 0, 271, 271));
        label_14 = new QLabel(groupBox_8);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 20, 61, 16));
        label_14->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_15 = new QLabel(groupBox_8);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 80, 171, 20));
        label_15->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEditPatientNom = new QLineEdit(groupBox_8);
        lineEditPatientNom->setObjectName(QString::fromUtf8("lineEditPatientNom"));
        lineEditPatientNom->setGeometry(QRect(10, 40, 251, 20));
        lineEditPatientNom->setMaxLength(50);
        lineEditPatientNumSS = new QLineEdit(groupBox_8);
        lineEditPatientNumSS->setObjectName(QString::fromUtf8("lineEditPatientNumSS"));
        lineEditPatientNumSS->setGeometry(QRect(10, 100, 251, 20));
        lineEditPatientNumSS->setMaxLength(30);
        label_16 = new QLabel(groupBox_8);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 140, 131, 16));
        comboBoxPatientMedecin = new QComboBox(groupBox_8);
        comboBoxPatientMedecin->setObjectName(QString::fromUtf8("comboBoxPatientMedecin"));
        comboBoxPatientMedecin->setGeometry(QRect(10, 160, 251, 22));
        tabWidgetMain->addTab(tab3, QString());
        tab4 = new QWidget();
        tab4->setObjectName(QString::fromUtf8("tab4"));
        groupBox_3 = new QGroupBox(tab4);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(400, 270, 271, 111));
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 251, 74));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButtonMedecinAjouter = new QPushButton(layoutWidget);
        pushButtonMedecinAjouter->setObjectName(QString::fromUtf8("pushButtonMedecinAjouter"));
        pushButtonMedecinAjouter->setEnabled(false);

        gridLayout_3->addWidget(pushButtonMedecinAjouter, 0, 0, 1, 1);

        pushButtonMedecinModifier = new QPushButton(layoutWidget);
        pushButtonMedecinModifier->setObjectName(QString::fromUtf8("pushButtonMedecinModifier"));
        pushButtonMedecinModifier->setEnabled(false);

        gridLayout_3->addWidget(pushButtonMedecinModifier, 0, 1, 1, 1);

        pushButtonMedecinAbandonner = new QPushButton(layoutWidget);
        pushButtonMedecinAbandonner->setObjectName(QString::fromUtf8("pushButtonMedecinAbandonner"));
        pushButtonMedecinAbandonner->setEnabled(false);

        gridLayout_3->addWidget(pushButtonMedecinAbandonner, 1, 0, 1, 1);

        pushButtonMedecinSupprimer = new QPushButton(layoutWidget);
        pushButtonMedecinSupprimer->setObjectName(QString::fromUtf8("pushButtonMedecinSupprimer"));
        pushButtonMedecinSupprimer->setEnabled(false);

        gridLayout_3->addWidget(pushButtonMedecinSupprimer, 1, 1, 1, 1);

        groupBox_4 = new QGroupBox(tab4);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 0, 381, 381));
        listWidgetMedecins = new QListWidget(groupBox_4);
        listWidgetMedecins->setObjectName(QString::fromUtf8("listWidgetMedecins"));
        listWidgetMedecins->setGeometry(QRect(10, 20, 361, 351));
        groupBox_5 = new QGroupBox(tab4);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(400, 0, 271, 271));
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 20, 61, 16));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 60, 111, 20));
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 110, 61, 16));
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEditMedecinNom = new QLineEdit(groupBox_5);
        lineEditMedecinNom->setObjectName(QString::fromUtf8("lineEditMedecinNom"));
        lineEditMedecinNom->setGeometry(QRect(10, 40, 251, 20));
        lineEditMedecinNom->setMaxLength(50);
        lineEditMedecinNumSS = new QLineEdit(groupBox_5);
        lineEditMedecinNumSS->setObjectName(QString::fromUtf8("lineEditMedecinNumSS"));
        lineEditMedecinNumSS->setGeometry(QRect(10, 80, 251, 20));
        lineEditMedecinNumSS->setMaxLength(10);
        lineEditMedecinAdr2 = new QLineEdit(groupBox_5);
        lineEditMedecinAdr2->setObjectName(QString::fromUtf8("lineEditMedecinAdr2"));
        lineEditMedecinAdr2->setGeometry(QRect(10, 160, 251, 20));
        lineEditMedecinAdr2->setMaxLength(50);
        lineEditMedecinAdr1 = new QLineEdit(groupBox_5);
        lineEditMedecinAdr1->setObjectName(QString::fromUtf8("lineEditMedecinAdr1"));
        lineEditMedecinAdr1->setGeometry(QRect(10, 130, 251, 20));
        lineEditMedecinAdr1->setMaxLength(50);
        lineEditMedecinCP = new QLineEdit(groupBox_5);
        lineEditMedecinCP->setObjectName(QString::fromUtf8("lineEditMedecinCP"));
        lineEditMedecinCP->setGeometry(QRect(10, 190, 71, 20));
        lineEditMedecinCP->setMaxLength(5);
        lineEditMedecinCP->setAlignment(Qt::AlignCenter);
        lineEditMedecinVille = new QLineEdit(groupBox_5);
        lineEditMedecinVille->setObjectName(QString::fromUtf8("lineEditMedecinVille"));
        lineEditMedecinVille->setGeometry(QRect(90, 190, 171, 20));
        lineEditMedecinVille->setMaxLength(50);
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 220, 81, 16));
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEditMedecinTel = new QLineEdit(groupBox_5);
        lineEditMedecinTel->setObjectName(QString::fromUtf8("lineEditMedecinTel"));
        lineEditMedecinTel->setGeometry(QRect(10, 240, 251, 20));
        lineEditMedecinTel->setMaxLength(50);
        tabWidgetMain->addTab(tab4, QString());
        tab5 = new QWidget();
        tab5->setObjectName(QString::fromUtf8("tab5"));
        groupBox_12 = new QGroupBox(tab5);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        groupBox_12->setGeometry(QRect(10, 10, 661, 91));
        label_11 = new QLabel(groupBox_12);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(30, 30, 111, 16));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_12 = new QLabel(groupBox_12);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(40, 60, 101, 16));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditParametresCPMedecin = new QLineEdit(groupBox_12);
        lineEditParametresCPMedecin->setObjectName(QString::fromUtf8("lineEditParametresCPMedecin"));
        lineEditParametresCPMedecin->setGeometry(QRect(160, 30, 101, 20));
        lineEditParametresCPMedecin->setMaxLength(5);
        lineEditParametreVilleMedecin = new QLineEdit(groupBox_12);
        lineEditParametreVilleMedecin->setObjectName(QString::fromUtf8("lineEditParametreVilleMedecin"));
        lineEditParametreVilleMedecin->setGeometry(QRect(160, 60, 491, 20));
        lineEditParametreVilleMedecin->setMaxLength(50);
        groupBox_13 = new QGroupBox(tab5);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        groupBox_13->setGeometry(QRect(10, 110, 661, 111));
        layoutWidget1 = new QWidget(groupBox_13);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 30, 309, 74));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(layoutWidget1);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_13, 0, 0, 1, 1);

        spinBoxParametreDureeDSI = new QSpinBox(layoutWidget1);
        spinBoxParametreDureeDSI->setObjectName(QString::fromUtf8("spinBoxParametreDureeDSI"));
        spinBoxParametreDureeDSI->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(spinBoxParametreDureeDSI, 0, 1, 1, 1);

        label_24 = new QLabel(layoutWidget1);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_2->addWidget(label_24, 0, 2, 1, 1);

        label_22 = new QLabel(layoutWidget1);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_22, 1, 0, 1, 1);

        spinBoxPrescriptionDureeOdronnance = new QSpinBox(layoutWidget1);
        spinBoxPrescriptionDureeOdronnance->setObjectName(QString::fromUtf8("spinBoxPrescriptionDureeOdronnance"));
        spinBoxPrescriptionDureeOdronnance->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(spinBoxPrescriptionDureeOdronnance, 1, 1, 1, 1);

        label_23 = new QLabel(layoutWidget1);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_2->addWidget(label_23, 1, 2, 1, 1);

        groupBox_14 = new QGroupBox(tab5);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        groupBox_14->setGeometry(QRect(10, 320, 661, 80));
        layoutWidget2 = new QWidget(groupBox_14);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(90, 30, 254, 35));
        gridLayout_4 = new QGridLayout(layoutWidget2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButtonPrescriptionEnregistrer = new QPushButton(layoutWidget2);
        pushButtonPrescriptionEnregistrer->setObjectName(QString::fromUtf8("pushButtonPrescriptionEnregistrer"));

        gridLayout_4->addWidget(pushButtonPrescriptionEnregistrer, 0, 0, 1, 1);

        pushButtonReinitialiser = new QPushButton(layoutWidget2);
        pushButtonReinitialiser->setObjectName(QString::fromUtf8("pushButtonReinitialiser"));

        gridLayout_4->addWidget(pushButtonReinitialiser, 0, 1, 1, 1);

        groupBox_15 = new QGroupBox(tab5);
        groupBox_15->setObjectName(QString::fromUtf8("groupBox_15"));
        groupBox_15->setGeometry(QRect(10, 240, 661, 80));
        layoutWidget3 = new QWidget(groupBox_15);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(20, 30, 469, 35));
        gridLayout_5 = new QGridLayout(layoutWidget3);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        spinBoxParametreARenouvelerTemps = new QSpinBox(layoutWidget3);
        spinBoxParametreARenouvelerTemps->setObjectName(QString::fromUtf8("spinBoxParametreARenouvelerTemps"));

        gridLayout_5->addWidget(spinBoxParametreARenouvelerTemps, 0, 1, 1, 1);

        label_25 = new QLabel(layoutWidget3);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_5->addWidget(label_25, 0, 2, 1, 1);

        label_26 = new QLabel(layoutWidget3);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_5->addWidget(label_26, 0, 0, 1, 1);

        tabWidgetMain->addTab(tab5, QString());

        gridLayout->addWidget(tabWidgetMain, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 700, 29));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidgetMain->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Prescription", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tabWidgetMain->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        groupBoxDetail->setTitle(QApplication::translate("MainWindow", "D\303\251tails", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Patient :", 0, QApplication::UnicodeUTF8));
        labelARenouvelerPatient->setText(QString());
        labelARenouvelerPresDateFin->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Prescription :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Valable jusqu'au", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Type de prescription :", 0, QApplication::UnicodeUTF8));
        labelARenouvelerPresType->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Mode renouvellement :", 0, QApplication::UnicodeUTF8));
        labelARenouvelerPresModeR->setText(QString());
        labelARenouvelerPresDuree->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "Dur\303\251e de la prescription :", 0, QApplication::UnicodeUTF8));
        labelARenouvelerMedNumNom->setText(QString());
        labelARenouvelerMedAd2->setText(QString());
        label_20->setText(QApplication::translate("MainWindow", "M\303\251decin :", 0, QApplication::UnicodeUTF8));
        labelARenouvelerMedAd1->setText(QString());
        labelARenouvelerMedCPVille->setText(QString());
        labelARenouvelerMedTel->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "A renouveler rapidement", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Action", 0, QApplication::UnicodeUTF8));
        pushButtonARenouvelerRenouveler->setText(QApplication::translate("MainWindow", "Renouveler", 0, QApplication::UnicodeUTF8));
        dateEditARenouvelerPresDateFin->setDisplayFormat(QApplication::translate("MainWindow", "dd/MM/yyyy", 0, QApplication::UnicodeUTF8));
        tabWidgetMain->setTabText(tabWidgetMain->indexOf(tab1), QApplication::translate("MainWindow", "A renouveler", 0, QApplication::UnicodeUTF8));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "Prescriptions enregistr\303\251es", 0, QApplication::UnicodeUTF8));
        groupBox_10->setTitle(QApplication::translate("MainWindow", "Saisie", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "Patient * :", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "Date de d\303\251but :", 0, QApplication::UnicodeUTF8));
        dateEditPrescriptionDateDebut->setDisplayFormat(QApplication::translate("MainWindow", "dd/MM/yyyy", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "Dur\303\251e :", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "mois", 0, QApplication::UnicodeUTF8));
        radioButtonOrdonnance->setText(QApplication::translate("MainWindow", "Ordonnance", 0, QApplication::UnicodeUTF8));
        radioButtonDSI->setText(QApplication::translate("MainWindow", "DSI", 0, QApplication::UnicodeUTF8));
        radioButtonPatient->setText(QApplication::translate("MainWindow", "Patient", 0, QApplication::UnicodeUTF8));
        radioButtonMedecin->setText(QApplication::translate("MainWindow", "M\303\251decin", 0, QApplication::UnicodeUTF8));
        groupBox_11->setTitle(QApplication::translate("MainWindow", "Actions", 0, QApplication::UnicodeUTF8));
        pushButtonPrescriptionAjouter->setText(QApplication::translate("MainWindow", "Ajouter", 0, QApplication::UnicodeUTF8));
        pushButtonPrescriptionModifier->setText(QApplication::translate("MainWindow", "Modifier", 0, QApplication::UnicodeUTF8));
        pushButtonPrescriptionAbandonner->setText(QApplication::translate("MainWindow", "Abandonner", 0, QApplication::UnicodeUTF8));
        pushButtonPrescriptionSupprimer->setText(QApplication::translate("MainWindow", "Supprimer", 0, QApplication::UnicodeUTF8));
        tabWidgetMain->setTabText(tabWidgetMain->indexOf(tab2), QApplication::translate("MainWindow", "Prescriptions", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Actions", 0, QApplication::UnicodeUTF8));
        pushButtonPatientAjouter->setText(QApplication::translate("MainWindow", "Ajouter", 0, QApplication::UnicodeUTF8));
        pushButtonPatientModifier->setText(QApplication::translate("MainWindow", "Modifier", 0, QApplication::UnicodeUTF8));
        pushButtonPatientAbandonner->setText(QApplication::translate("MainWindow", "Abandonner", 0, QApplication::UnicodeUTF8));
        pushButtonPatientSupprimer->setText(QApplication::translate("MainWindow", "Supprimer", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Patients enregistr\303\251s", 0, QApplication::UnicodeUTF8));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Saisie", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "Nom * :", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "Num\303\251ro S\303\251curit\303\251 Sociale :", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "M\303\251decin traitant :", 0, QApplication::UnicodeUTF8));
        tabWidgetMain->setTabText(tabWidgetMain->indexOf(tab3), QApplication::translate("MainWindow", "Patients", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Actions", 0, QApplication::UnicodeUTF8));
        pushButtonMedecinAjouter->setText(QApplication::translate("MainWindow", "Ajouter", 0, QApplication::UnicodeUTF8));
        pushButtonMedecinModifier->setText(QApplication::translate("MainWindow", "Modifier", 0, QApplication::UnicodeUTF8));
        pushButtonMedecinAbandonner->setText(QApplication::translate("MainWindow", "Abandonner", 0, QApplication::UnicodeUTF8));
        pushButtonMedecinSupprimer->setText(QApplication::translate("MainWindow", "Supprimer", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Medecins enregistr\303\251s", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Saisie", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Nom * :", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Num\303\251ro CPAM * :", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Adresse :", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "T\303\251l\303\251phones :", 0, QApplication::UnicodeUTF8));
        tabWidgetMain->setTabText(tabWidgetMain->indexOf(tab4), QApplication::translate("MainWindow", "M\303\251decins", 0, QApplication::UnicodeUTF8));
        groupBox_12->setTitle(QApplication::translate("MainWindow", "M\303\251decin [valeurs par d\303\251faut]", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Code postal :", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Ville :", 0, QApplication::UnicodeUTF8));
        groupBox_13->setTitle(QApplication::translate("MainWindow", "Prescriptions  [valeurs par d\303\251faut]", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Dur\303\251e DSI :", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", "mois", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "Dur\303\251e ordonnance :", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindow", "mois", 0, QApplication::UnicodeUTF8));
        groupBox_14->setTitle(QApplication::translate("MainWindow", "Action", 0, QApplication::UnicodeUTF8));
        pushButtonPrescriptionEnregistrer->setText(QApplication::translate("MainWindow", "&Enregistrer", 0, QApplication::UnicodeUTF8));
        pushButtonReinitialiser->setText(QApplication::translate("MainWindow", "&R\303\251initialiser", 0, QApplication::UnicodeUTF8));
        groupBox_15->setTitle(QApplication::translate("MainWindow", "A renouveler [valeurs par d\303\251faut]", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MainWindow", "jours", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MainWindow", "Plus vieille prescription a renouveler ", 0, QApplication::UnicodeUTF8));
        tabWidgetMain->setTabText(tabWidgetMain->indexOf(tab5), QApplication::translate("MainWindow", "Param\303\250tres", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
