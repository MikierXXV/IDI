/********************************************************************************
** Form generated from reading UI file 'Galton.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GALTON_H
#define UI_GALTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "MyLCDNumber.h"
#include "MyLabel.h"

QT_BEGIN_NAMESPACE

class Ui_Galton
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    MyLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_11;
    MyLabel *label_2;
    QSpacerItem *horizontalSpacer_13;
    MyLabel *label_3;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    MyLabel *label_4;
    QSpacerItem *horizontalSpacer_3;
    MyLabel *label_6;
    QSpacerItem *horizontalSpacer_4;
    MyLabel *label_7;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_6;
    MyLabel *label_8;
    QSpacerItem *horizontalSpacer_8;
    MyLabel *label_11;
    QSpacerItem *horizontalSpacer_9;
    MyLabel *label_15;
    QSpacerItem *horizontalSpacer_10;
    MyLabel *label_14;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_5;
    MyLCDNumber *lcdNumber;
    MyLCDNumber *lcdNumber_2;
    MyLCDNumber *lcdNumber_3;
    MyLCDNumber *lcdNumber_4;
    MyLCDNumber *lcdNumber_6;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_16;
    QSpacerItem *verticalSpacer_3;
    MyLCDNumber *lcdNumber_9;

    void setupUi(QWidget *Galton)
    {
        if (Galton->objectName().isEmpty())
            Galton->setObjectName(QString::fromUtf8("Galton"));
        Galton->resize(800, 621);
        gridLayout = new QGridLayout(Galton);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton = new QPushButton(Galton);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);

        label = new MyLabel(Galton);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_11);

        label_2 = new MyLabel(Galton);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_2);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_13);

        label_3 = new MyLabel(Galton);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_3);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_12);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_4 = new MyLabel(Galton);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_6 = new MyLabel(Galton);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_6);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        label_7 = new MyLabel(Galton);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_7);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        label_8 = new MyLabel(Galton);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_8);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        label_11 = new MyLabel(Galton);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_11);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        label_15 = new MyLabel(Galton);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_15);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_10);

        label_14 = new MyLabel(Galton);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_14);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lcdNumber = new MyLCDNumber(Galton);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setLayoutDirection(Qt::LeftToRight);
        lcdNumber->setFrameShape(QFrame::Box);
        lcdNumber->setFrameShadow(QFrame::Raised);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber->setProperty("intValue", QVariant(0));

        horizontalLayout_5->addWidget(lcdNumber);

        lcdNumber_2 = new MyLCDNumber(Galton);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setLayoutDirection(Qt::LeftToRight);
        lcdNumber_2->setFrameShape(QFrame::Box);
        lcdNumber_2->setFrameShadow(QFrame::Raised);
        lcdNumber_2->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_5->addWidget(lcdNumber_2);

        lcdNumber_3 = new MyLCDNumber(Galton);
        lcdNumber_3->setObjectName(QString::fromUtf8("lcdNumber_3"));
        lcdNumber_3->setLayoutDirection(Qt::LeftToRight);
        lcdNumber_3->setFrameShape(QFrame::Box);
        lcdNumber_3->setFrameShadow(QFrame::Raised);
        lcdNumber_3->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_5->addWidget(lcdNumber_3);

        lcdNumber_4 = new MyLCDNumber(Galton);
        lcdNumber_4->setObjectName(QString::fromUtf8("lcdNumber_4"));
        lcdNumber_4->setLayoutDirection(Qt::LeftToRight);
        lcdNumber_4->setFrameShape(QFrame::Box);
        lcdNumber_4->setFrameShadow(QFrame::Raised);
        lcdNumber_4->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_5->addWidget(lcdNumber_4);

        lcdNumber_6 = new MyLCDNumber(Galton);
        lcdNumber_6->setObjectName(QString::fromUtf8("lcdNumber_6"));
        lcdNumber_6->setLayoutDirection(Qt::LeftToRight);
        lcdNumber_6->setFrameShape(QFrame::Box);
        lcdNumber_6->setFrameShadow(QFrame::Raised);
        lcdNumber_6->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_5->addWidget(lcdNumber_6);


        verticalLayout_2->addLayout(horizontalLayout_5);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pushButton_2 = new QPushButton(Galton);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_3->addWidget(pushButton_2);

        verticalSpacer = new QSpacerItem(20, 340, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_2);

        label_16 = new QLabel(Galton);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMaximumSize(QSize(600, 600));
        label_16->setBaseSize(QSize(0, 0));
        label_16->setStyleSheet(QString::fromUtf8(""));
        label_16->setTextFormat(Qt::AutoText);
        label_16->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_16);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        lcdNumber_9 = new MyLCDNumber(Galton);
        lcdNumber_9->setObjectName(QString::fromUtf8("lcdNumber_9"));
        lcdNumber_9->setMaximumSize(QSize(800, 800));
        QFont font;
        font.setPointSize(16);
        font.setBold(false);
        font.setWeight(50);
        lcdNumber_9->setFont(font);
        lcdNumber_9->setLayoutDirection(Qt::LeftToRight);
        lcdNumber_9->setFrameShape(QFrame::Box);
        lcdNumber_9->setFrameShadow(QFrame::Raised);
        lcdNumber_9->setSegmentStyle(QLCDNumber::Flat);

        verticalLayout->addWidget(lcdNumber_9);


        verticalLayout_3->addLayout(verticalLayout);


        horizontalLayout_3->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        retranslateUi(Galton);
        QObject::connect(pushButton_2, SIGNAL(clicked()), lcdNumber, SLOT(reset()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), lcdNumber_2, SLOT(reset()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), lcdNumber_3, SLOT(reset()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), lcdNumber_4, SLOT(reset()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), lcdNumber_9, SLOT(reset()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), label, SLOT(reset()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), label_2, SLOT(reset()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), label_3, SLOT(reset()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), label_4, SLOT(reset()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), label_6, SLOT(reset()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), label_7, SLOT(reset()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), label_8, SLOT(reset()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), label_11, SLOT(reset()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), label_15, SLOT(reset()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), label_14, SLOT(reset()));
        QObject::connect(pushButton, SIGNAL(clicked()), lcdNumber_9, SLOT(incrementanumballs()));
        QObject::connect(label, SIGNAL(esquerra()), label_2, SLOT(probabilidad()));
        QObject::connect(label, SIGNAL(dreta()), label_3, SLOT(probabilidad()));
        QObject::connect(label_2, SIGNAL(esquerra()), label_4, SLOT(probabilidad()));
        QObject::connect(label_2, SIGNAL(dreta()), label_6, SLOT(probabilidad()));
        QObject::connect(label_3, SIGNAL(esquerra()), label_6, SLOT(probabilidad()));
        QObject::connect(label_3, SIGNAL(dreta()), label_7, SLOT(probabilidad()));
        QObject::connect(label_4, SIGNAL(esquerra()), label_8, SLOT(probabilidad()));
        QObject::connect(label_4, SIGNAL(dreta()), label_11, SLOT(probabilidad()));
        QObject::connect(label_6, SIGNAL(esquerra()), label_11, SLOT(probabilidad()));
        QObject::connect(label_6, SIGNAL(dreta()), label_15, SLOT(probabilidad()));
        QObject::connect(label_7, SIGNAL(esquerra()), label_15, SLOT(probabilidad()));
        QObject::connect(label_7, SIGNAL(dreta()), label_14, SLOT(probabilidad()));
        QObject::connect(pushButton, SIGNAL(clicked()), label, SLOT(jugar()));
        QObject::connect(label, SIGNAL(borrar()), label_2, SLOT(reset()));
        QObject::connect(label, SIGNAL(borrar()), label_3, SLOT(reset()));
        QObject::connect(label_2, SIGNAL(borrar()), label_4, SLOT(reset()));
        QObject::connect(label_2, SIGNAL(borrar()), label_6, SLOT(reset()));
        QObject::connect(label_3, SIGNAL(borrar()), label_6, SLOT(reset()));
        QObject::connect(label_3, SIGNAL(borrar()), label_7, SLOT(reset()));
        QObject::connect(label_4, SIGNAL(borrar()), label_8, SLOT(reset()));
        QObject::connect(label_4, SIGNAL(borrar()), label_11, SLOT(reset()));
        QObject::connect(label_7, SIGNAL(borrar()), label_14, SLOT(reset()));
        QObject::connect(label_6, SIGNAL(borrar()), label_15, SLOT(reset()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), lcdNumber_6, SLOT(reset()));
        QObject::connect(label_8, SIGNAL(esquerra()), lcdNumber, SLOT(incrementabox1()));
        QObject::connect(label_8, SIGNAL(dreta()), lcdNumber_2, SLOT(incrementabox2()));
        QObject::connect(label_11, SIGNAL(esquerra()), lcdNumber_2, SLOT(incrementabox2()));
        QObject::connect(label_11, SIGNAL(dreta()), lcdNumber_3, SLOT(incrementabox3()));
        QObject::connect(label_15, SIGNAL(esquerra()), lcdNumber_3, SLOT(incrementabox3()));
        QObject::connect(label_15, SIGNAL(dreta()), lcdNumber_4, SLOT(incrementabox4()));
        QObject::connect(label_14, SIGNAL(esquerra()), lcdNumber_4, SLOT(incrementabox4()));
        QObject::connect(label_14, SIGNAL(dreta()), lcdNumber_6, SLOT(incrementabox5()));

        QMetaObject::connectSlotsByName(Galton);
    } // setupUi

    void retranslateUi(QWidget *Galton)
    {
        Galton->setWindowTitle(QApplication::translate("Galton", "Galton", nullptr));
        pushButton->setText(QApplication::translate("Galton", "Bola", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton->setShortcut(QApplication::translate("Galton", "Alt+B", nullptr));
#endif // QT_NO_SHORTCUT
        label->setText(QApplication::translate("Galton", "-", nullptr));
        label_2->setText(QApplication::translate("Galton", "-", nullptr));
        label_3->setText(QApplication::translate("Galton", "-", nullptr));
        label_4->setText(QApplication::translate("Galton", "-", nullptr));
        label_6->setText(QApplication::translate("Galton", "-", nullptr));
        label_7->setText(QApplication::translate("Galton", "-", nullptr));
        label_8->setText(QApplication::translate("Galton", "-", nullptr));
        label_11->setText(QApplication::translate("Galton", "-", nullptr));
        label_15->setText(QApplication::translate("Galton", "-", nullptr));
        label_14->setText(QApplication::translate("Galton", "-", nullptr));
        pushButton_2->setText(QApplication::translate("Galton", "Reset", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_2->setShortcut(QApplication::translate("Galton", "Alt+R", nullptr));
#endif // QT_NO_SHORTCUT
        label_16->setText(QApplication::translate("Galton", "Total boles:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Galton: public Ui_Galton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GALTON_H
