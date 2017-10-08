/********************************************************************************
** Form generated from reading UI file 'authorinfos.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORINFOS_H
#define UI_AUTHORINFOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Dialog_About
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_version;

    void setupUi(QDialog *Dialog_About)
    {
        if (Dialog_About->objectName().isEmpty())
            Dialog_About->setObjectName(QStringLiteral("Dialog_About"));
        Dialog_About->resize(200, 120);
        Dialog_About->setMinimumSize(QSize(200, 120));
        Dialog_About->setMaximumSize(QSize(200, 120));
        Dialog_About->setCursor(QCursor(Qt::ArrowCursor));
        Dialog_About->setModal(true);
        label = new QLabel(Dialog_About);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 151, 21));
        label->setOpenExternalLinks(true);
        label->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        label_2 = new QLabel(Dialog_About);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 40, 41, 16));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2->setOpenExternalLinks(true);
        label_2->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        label_3 = new QLabel(Dialog_About);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 40, 141, 16));
        label_3->setOpenExternalLinks(true);
        label_3->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        label_4 = new QLabel(Dialog_About);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 80, 51, 20));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4->setOpenExternalLinks(true);
        label_4->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        label_version = new QLabel(Dialog_About);
        label_version->setObjectName(QStringLiteral("label_version"));
        label_version->setGeometry(QRect(70, 80, 31, 20));
        label_version->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_version->setOpenExternalLinks(true);
        label_version->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        retranslateUi(Dialog_About);

        QMetaObject::connectSlotsByName(Dialog_About);
    } // setupUi

    void retranslateUi(QDialog *Dialog_About)
    {
        Dialog_About->setWindowTitle(QApplication::translate("Dialog_About", "About...", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog_About", "Author :   Cl\303\251ment ABADIE", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog_About", "e-Mail :", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dialog_About", "cle.abadie@gmail.com", Q_NULLPTR));
        label_4->setText(QApplication::translate("Dialog_About", "Version :", Q_NULLPTR));
        label_version->setText(QApplication::translate("Dialog_About", "0.0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog_About: public Ui_Dialog_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORINFOS_H
