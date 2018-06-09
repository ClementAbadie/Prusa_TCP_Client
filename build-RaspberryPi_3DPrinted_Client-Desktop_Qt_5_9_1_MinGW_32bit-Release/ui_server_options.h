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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
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
    QSpinBox *spinBox_Video_framerate;
    QLabel *server_label_4;
    QRadioButton *radioButton_webcam_android;
    QRadioButton *radioButton_webcam_pi;
    QComboBox *comboBox_Server_Port;
    QComboBox *comboBox_Server_IP_Distant;
    QLabel *Server_IP_PORT_separator;
    QComboBox *comboBox_Server_IP_Local;
    QLabel *label_timeout_3;
    QLabel *label_timeout_4;
    QLineEdit *lineEdit_repetier_path;
    QLabel *label_repetier_path;
    QLabel *label_CAO;
    QLineEdit *lineEdit_CAO_path;
    QLabel *label_project;
    QLineEdit *lineEdit_project_path;
    QComboBox *comboBox_Webcam_IP;

    void setupUi(QDialog *Dialog_Server_Options)
    {
        if (Dialog_Server_Options->objectName().isEmpty())
            Dialog_Server_Options->setObjectName(QStringLiteral("Dialog_Server_Options"));
        Dialog_Server_Options->setWindowModality(Qt::WindowModal);
        Dialog_Server_Options->resize(379, 359);
        Dialog_Server_Options->setModal(true);
        buttonBox = new QDialogButtonBox(Dialog_Server_Options);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 320, 361, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        label_timeout = new QLabel(Dialog_Server_Options);
        label_timeout->setObjectName(QStringLiteral("label_timeout"));
        label_timeout->setGeometry(QRect(50, 80, 131, 21));
        label_timeout->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_timeout_unsaved_time = new QSpinBox(Dialog_Server_Options);
        spinBox_timeout_unsaved_time->setObjectName(QStringLiteral("spinBox_timeout_unsaved_time"));
        spinBox_timeout_unsaved_time->setGeometry(QRect(190, 80, 71, 22));
        spinBox_timeout_unsaved_time->setMinimum(500);
        spinBox_timeout_unsaved_time->setMaximum(10000);
        spinBox_timeout_unsaved_time->setSingleStep(1000);
        spinBox_timeout_unsaved_time->setValue(1000);
        spinBox_Video_res_h = new QSpinBox(Dialog_Server_Options);
        spinBox_Video_res_h->setObjectName(QStringLiteral("spinBox_Video_res_h"));
        spinBox_Video_res_h->setEnabled(true);
        spinBox_Video_res_h->setGeometry(QRect(160, 150, 51, 21));
        spinBox_Video_res_h->setMinimum(480);
        spinBox_Video_res_h->setMaximum(1920);
        spinBox_Video_res_h->setValue(1280);
        server_label_3 = new QLabel(Dialog_Server_Options);
        server_label_3->setObjectName(QStringLiteral("server_label_3"));
        server_label_3->setGeometry(QRect(210, 150, 21, 21));
        server_label_3->setAlignment(Qt::AlignCenter);
        server_label_3->setTextInteractionFlags(Qt::NoTextInteraction);
        spinBox_Video_res_v = new QSpinBox(Dialog_Server_Options);
        spinBox_Video_res_v->setObjectName(QStringLiteral("spinBox_Video_res_v"));
        spinBox_Video_res_v->setEnabled(true);
        spinBox_Video_res_v->setGeometry(QRect(230, 150, 51, 21));
        spinBox_Video_res_v->setMinimum(320);
        spinBox_Video_res_v->setMaximum(1080);
        spinBox_Video_res_v->setValue(720);
        label_timeout_2 = new QLabel(Dialog_Server_Options);
        label_timeout_2->setObjectName(QStringLiteral("label_timeout_2"));
        label_timeout_2->setGeometry(QRect(10, 120, 61, 16));
        label_timeout_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_Video_framerate = new QSpinBox(Dialog_Server_Options);
        spinBox_Video_framerate->setObjectName(QStringLiteral("spinBox_Video_framerate"));
        spinBox_Video_framerate->setEnabled(true);
        spinBox_Video_framerate->setGeometry(QRect(300, 150, 41, 21));
        spinBox_Video_framerate->setMinimum(2);
        spinBox_Video_framerate->setMaximum(90);
        spinBox_Video_framerate->setValue(20);
        server_label_4 = new QLabel(Dialog_Server_Options);
        server_label_4->setObjectName(QStringLiteral("server_label_4"));
        server_label_4->setGeometry(QRect(280, 150, 21, 21));
        server_label_4->setAlignment(Qt::AlignCenter);
        server_label_4->setTextInteractionFlags(Qt::NoTextInteraction);
        radioButton_webcam_android = new QRadioButton(Dialog_Server_Options);
        radioButton_webcam_android->setObjectName(QStringLiteral("radioButton_webcam_android"));
        radioButton_webcam_android->setGeometry(QRect(80, 120, 141, 19));
        radioButton_webcam_android->setChecked(true);
        radioButton_webcam_pi = new QRadioButton(Dialog_Server_Options);
        radioButton_webcam_pi->setObjectName(QStringLiteral("radioButton_webcam_pi"));
        radioButton_webcam_pi->setGeometry(QRect(80, 150, 71, 21));
        comboBox_Server_Port = new QComboBox(Dialog_Server_Options);
        comboBox_Server_Port->setObjectName(QStringLiteral("comboBox_Server_Port"));
        comboBox_Server_Port->setGeometry(QRect(300, 11, 61, 51));
        comboBox_Server_Port->setEditable(true);
        comboBox_Server_IP_Distant = new QComboBox(Dialog_Server_Options);
        comboBox_Server_IP_Distant->setObjectName(QStringLiteral("comboBox_Server_IP_Distant"));
        comboBox_Server_IP_Distant->setGeometry(QRect(160, 10, 131, 22));
        comboBox_Server_IP_Distant->setEditable(true);
        Server_IP_PORT_separator = new QLabel(Dialog_Server_Options);
        Server_IP_PORT_separator->setObjectName(QStringLiteral("Server_IP_PORT_separator"));
        Server_IP_PORT_separator->setGeometry(QRect(290, 10, 16, 51));
        comboBox_Server_IP_Local = new QComboBox(Dialog_Server_Options);
        comboBox_Server_IP_Local->setObjectName(QStringLiteral("comboBox_Server_IP_Local"));
        comboBox_Server_IP_Local->setGeometry(QRect(160, 40, 131, 22));
        comboBox_Server_IP_Local->setEditable(true);
        label_timeout_3 = new QLabel(Dialog_Server_Options);
        label_timeout_3->setObjectName(QStringLiteral("label_timeout_3"));
        label_timeout_3->setGeometry(QRect(20, 10, 131, 20));
        label_timeout_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_timeout_4 = new QLabel(Dialog_Server_Options);
        label_timeout_4->setObjectName(QStringLiteral("label_timeout_4"));
        label_timeout_4->setGeometry(QRect(20, 40, 131, 20));
        label_timeout_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_repetier_path = new QLineEdit(Dialog_Server_Options);
        lineEdit_repetier_path->setObjectName(QStringLiteral("lineEdit_repetier_path"));
        lineEdit_repetier_path->setGeometry(QRect(120, 190, 241, 21));
        label_repetier_path = new QLabel(Dialog_Server_Options);
        label_repetier_path->setObjectName(QStringLiteral("label_repetier_path"));
        label_repetier_path->setGeometry(QRect(20, 190, 91, 20));
        label_repetier_path->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_CAO = new QLabel(Dialog_Server_Options);
        label_CAO->setObjectName(QStringLiteral("label_CAO"));
        label_CAO->setGeometry(QRect(20, 220, 91, 20));
        label_CAO->setToolTipDuration(-1);
        label_CAO->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_CAO_path = new QLineEdit(Dialog_Server_Options);
        lineEdit_CAO_path->setObjectName(QStringLiteral("lineEdit_CAO_path"));
        lineEdit_CAO_path->setGeometry(QRect(120, 220, 241, 21));
        lineEdit_CAO_path->setToolTipDuration(-1);
        label_project = new QLabel(Dialog_Server_Options);
        label_project->setObjectName(QStringLiteral("label_project"));
        label_project->setGeometry(QRect(20, 250, 91, 20));
        label_project->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_project_path = new QLineEdit(Dialog_Server_Options);
        lineEdit_project_path->setObjectName(QStringLiteral("lineEdit_project_path"));
        lineEdit_project_path->setGeometry(QRect(120, 250, 241, 21));
        comboBox_Webcam_IP = new QComboBox(Dialog_Server_Options);
        comboBox_Webcam_IP->setObjectName(QStringLiteral("comboBox_Webcam_IP"));
        comboBox_Webcam_IP->setGeometry(QRect(220, 120, 131, 22));
        comboBox_Webcam_IP->setEditable(true);

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
        server_label_4->setText(QApplication::translate("Dialog_Server_Options", "@", Q_NULLPTR));
        radioButton_webcam_android->setText(QApplication::translate("Dialog_Server_Options", "Android  (IP WebCam)", Q_NULLPTR));
        radioButton_webcam_pi->setText(QApplication::translate("Dialog_Server_Options", "Camera Pi", Q_NULLPTR));
        comboBox_Server_Port->setCurrentText(QApplication::translate("Dialog_Server_Options", "51717", Q_NULLPTR));
        comboBox_Server_IP_Distant->setCurrentText(QApplication::translate("Dialog_Server_Options", "your IP here", Q_NULLPTR));
        Server_IP_PORT_separator->setText(QApplication::translate("Dialog_Server_Options", " :", Q_NULLPTR));
        comboBox_Server_IP_Local->setCurrentText(QApplication::translate("Dialog_Server_Options", "your IP here", Q_NULLPTR));
        label_timeout_3->setText(QApplication::translate("Dialog_Server_Options", "Distant server :", Q_NULLPTR));
        label_timeout_4->setText(QApplication::translate("Dialog_Server_Options", "Local server :", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        lineEdit_repetier_path->setToolTip(QApplication::translate("Dialog_Server_Options", "Folder path only (Copy-Paste from Windows Explorer)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        lineEdit_repetier_path->setText(QApplication::translate("Dialog_Server_Options", "C:\\Program Files\\Repetier-Host", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_repetier_path->setToolTip(QApplication::translate("Dialog_Server_Options", "Folder path only (Copy-Paste from Windows Explorer)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_repetier_path->setText(QApplication::translate("Dialog_Server_Options", "Repetier path :", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_CAO->setToolTip(QApplication::translate("Dialog_Server_Options", "Full path (with .exe)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_CAO->setText(QApplication::translate("Dialog_Server_Options", "CAO path :", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        lineEdit_CAO_path->setToolTip(QApplication::translate("Dialog_Server_Options", "Full path (with .exe)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label_project->setToolTip(QApplication::translate("Dialog_Server_Options", "Folder path (Copy-Paste from Windows Explorer)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_project->setText(QApplication::translate("Dialog_Server_Options", "Project path :", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        lineEdit_project_path->setToolTip(QApplication::translate("Dialog_Server_Options", "Folder path (Copy-Paste from Windows Explorer)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        comboBox_Webcam_IP->setCurrentText(QApplication::translate("Dialog_Server_Options", "your IP here", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Server_Options: public Ui_Dialog_Server_Options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_OPTIONS_H
