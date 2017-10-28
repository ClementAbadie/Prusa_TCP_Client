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
    QSpinBox *spinBox_Video_res_h;
    QLabel *server_label_3;
    QSpinBox *spinBox_Video_res_v;
    QLabel *label_timeout_2;

    void setupUi(QDialog *Dialog_Server_Options)
    {
        if (Dialog_Server_Options->objectName().isEmpty())
            Dialog_Server_Options->setObjectName(QStringLiteral("Dialog_Server_Options"));
        Dialog_Server_Options->setWindowModality(Qt::WindowModal);
        Dialog_Server_Options->resize(274, 135);
        Dialog_Server_Options->setModal(true);
        buttonBox = new QDialogButtonBox(Dialog_Server_Options);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(20, 90, 241, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        label_timeout = new QLabel(Dialog_Server_Options);
        label_timeout->setObjectName(QStringLiteral("label_timeout"));
        label_timeout->setGeometry(QRect(50, 20, 131, 21));
        label_timeout->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_timeout_unsaved_time = new QSpinBox(Dialog_Server_Options);
        spinBox_timeout_unsaved_time->setObjectName(QStringLiteral("spinBox_timeout_unsaved_time"));
        spinBox_timeout_unsaved_time->setGeometry(QRect(190, 20, 71, 22));
        spinBox_timeout_unsaved_time->setMinimum(500);
        spinBox_timeout_unsaved_time->setMaximum(10000);
        spinBox_timeout_unsaved_time->setSingleStep(1000);
        spinBox_timeout_unsaved_time->setValue(1000);
        spinBox_Video_res_h = new QSpinBox(Dialog_Server_Options);
        spinBox_Video_res_h->setObjectName(QStringLiteral("spinBox_Video_res_h"));
        spinBox_Video_res_h->setGeometry(QRect(90, 60, 71, 21));
        spinBox_Video_res_h->setMinimum(480);
        spinBox_Video_res_h->setMaximum(1920);
        spinBox_Video_res_h->setValue(800);
        server_label_3 = new QLabel(Dialog_Server_Options);
        server_label_3->setObjectName(QStringLiteral("server_label_3"));
        server_label_3->setGeometry(QRect(160, 60, 31, 21));
        server_label_3->setAlignment(Qt::AlignCenter);
        server_label_3->setTextInteractionFlags(Qt::NoTextInteraction);
        spinBox_Video_res_v = new QSpinBox(Dialog_Server_Options);
        spinBox_Video_res_v->setObjectName(QStringLiteral("spinBox_Video_res_v"));
        spinBox_Video_res_v->setGeometry(QRect(190, 60, 71, 21));
        spinBox_Video_res_v->setMinimum(320);
        spinBox_Video_res_v->setMaximum(1080);
        spinBox_Video_res_v->setValue(600);
        label_timeout_2 = new QLabel(Dialog_Server_Options);
        label_timeout_2->setObjectName(QStringLiteral("label_timeout_2"));
        label_timeout_2->setGeometry(QRect(10, 60, 71, 21));
        label_timeout_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(Dialog_Server_Options);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_Server_Options, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_Server_Options, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_Server_Options);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Server_Options)
    {
        Dialog_Server_Options->setWindowTitle(QApplication::translate("Dialog_Server_Options", "Options", Q_NULLPTR));
        label_timeout->setText(QApplication::translate("Dialog_Server_Options", "Connection timeout (ms) :", Q_NULLPTR));
        server_label_3->setText(QApplication::translate("Dialog_Server_Options", "x", Q_NULLPTR));
        label_timeout_2->setText(QApplication::translate("Dialog_Server_Options", "WebCam :", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Server_Options: public Ui_Dialog_Server_Options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_OPTIONS_H
