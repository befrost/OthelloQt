/********************************************************************************
** Form generated from reading UI file 'dialogueconfiguration.ui'
**
** Created: Fri 9. Mar 18:57:56 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGUECONFIGURATION_H
#define UI_DIALOGUECONFIGURATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialogueConfigurationClass
{
public:
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *ok;
    QPushButton *cancel;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QSpinBox *nbRan;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QSpinBox *nbCol;

    void setupUi(QDialog *dialogueConfigurationClass)
    {
        if (dialogueConfigurationClass->objectName().isEmpty())
            dialogueConfigurationClass->setObjectName(QString::fromUtf8("dialogueConfigurationClass"));
        dialogueConfigurationClass->resize(267, 236);
        horizontalLayoutWidget_2 = new QWidget(dialogueConfigurationClass);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 160, 241, 51));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        ok = new QPushButton(horizontalLayoutWidget_2);
        ok->setObjectName(QString::fromUtf8("ok"));

        horizontalLayout_2->addWidget(ok);

        cancel = new QPushButton(horizontalLayoutWidget_2);
        cancel->setObjectName(QString::fromUtf8("cancel"));

        horizontalLayout_2->addWidget(cancel);

        verticalLayoutWidget_3 = new QWidget(dialogueConfigurationClass);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 30, 241, 121));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget_3);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(verticalLayoutWidget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(14);
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        nbRan = new QSpinBox(verticalLayoutWidget_3);
        nbRan->setObjectName(QString::fromUtf8("nbRan"));

        verticalLayout->addWidget(nbRan);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(verticalLayoutWidget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout_2->addWidget(label_3);

        nbCol = new QSpinBox(verticalLayoutWidget_3);
        nbCol->setObjectName(QString::fromUtf8("nbCol"));

        verticalLayout_2->addWidget(nbCol);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(dialogueConfigurationClass);

        QMetaObject::connectSlotsByName(dialogueConfigurationClass);
    } // setupUi

    void retranslateUi(QDialog *dialogueConfigurationClass)
    {
        dialogueConfigurationClass->setWindowTitle(QApplication::translate("dialogueConfigurationClass", "Configurer", 0, QApplication::UnicodeUTF8));
        ok->setText(QApplication::translate("dialogueConfigurationClass", "ok", 0, QApplication::UnicodeUTF8));
        cancel->setText(QApplication::translate("dialogueConfigurationClass", "cancel", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dialogueConfigurationClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">Taille de l'othellier</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dialogueConfigurationClass", "Rang\303\251es", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("dialogueConfigurationClass", "Colonnes", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dialogueConfigurationClass: public Ui_dialogueConfigurationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGUECONFIGURATION_H
