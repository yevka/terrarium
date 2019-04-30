#include "menubar.h"

MenuBar::MenuBar(QWidget *parent) : QMenuBar(parent) {
  createAction();
  createMenu();
}

void MenuBar::createAction() {
  actionNewGame = new QAction("Новая игра", this);
  connect(actionNewGame, SIGNAL(triggered()), SIGNAL(newGame()));
  actionFont = new QAction("Шрифт", this);
  connect(actionFont, SIGNAL(triggered()), SIGNAL(font()));
  actionAbout = new QAction("О программе", this);
  connect(actionAbout, SIGNAL(triggered()), SIGNAL(about()));
}

void MenuBar::createMenu() {
  menuGame = new QMenu("Игра");
  menuGame->addAction(actionNewGame);
  menuView = new QMenu("Вид");
  menuView->addAction(actionFont);
  menuAbout = new QMenu("О программе");
  menuAbout->addAction(actionAbout);
  this->addMenu(menuGame);
  this->addMenu(menuView);
  this->addMenu(menuAbout);
}
