#ifndef DIALOGUECONFIGURATION_H
#define DIALOGUECONFIGURATION_H

#include <QtGui/QDialog>
#include "ui_dialogueconfiguration.h"

class dialogueConfiguration : public QDialog
{
    Q_OBJECT

public:
    dialogueConfiguration(QWidget *parent = 0);
    ~dialogueConfiguration();

private:
    Ui::dialogueConfigurationClass ui;
};

#endif // DIALOGUECONFIGURATION_H
