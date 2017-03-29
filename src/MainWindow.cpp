#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
    m_gl=new  NGLScene(this);

    m_ui->s_mainWindowGridLayout->addWidget(m_gl,0,0,2,1);

    connect(m_ui->m_rain,SIGNAL(toggled(bool)),m_gl,SLOT(toggleRain(bool)));
    connect(m_ui->m_snow,SIGNAL(toggled(bool)),m_gl,SLOT(toggleSnow(bool)));
    connect(m_ui->weatherStrength, SIGNAL(sliderMoved(int)), m_gl, SLOT(weatherStrength(int)));
    connect(m_ui->m_heaviness, SIGNAL(sliderMoved(int)), m_gl, SLOT(weatherHeaviness(int)));
    connect(m_ui->m_scene1,SIGNAL(toggled(bool)),m_gl,SLOT(toggleScene1(bool)));
    connect(m_ui->m_scene2,SIGNAL(toggled(bool)),m_gl,SLOT(toggleScene2(bool)));
    connect(m_ui->m_scene3,SIGNAL(toggled(bool)),m_gl,SLOT(toggleScene3(bool)));
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

void MainWindow::keyPressEvent(QKeyEvent *_event)
{
    switch(_event->key())
    {
        case Qt::Key_Escape : QGuiApplication::exit(0); break;
    }
}
