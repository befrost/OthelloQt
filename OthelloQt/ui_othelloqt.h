/********************************************************************************
** Form generated from reading UI file 'othelloqt.ui'
**
** Created: Tue 13. Mar 14:43:03 2012
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
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
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
    QWidget *centralwidget;
    QLabel *label;
    QComboBox *rangee;
    QComboBox *colonne;
    QGroupBox *pion;
    QRadioButton *blanc;
    QRadioButton *noir;
    QMenuBar *menubar;
    QMenu *menuOthello;
    QMenu *menuObservateurs;
    QMenu *menuA_propos;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *OthelloQtClass)
    {
        if (OthelloQtClass->objectName().isEmpty())
            OthelloQtClass->setObjectName(QString::fromUtf8("OthelloQtClass"));
        OthelloQtClass->resize(248, 368);
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
        actionExpert = new QAction(OthelloQtClass);
        actionExpert->setObjectName(QString::fromUtf8("actionExpert"));
        centralwidget = new QWidget(OthelloQtClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 40, 61, 16));
        rangee = new QComboBox(centralwidget);
        rangee->setObjectName(QString::fromUtf8("rangee"));
        rangee->setGeometry(QRect(20, 180, 69, 22));
        colonne = new QComboBox(centralwidget);
        colonne->setObjectName(QString::fromUtf8("colonne"));
        colonne->setGeometry(QRect(140, 180, 69, 22));
        pion = new QGroupBox(centralwidget);
        pion->setObjectName(QString::fromUtf8("pion"));
        pion->setGeometry(QRect(70, 80, 120, 80));
        blanc = new QRadioButton(pion);
        blanc->setObjectName(QString::fromUtf8("blanc"));
        blanc->setGeometry(QRect(20, 30, 82, 17));
        noir = new QRadioButton(pion);
        noir->setObjectName(QString::fromUtf8("noir"));
        noir->setGeometry(QRect(20, 60, 82, 17));
        OthelloQtClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(OthelloQtClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 248, 20));
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
        label->setText(QApplication::translate("OthelloQtClass", "Controleur", 0, QApplication::UnicodeUTF8));
        pion->setTitle(QApplication::translate("OthelloQtClass", "Pion", 0, QApplication::UnicodeUTF8));
        blanc->setText(QApplication::translate("OthelloQtClass", "BLANC", 0, QApplication::UnicodeUTF8));
        noir->setText(QApplication::translate("OthelloQtClass", "NOIR", 0, QApplication::UnicodeUTF8));
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
