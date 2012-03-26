/********************************************************************************
** Form generated from reading UI file 'othelloqt.ui'
**
** Created: Mon 26. Mar 01:50:26 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OTHELLOQT_H
#define UI_OTHELLOQT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OthelloQtClass
{
public:
    QAction *actionOthello;
    QAction *actionAuteur;
    QAction *actionNouveau;
    QAction *actionFermer;
    QAction *actionQuitter;
    QAction *actionTexte;
    QAction *actionExpert;
    QAction *actionSauver;
    QAction *actionCharger;
    QWidget *centralwidget;
    QFrame *frame;
    QGroupBox *pion;
    QRadioButton *blanc;
    QRadioButton *noir;
    QLabel *label;
    QPushButton *placer;
    QComboBox *colonne;
    QComboBox *rangee;
    QMenuBar *menubar;
    QMenu *menuOthello;
    QMenu *menuObservateurs;
    QMenu *menuA_propos;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *OthelloQtClass)
    {
        if (OthelloQtClass->objectName().isEmpty())
            OthelloQtClass->setObjectName(QString::fromUtf8("OthelloQtClass"));
        OthelloQtClass->resize(250, 360);
        OthelloQtClass->setMinimumSize(QSize(250, 360));
        OthelloQtClass->setMaximumSize(QSize(250, 360));
        actionOthello = new QAction(OthelloQtClass);
        actionOthello->setObjectName(QString::fromUtf8("actionOthello"));
        actionAuteur = new QAction(OthelloQtClass);
        actionAuteur->setObjectName(QString::fromUtf8("actionAuteur"));
        actionNouveau = new QAction(OthelloQtClass);
        actionNouveau->setObjectName(QString::fromUtf8("actionNouveau"));
        actionFermer = new QAction(OthelloQtClass);
        actionFermer->setObjectName(QString::fromUtf8("actionFermer"));
        actionFermer->setEnabled(false);
        actionQuitter = new QAction(OthelloQtClass);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionTexte = new QAction(OthelloQtClass);
        actionTexte->setObjectName(QString::fromUtf8("actionTexte"));
        actionTexte->setCheckable(true);
        actionExpert = new QAction(OthelloQtClass);
        actionExpert->setObjectName(QString::fromUtf8("actionExpert"));
        actionSauver = new QAction(OthelloQtClass);
        actionSauver->setObjectName(QString::fromUtf8("actionSauver"));
        actionCharger = new QAction(OthelloQtClass);
        actionCharger->setObjectName(QString::fromUtf8("actionCharger"));
        centralwidget = new QWidget(OthelloQtClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setEnabled(false);
        frame->setGeometry(QRect(30, 40, 190, 245));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(4);
        frame->setMidLineWidth(0);
        pion = new QGroupBox(frame);
        pion->setObjectName(QString::fromUtf8("pion"));
        pion->setGeometry(QRect(20, 40, 120, 80));
        blanc = new QRadioButton(pion);
        blanc->setObjectName(QString::fromUtf8("blanc"));
        blanc->setGeometry(QRect(20, 30, 82, 17));
        blanc->setChecked(false);
        noir = new QRadioButton(pion);
        noir->setObjectName(QString::fromUtf8("noir"));
        noir->setGeometry(QRect(20, 60, 82, 17));
        noir->setChecked(true);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 10, 61, 16));
        placer = new QPushButton(frame);
        placer->setObjectName(QString::fromUtf8("placer"));
        placer->setGeometry(QRect(50, 190, 75, 23));
        colonne = new QComboBox(frame);
        colonne->setObjectName(QString::fromUtf8("colonne"));
        colonne->setGeometry(QRect(20, 140, 69, 22));
        rangee = new QComboBox(frame);
        rangee->setObjectName(QString::fromUtf8("rangee"));
        rangee->setGeometry(QRect(100, 140, 69, 22));
        OthelloQtClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(OthelloQtClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 250, 22));
        menuOthello = new QMenu(menubar);
        menuOthello->setObjectName(QString::fromUtf8("menuOthello"));
        menuObservateurs = new QMenu(menubar);
        menuObservateurs->setObjectName(QString::fromUtf8("menuObservateurs"));
        menuObservateurs->setEnabled(false);
        menuA_propos = new QMenu(menubar);
        menuA_propos->setObjectName(QString::fromUtf8("menuA_propos"));
        OthelloQtClass->setMenuBar(menubar);
        statusbar = new QStatusBar(OthelloQtClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        OthelloQtClass->setStatusBar(statusbar);

        menubar->addAction(menuOthello->menuAction());
        menubar->addAction(menuObservateurs->menuAction());
        menubar->addAction(menuA_propos->menuAction());
        menuOthello->addAction(actionNouveau);
        menuOthello->addAction(actionCharger);
        menuOthello->addAction(actionSauver);
        menuOthello->addAction(actionFermer);
        menuOthello->addAction(actionQuitter);
        menuObservateurs->addAction(actionTexte);
        menuObservateurs->addAction(actionExpert);
        menuA_propos->addAction(actionOthello);
        menuA_propos->addAction(actionAuteur);

        retranslateUi(OthelloQtClass);

        QMetaObject::connectSlotsByName(OthelloQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *OthelloQtClass)
    {
        OthelloQtClass->setWindowTitle(QApplication::translate("OthelloQtClass", "Jouer \303\240 Othello", 0, QApplication::UnicodeUTF8));
        actionOthello->setText(QApplication::translate("OthelloQtClass", "Othello", 0, QApplication::UnicodeUTF8));
        actionAuteur->setText(QApplication::translate("OthelloQtClass", "Auteur", 0, QApplication::UnicodeUTF8));
        actionNouveau->setText(QApplication::translate("OthelloQtClass", "Nouveau", 0, QApplication::UnicodeUTF8));
        actionFermer->setText(QApplication::translate("OthelloQtClass", "Fermer", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("OthelloQtClass", "Quitter", 0, QApplication::UnicodeUTF8));
        actionTexte->setText(QApplication::translate("OthelloQtClass", "Texte", 0, QApplication::UnicodeUTF8));
        actionExpert->setText(QApplication::translate("OthelloQtClass", "Expert", 0, QApplication::UnicodeUTF8));
        actionSauver->setText(QApplication::translate("OthelloQtClass", "Sauver", 0, QApplication::UnicodeUTF8));
        actionCharger->setText(QApplication::translate("OthelloQtClass", "Charger", 0, QApplication::UnicodeUTF8));
        pion->setTitle(QApplication::translate("OthelloQtClass", "Pion", 0, QApplication::UnicodeUTF8));
        blanc->setText(QApplication::translate("OthelloQtClass", "BLANC", 0, QApplication::UnicodeUTF8));
        noir->setText(QApplication::translate("OthelloQtClass", "NOIR", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("OthelloQtClass", "Controleur", 0, QApplication::UnicodeUTF8));
        placer->setText(QApplication::translate("OthelloQtClass", "Placer", 0, QApplication::UnicodeUTF8));
        menuOthello->setTitle(QApplication::translate("OthelloQtClass", "Othello", 0, QApplication::UnicodeUTF8));
        menuObservateurs->setTitle(QApplication::translate("OthelloQtClass", "Observateurs", 0, QApplication::UnicodeUTF8));
        menuA_propos->setTitle(QApplication::translate("OthelloQtClass", "A propos", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OthelloQtClass: public Ui_OthelloQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OTHELLOQT_H
