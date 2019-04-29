#include "menubar.h"

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

  actionDarkBlue = new QAction("Dark blue", actionGroupFon);
  actionDarkBlue->setCheckable(true);

  actionLightBlue = new QAction("Light blue", actionGroupFon);
  actionLightBlue->setCheckable(true);
  actionLightBlue->setChecked(true);

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

  menuView->addAction(actionFont);
  menuView->addAction(actionColorTextEdit);

  menuAbout = new QMenu("О программе");
  menuAbout->addAction(actionAbout);

  this->addMenu(menuGame);
  this->addMenu(menuView);
  this->addMenu(menuAbout);
}
