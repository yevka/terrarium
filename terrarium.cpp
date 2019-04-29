#include "terrarium.h"
#include <QTextEdit>
#include <QString>
#include <QSplitter>
#include <QColorDialog>
#include <QFontDialog>
#include <QPalette>

Terrarium::Terrarium(const QSize screenSize, QWidget* parent) : QMainWindow(parent) {
  QSize resize = screenSize;
  resize.setHeight(resize.height() / 1.45);
  resize.setWidth(resize.width() / 1.9);
  this->resize(resize);

  QPoint central;
  central.setX((screenSize.width() - resize.width()) / 2);
  central.setY((screenSize.height() - resize.height()) / 2);
  this->move(central);

  board.setFon(QPixmap(":/Skin/fon/Light blue.png"));
  board.setBoard(QPixmap(":/Skin/background board/lightwood.jpg"));
  board.setPosition("bbbbbbbbbbbb........wwwwwwwwwwww");

  QString party = "Протокол партии:\r\n\r\n";

  protocolParty = new QTextEdit;
  QPalette pal = protocolParty->palette();
  pal.setColor(QPalette::Active, QPalette::Base, QColor(255, 230, 187));
  pal.setColor(QPalette::Inactive, QPalette::Base, QColor(255, 230, 187));
  protocolParty->setPalette(pal);

  protocolParty->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
  protocolParty->setMinimumWidth(150);
  protocolParty->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  protocolParty->setAlignment(Qt::AlignCenter);
  protocolParty->setReadOnly(true);
  protocolParty->setFont(QFont("MS Shell Dlg 2", 14, QFont::Normal));
  protocolParty->setText(party);

  splitter = new QSplitter;
  splitter->addWidget(board.boardView());
  splitter->addWidget(protocolParty);
  splitter->setStretchFactor(0, 3);
  splitter->setStretchFactor(1, 2);
  splitter->setHandleWidth(10);

  this->setCentralWidget(splitter);

  createMenu();
}

void Terrarium::createMenu() {
  menuBar = new MenuBar(this);
  this->setMenuBar(menuBar);

  // menuGame
  connect(menuBar, SIGNAL(newGame()), this, SLOT(newGame()));

  // menuView
  connect(menuBar, SIGNAL(groupFon(QAction*)), SLOT(setFon(QAction*)));
  connect(menuBar, SIGNAL(font()), SLOT(font()));
  connect(menuBar, SIGNAL(colorTextEdit()), SLOT(colorTextEdit()));

  // menuAbout
  connect(menuBar, SIGNAL(about()), SLOT(about()));
}

// menuGame
void Terrarium::newGame() {

}

// menuView
void Terrarium::setFon(QAction* pFon) {
  board.setFon(QPixmap(":/Skin/fon/" + pFon->text()));
}

void Terrarium::setBoard(QAction* pBoard) {
  board.setBoard(QPixmap(":/Skin/background board/" + pBoard->text()));
}

void Terrarium::font() {
  bool ok;
  QFont font = QFontDialog::getFont(&ok, protocolParty->font());
  if (ok) {
    protocolParty->setFont(font);
  }
}

void Terrarium::colorTextEdit() {
  QPalette pal = protocolParty->palette();
  QColor col = pal.color(QPalette::Active, QPalette::Base);
  QColor color = QColorDialog::getColor(col, this, "Select Color");
  if (color.isValid()) {
    pal.setColor(QPalette::Active, QPalette::Base, color);
    pal.setColor(QPalette::Inactive, QPalette::Base, color);
    protocolParty->setPalette(pal);
    protocolParty->setAutoFillBackground(true);
  }
}

// menuAbout
void Terrarium::about() {
  // todo
}

void Terrarium::closeEvent(QCloseEvent *) {
  // todo
}
