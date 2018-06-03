#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>

class MenuBar : public QMenuBar {
  Q_OBJECT
 public:
  explicit MenuBar(QWidget* parent = 0);

 signals:
  // menuGame
  void newGame();

  // menuView
  void groupFon(QAction*);
  void groupBoard(QAction*);
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
  QAction* actionAqua;
  QAction* actionBrown;
  QAction* actionCanva;
  QAction* actionDarkBlue;
  QAction* actionGray;
  QAction* actionLightBlue;
  QAction* actionCherry;

  QActionGroup* actionGroupBoard;
  QAction* actionAshTree;
  QAction* actionAutumn;
  QAction* actionGreen;
  QAction* actionLime;
  QAction* actionMahogany;
  QAction* actionNavajoWhite;
  QAction* actionOrangeMarble;
  QAction* actionPlywood;
  QAction* actionSkyBlue;
  QAction* actionWood;

  QAction* actionFont;
  QAction* actionColorTextEdit;

  // setting
  QAction* actionSettingEngine;

  // menuAbout
  QAction* actionAbout;

  QMenu* menuFile;
  QMenu* menuView;
  QMenu* subMenuViewFon;
  QMenu* subMenuViewBoard;

  QMenu* menuGame;
  QMenu* menuAbout;

  void createAction();
  void createMenu();
};

#endif  // MENUBAR_H
