/// @file MainWindow.h
/// @brief User interface window
/// @author Edina Morris
/// @version 1.0
/// @date 04/05/17

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QMainWindow>
#include "NGLScene.h"

namespace Ui
{
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private:
  Ui::MainWindow *m_ui;
  /// @brief our openGL widget
  NGLScene *m_gl;
  /// @brief event used everytime user presses a key
  /// @param [in] _event the keyboard event
  void keyPressEvent(QKeyEvent *_event);
};

#endif // MAINWINDOW_H_
