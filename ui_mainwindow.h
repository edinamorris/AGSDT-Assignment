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
#include <QtWidgets/QDial>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
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
    QGroupBox *s_drawGB;
    QGridLayout *gridLayout_2;
    QSlider *particleSize;
    QFrame *line_2;
    QLabel *label_6;
    QFrame *line_3;
    QSlider *weatherStrength;
    QFrame *line_9;
    QVBoxLayout *verticalLayout;
    QRadioButton *m_rain;
    QRadioButton *m_snow;
    QFrame *line_4;
    QFrame *line;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_3;
    QFrame *line_6;
    QLabel *label_2;
    QFrame *line_5;
    QSlider *m_heaviness;
    QSlider *m_windSpeed;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QDial *direction;
    QLabel *label_7;
    QLabel *label_8;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *m_scene1;
    QRadioButton *m_scene2;
    QRadioButton *m_scene3;
    QFrame *line_7;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(972, 824);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        s_mainWindowGridLayout = new QGridLayout(centralwidget);
        s_mainWindowGridLayout->setObjectName(QStringLiteral("s_mainWindowGridLayout"));
        s_drawGB = new QGroupBox(centralwidget);
        s_drawGB->setObjectName(QStringLiteral("s_drawGB"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(s_drawGB->sizePolicy().hasHeightForWidth());
        s_drawGB->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(s_drawGB);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        particleSize = new QSlider(s_drawGB);
        particleSize->setObjectName(QStringLiteral("particleSize"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(particleSize->sizePolicy().hasHeightForWidth());
        particleSize->setSizePolicy(sizePolicy1);
        particleSize->setMinimum(5);
        particleSize->setMaximum(11);
        particleSize->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(particleSize, 13, 0, 1, 1);

        line_2 = new QFrame(s_drawGB);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_2, 19, 0, 1, 1);

        label_6 = new QLabel(s_drawGB);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 9, 0, 1, 1);

        line_3 = new QFrame(s_drawGB);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_3, 4, 0, 1, 1);

        weatherStrength = new QSlider(s_drawGB);
        weatherStrength->setObjectName(QStringLiteral("weatherStrength"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(weatherStrength->sizePolicy().hasHeightForWidth());
        weatherStrength->setSizePolicy(sizePolicy2);
        weatherStrength->setMaximum(100);
        weatherStrength->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(weatherStrength, 7, 0, 1, 1);

        line_9 = new QFrame(s_drawGB);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_9, 8, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        m_rain = new QRadioButton(s_drawGB);
        m_rain->setObjectName(QStringLiteral("m_rain"));

        verticalLayout->addWidget(m_rain);

        m_snow = new QRadioButton(s_drawGB);
        m_snow->setObjectName(QStringLiteral("m_snow"));

        verticalLayout->addWidget(m_snow);


        gridLayout_2->addLayout(verticalLayout, 3, 0, 1, 1);

        line_4 = new QFrame(s_drawGB);
        line_4->setObjectName(QStringLiteral("line_4"));
        QSizePolicy sizePolicy3(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(line_4->sizePolicy().hasHeightForWidth());
        line_4->setSizePolicy(sizePolicy3);
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_4, 17, 0, 1, 1);

        line = new QFrame(s_drawGB);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 1, 0, 1, 1);

        label = new QLabel(s_drawGB);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 5, 0, 1, 1);

        label_4 = new QLabel(s_drawGB);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 12, 0, 1, 1);

        label_3 = new QLabel(s_drawGB);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 15, 0, 1, 1);

        line_6 = new QFrame(s_drawGB);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_6, 11, 0, 1, 1);

        label_2 = new QLabel(s_drawGB);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        line_5 = new QFrame(s_drawGB);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_5, 14, 0, 1, 1);

        m_heaviness = new QSlider(s_drawGB);
        m_heaviness->setObjectName(QStringLiteral("m_heaviness"));
        sizePolicy3.setHeightForWidth(m_heaviness->sizePolicy().hasHeightForWidth());
        m_heaviness->setSizePolicy(sizePolicy3);
        m_heaviness->setMaximum(100);
        m_heaviness->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(m_heaviness, 10, 0, 1, 1);

        m_windSpeed = new QSlider(s_drawGB);
        m_windSpeed->setObjectName(QStringLiteral("m_windSpeed"));
        sizePolicy1.setHeightForWidth(m_windSpeed->sizePolicy().hasHeightForWidth());
        m_windSpeed->setSizePolicy(sizePolicy1);
        m_windSpeed->setMaximum(100);
        m_windSpeed->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(m_windSpeed, 16, 0, 1, 1);

        groupBox = new QGroupBox(s_drawGB);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy4);
        groupBox->setMaximumSize(QSize(16777215, 185));
        groupBox->setLayoutDirection(Qt::LeftToRight);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        direction = new QDial(groupBox);
        direction->setObjectName(QStringLiteral("direction"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(100);
        sizePolicy5.setHeightForWidth(direction->sizePolicy().hasHeightForWidth());
        direction->setSizePolicy(sizePolicy5);
        direction->setMinimumSize(QSize(50, 90));
        direction->setLayoutDirection(Qt::LeftToRight);
        direction->setMaximum(360);
        direction->setPageStep(1);
        direction->setValue(0);
        direction->setSliderPosition(0);
        direction->setOrientation(Qt::Horizontal);
        direction->setInvertedAppearance(false);
        direction->setInvertedControls(false);
        direction->setWrapping(true);
        direction->setNotchesVisible(false);

        gridLayout->addWidget(direction, 5, 0, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMaximumSize(QSize(100, 20));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 6, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 18, 0, 1, 1);

        groupBox_2 = new QGroupBox(s_drawGB);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy6);
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        m_scene1 = new QRadioButton(groupBox_2);
        m_scene1->setObjectName(QStringLiteral("m_scene1"));

        verticalLayout_2->addWidget(m_scene1);

        m_scene2 = new QRadioButton(groupBox_2);
        m_scene2->setObjectName(QStringLiteral("m_scene2"));

        verticalLayout_2->addWidget(m_scene2);

        m_scene3 = new QRadioButton(groupBox_2);
        m_scene3->setObjectName(QStringLiteral("m_scene3"));

        verticalLayout_2->addWidget(m_scene3);


        verticalLayout_3->addLayout(verticalLayout_2);


        gridLayout_2->addWidget(groupBox_2, 20, 0, 1, 1);

        line_7 = new QFrame(s_drawGB);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_7, 21, 0, 1, 1);


        s_mainWindowGridLayout->addWidget(s_drawGB, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(750, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        s_mainWindowGridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

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
        label_6->setText(QApplication::translate("MainWindow", "Number of Particles", Q_NULLPTR));
        m_rain->setText(QApplication::translate("MainWindow", "Rain", Q_NULLPTR));
        m_snow->setText(QApplication::translate("MainWindow", "Snow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Speed of Weather", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Size of Particles", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Wind Strength", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Choose Simulation", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Wind Direction", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "North", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "South", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Scene Interaction", Q_NULLPTR));
        m_scene1->setText(QApplication::translate("MainWindow", "Scene 1", Q_NULLPTR));
        m_scene2->setText(QApplication::translate("MainWindow", "Scene 2", Q_NULLPTR));
        m_scene3->setText(QApplication::translate("MainWindow", "Scene 3", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
