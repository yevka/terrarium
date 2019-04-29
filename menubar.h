#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>

class MenuBar : public QMenuBar {
  Q_OBJECT
 public:
  explicit MenuBar(QWidget* parent = nullptr);

 signals:
  // menuGame
  void newGame();

  // menuView
  void groupFon(QAction*);
  void font();
  void colorTextEdit();

  // menuAbout
  void about();

 public slots:

 private:
  // menuGame
  QAction* actionNewGame;

  // menuView
  QActionGroup* actionGroupFon;
  QAction* actionDarkBlue;
  QAction* actionLightBlue;

  QAction* actionFont;
  QAction* actionColorTextEdit;

  // menuAbout
  QAction* actionAbout;

  QMenu* menuFile;
  QMenu* menuView;
  QMenu* subMenuViewFon;

  QMenu* menuGame;
  QMenu* menuAbout;

  void createAction();
  void createMenu();
};

#endif  // MENUBAR_H
