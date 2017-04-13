/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *s_mainWindowGridLayout;
    QSpacerItem *horizontalSpacer;
    QGroupBox *s_drawGB;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *m_rain;
    QRadioButton *m_snow;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QFrame *line_5;
    QLabel *label_3;
    QSlider *m_windSpeed;
    QFrame *line_6;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QRadioButton *m_north;
    QRadioButton *m_east;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *m_south;
    QRadioButton *m_west;
    QFrame *line_7;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *m_scene1;
    QRadioButton *m_scene2;
    QRadioButton *m_scene3;
    QFrame *line_8;
    QFrame *line_2;
    QLabel *label_2;
    QLabel *label_6;
    QSlider *weatherStrength;
    QFrame *line_9;
    QFrame *line;
    QFrame *line_3;
    QSlider *m_heaviness;
    QFrame *line_4;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(972, 678);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        s_mainWindowGridLayout = new QGridLayout(centralwidget);
        s_mainWindowGridLayout->setObjectName(QStringLiteral("s_mainWindowGridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        s_mainWindowGridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        s_drawGB = new QGroupBox(centralwidget);
        s_drawGB->setObjectName(QStringLiteral("s_drawGB"));
        gridLayout_2 = new QGridLayout(s_drawGB);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        m_rain = new QRadioButton(s_drawGB);
        m_rain->setObjectName(QStringLiteral("m_rain"));

        verticalLayout->addWidget(m_rain);

        m_snow = new QRadioButton(s_drawGB);
        m_snow->setObjectName(QStringLiteral("m_snow"));

        verticalLayout->addWidget(m_snow);


        gridLayout_2->addLayout(verticalLayout, 2, 0, 1, 1);

        groupBox = new QGroupBox(s_drawGB);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        line_5 = new QFrame(groupBox);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_5, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        m_windSpeed = new QSlider(groupBox);
        m_windSpeed->setObjectName(QStringLiteral("m_windSpeed"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_windSpeed->sizePolicy().hasHeightForWidth());
        m_windSpeed->setSizePolicy(sizePolicy);
        m_windSpeed->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(m_windSpeed, 2, 0, 1, 1);

        line_6 = new QFrame(groupBox);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_6, 3, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_north = new QRadioButton(groupBox);
        m_north->setObjectName(QStringLiteral("m_north"));

        horizontalLayout->addWidget(m_north);

        m_east = new QRadioButton(groupBox);
        m_east->setObjectName(QStringLiteral("m_east"));

        horizontalLayout->addWidget(m_east);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        m_south = new QRadioButton(groupBox);
        m_south->setObjectName(QStringLiteral("m_south"));

        horizontalLayout_2->addWidget(m_south);

        m_west = new QRadioButton(groupBox);
        m_west->setObjectName(QStringLiteral("m_west"));

        horizontalLayout_2->addWidget(m_west);


        gridLayout->addLayout(horizontalLayout_2, 6, 0, 1, 1);

        line_7 = new QFrame(groupBox);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_7, 7, 0, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 8, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        m_scene1 = new QRadioButton(groupBox);
        m_scene1->setObjectName(QStringLiteral("m_scene1"));

        verticalLayout_2->addWidget(m_scene1);

        m_scene2 = new QRadioButton(groupBox);
        m_scene2->setObjectName(QStringLiteral("m_scene2"));

        verticalLayout_2->addWidget(m_scene2);

        m_scene3 = new QRadioButton(groupBox);
        m_scene3->setObjectName(QStringLiteral("m_scene3"));

        verticalLayout_2->addWidget(m_scene3);


        gridLayout->addLayout(verticalLayout_2, 9, 0, 1, 1);

        line_8 = new QFrame(groupBox);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_8, 10, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 11, 0, 1, 1);

        line_2 = new QFrame(s_drawGB);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_2, 10, 0, 1, 1);

        label_2 = new QLabel(s_drawGB);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label_6 = new QLabel(s_drawGB);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 8, 0, 1, 1);

        weatherStrength = new QSlider(s_drawGB);
        weatherStrength->setObjectName(QStringLiteral("weatherStrength"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(weatherStrength->sizePolicy().hasHeightForWidth());
        weatherStrength->setSizePolicy(sizePolicy1);
        weatherStrength->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(weatherStrength, 6, 0, 1, 1);

        line_9 = new QFrame(s_drawGB);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_9, 7, 0, 1, 1);

        line = new QFrame(s_drawGB);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 12, 0, 1, 1);

        line_3 = new QFrame(s_drawGB);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_3, 3, 0, 1, 1);

        m_heaviness = new QSlider(s_drawGB);
        m_heaviness->setObjectName(QStringLiteral("m_heaviness"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(m_heaviness->sizePolicy().hasHeightForWidth());
        m_heaviness->setSizePolicy(sizePolicy2);
        m_heaviness->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(m_heaviness, 9, 0, 1, 1);

        line_4 = new QFrame(s_drawGB);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_4, 0, 0, 1, 1);

        label = new QLabel(s_drawGB);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 4, 0, 1, 1);


        s_mainWindowGridLayout->addWidget(s_drawGB, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 972, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Rain-Snow Simulation", Q_NULLPTR));
        s_drawGB->setTitle(QApplication::translate("MainWindow", "Basic Controls", Q_NULLPTR));
        m_rain->setText(QApplication::translate("MainWindow", "Rain", Q_NULLPTR));
        m_snow->setText(QApplication::translate("MainWindow", "Snow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Interactive Controls", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Wind Strength", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Wind Direction", Q_NULLPTR));
        m_north->setText(QApplication::translate("MainWindow", "North", Q_NULLPTR));
        m_east->setText(QApplication::translate("MainWindow", "East", Q_NULLPTR));
        m_south->setText(QApplication::translate("MainWindow", "South", Q_NULLPTR));
        m_west->setText(QApplication::translate("MainWindow", "West", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Interaction with Objects", Q_NULLPTR));
        m_scene1->setText(QApplication::translate("MainWindow", "Scene 1", Q_NULLPTR));
        m_scene2->setText(QApplication::translate("MainWindow", "Scene 2", Q_NULLPTR));
        m_scene3->setText(QApplication::translate("MainWindow", "Scene 3", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Choose Simulation", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Number of Particles", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Speed of Weather", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
