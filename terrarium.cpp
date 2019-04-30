#include "terrarium.h"
#include <QTextEdit>
#include <QString>
#include <QSplitter>
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

  board.setBoard(QPixmap(":/Skin/background board/lightwood.jpg"));
  board.setPosition("bbbbbbbbbbbb........wwwwwwwwwwww");

  QString party = "Протокол партии:\r\n\r\n";

  protocolParty = new QTextEdit;
  QPalette pallete = protocolParty->palette();
  QColor color; color.setRgb(75, 116, 155);
  pallete.setColor(QPalette::Base, color);
  protocolParty->setPalette(pallete);
  protocolParty->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
  protocolParty->setMinimumWidth(150);
  protocolParty->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  protocolParty->setAlignment(Qt::AlignCenter);
  protocolParty->setReadOnly(true);
  QFont font("MS Shell Dlg 2", 16, QFont::Bold);
  font.setUnderline(true);
  protocolParty->setFont(font);
  protocolParty->setTextColor(Qt::white);
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
  connect(menuBar, SIGNAL(newGame()), SLOT(newGame()));
  connect(menuBar, SIGNAL(font()), SLOT(font()));
  connect(menuBar, SIGNAL(about()), SLOT(about()));
}

void Terrarium::newGame() {

}

void Terrarium::font() {
  bool ok = false;
  QFont font = QFontDialog::getFont(&ok, protocolParty->font());
  if (ok) {
    protocolParty->setFont(font);
  }
}

void Terrarium::about() {
  // todo
}

void Terrarium::closeEvent(QCloseEvent *) {
  // todo
}
