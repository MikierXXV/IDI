/********************************************************************************
** Form generated from reading UI file 'Exercici1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXERCICI1_H
#define UI_EXERCICI1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Exercici1
{
public:
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *hours;
    QLabel *minutes;
    QHBoxLayout *horizontalLayout_3;
    QLCDNumber *hnum;
    QLCDNumber *mnum;
    QHBoxLayout *horizontalLayout_4;
    QDial *hdial;
    QDial *mdial;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *exit;

    void setupUi(QWidget *Exercici1)
    {
        if (Exercici1->objectName().isEmpty())
            Exercici1->setObjectName(QString::fromUtf8("Exercici1"));
        Exercici1->resize(382, 308);
        Exercici1->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_5 = new QHBoxLayout(Exercici1);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        hours = new QLabel(Exercici1);
        hours->setObjectName(QString::fromUtf8("hours"));

        horizontalLayout_2->addWidget(hours);

        minutes = new QLabel(Exercici1);
        minutes->setObjectName(QString::fromUtf8("minutes"));

        horizontalLayout_2->addWidget(minutes);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        hnum = new QLCDNumber(Exercici1);
        hnum->setObjectName(QString::fromUtf8("hnum"));
        hnum->setSmallDecimalPoint(false);
        hnum->setDigitCount(2);

        horizontalLayout_3->addWidget(hnum);

        mnum = new QLCDNumber(Exercici1);
        mnum->setObjectName(QString::fromUtf8("mnum"));

        horizontalLayout_3->addWidget(mnum);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        hdial = new QDial(Exercici1);
        hdial->setObjectName(QString::fromUtf8("hdial"));
        hdial->setMaximum(23);

        horizontalLayout_4->addWidget(hdial);

        mdial = new QDial(Exercici1);
        mdial->setObjectName(QString::fromUtf8("mdial"));
        mdial->setMaximum(59);

        horizontalLayout_4->addWidget(mdial);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        exit = new QPushButton(Exercici1);
        exit->setObjectName(QString::fromUtf8("exit"));

        horizontalLayout->addWidget(exit);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_5->addLayout(verticalLayout);


        retranslateUi(Exercici1);
        QObject::connect(exit, SIGNAL(clicked()), Exercici1, SLOT(close()));
        QObject::connect(hdial, SIGNAL(valueChanged(int)), hnum, SLOT(display(int)));
        QObject::connect(mdial, SIGNAL(valueChanged(int)), mnum, SLOT(display(int)));

        QMetaObject::connectSlotsByName(Exercici1);
    } // setupUi

    void retranslateUi(QWidget *Exercici1)
    {
        Exercici1->setWindowTitle(QApplication::translate("Exercici1", "Form", nullptr));
        hours->setText(QApplication::translate("Exercici1", "Hours", nullptr));
        minutes->setText(QApplication::translate("Exercici1", "Minutes", nullptr));
        exit->setText(QApplication::translate("Exercici1", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Exercici1: public Ui_Exercici1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXERCICI1_H
