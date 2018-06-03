#include "menubar.h"

//#include <QActionGroup>

MenuBar::MenuBar(QWidget *parent) : QMenuBar(parent) {
  createAction();
  createMenu();
}

void MenuBar::createAction() {
  // menuGame
  actionNewGame = new QAction("Новая игра", this);
  connect(actionNewGame, SIGNAL(triggered()), SIGNAL(newGame()));

  // menuView
  actionGroupFon = new QActionGroup(this);
  actionGroupFon->setExclusive(true);
  connect(actionGroupFon, SIGNAL(triggered(QAction *)), SIGNAL(groupFon(QAction *)));

  actionAqua = new QAction("Aqua", actionGroupFon);
  actionAqua->setCheckable(true);

  actionBrown = new QAction("Brown", actionGroupFon);
  actionBrown->setCheckable(true);

  actionCanva = new QAction("Canva", actionGroupFon);
  actionCanva->setCheckable(true);

  actionDarkBlue = new QAction("Dark blue", actionGroupFon);
  actionDarkBlue->setCheckable(true);
  actionDarkBlue->setChecked(true);

  actionGray = new QAction("Gray", actionGroupFon);
  actionGray->setCheckable(true);

  actionLightBlue = new QAction("Light blue", actionGroupFon);
  actionLightBlue->setCheckable(true);

  actionCherry = new QAction("Cherry", actionGroupFon);
  actionCherry->setCheckable(true);

  actionGroupBoard = new QActionGroup(this);
  actionGroupBoard->setExclusive(true);
  connect(actionGroupBoard, SIGNAL(triggered(QAction *)),
          SIGNAL(groupBoard(QAction *)));

  actionAshTree = new QAction("Ash-tree", actionGroupBoard);

  actionAutumn = new QAction("Autumn", actionGroupBoard);
  actionAutumn->setCheckable(true);

  actionGreen = new QAction("Green", actionGroupBoard);
  actionGreen->setCheckable(true);

  actionLime = new QAction("Lime", actionGroupBoard);
  actionLime->setCheckable(true);

  actionMahogany = new QAction("Mahogany", actionGroupBoard);
  actionMahogany->setCheckable(true);

  actionNavajoWhite = new QAction("Navajo white", actionGroupBoard);
  actionNavajoWhite->setCheckable(true);

  actionOrangeMarble = new QAction("Orange marble", actionGroupBoard);
  actionOrangeMarble->setCheckable(true);

  actionPlywood = new QAction("Plywood", actionGroupBoard);
  actionPlywood->setCheckable(true);
  actionPlywood->setChecked(true);

  actionSkyBlue = new QAction("Sky blue", actionGroupBoard);
  actionSkyBlue->setCheckable(true);

  actionWood = new QAction("Wood", actionGroupBoard);
  actionWood->setCheckable(true);

  actionFont = new QAction("Шрифт", this);
  connect(actionFont, SIGNAL(triggered()), SIGNAL(font()));

  actionColorTextEdit = new QAction("Цвет текст. блока", this);
  connect(actionColorTextEdit, SIGNAL(triggered()), SIGNAL(colorTextEdit()));

  // menuAbout
  actionAbout = new QAction("О программе", this);
  connect(actionAbout, SIGNAL(triggered()), SIGNAL(about()));
}

void MenuBar::createMenu() {
  menuGame = new QMenu("Игра");
  menuGame->addAction(actionNewGame);

  menuView = new QMenu("Вид");
  subMenuViewFon = new QMenu("Фон");
  subMenuViewFon->addActions(actionGroupFon->actions());
  menuView->addMenu(subMenuViewFon);

  subMenuViewBoard = new QMenu("Доска");
  subMenuViewBoard->addActions(actionGroupBoard->actions());
  menuView->addMenu(subMenuViewBoard);

  menuView->addAction(actionFont);
  menuView->addAction(actionColorTextEdit);

  menuAbout = new QMenu("О программе");
  menuAbout->addAction(actionAbout);

  this->addMenu(menuGame);
  this->addMenu(menuView);
  this->addMenu(menuAbout);
}
