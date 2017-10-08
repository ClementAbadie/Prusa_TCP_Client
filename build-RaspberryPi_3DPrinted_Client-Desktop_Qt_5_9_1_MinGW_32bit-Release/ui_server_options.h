/********************************************************************************
** Form generated from reading UI file 'server_options.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_OPTIONS_H
#define UI_SERVER_OPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Server_Options
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_timeout;
    QSpinBox *spinBox_timeout_unsaved_time;

    void setupUi(QDialog *Dialog_Server_Options)
    {
        if (Dialog_Server_Options->objectName().isEmpty())
            Dialog_Server_Options->setObjectName(QStringLiteral("Dialog_Server_Options"));
        Dialog_Server_Options->setWindowModality(Qt::WindowModal);
        Dialog_Server_Options->resize(273, 106);
        Dialog_Server_Options->setModal(true);
        buttonBox = new QDialogButtonBox(Dialog_Server_Options);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(20, 70, 241, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        label_timeout = new QLabel(Dialog_Server_Options);
        label_timeout->setObjectName(QStringLiteral("label_timeout"));
        label_timeout->setGeometry(QRect(50, 30, 131, 21));
        label_timeout->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_timeout_unsaved_time = new QSpinBox(Dialog_Server_Options);
        spinBox_timeout_unsaved_time->setObjectName(QStringLiteral("spinBox_timeout_unsaved_time"));
        spinBox_timeout_unsaved_time->setGeometry(QRect(190, 30, 71, 22));
        spinBox_timeout_unsaved_time->setMinimum(500);
        spinBox_timeout_unsaved_time->setMaximum(10000);
        spinBox_timeout_unsaved_time->setSingleStep(1000);
        spinBox_timeout_unsaved_time->setValue(1000);

        retranslateUi(Dialog_Server_Options);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_Server_Options, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_Server_Options, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_Server_Options);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Server_Options)
    {
        Dialog_Server_Options->setWindowTitle(QApplication::translate("Dialog_Server_Options", "Options", Q_NULLPTR));
        label_timeout->setText(QApplication::translate("Dialog_Server_Options", "Connection timeout (ms) :", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Server_Options: public Ui_Dialog_Server_Options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_OPTIONS_H
