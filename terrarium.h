#ifndef TERRARIUM_H
#define TERRARIUM_H

#include <QWidget>
#include <QMainWindow>
#include <QTextEdit>
#include <QString>
#include <QSplitter>
#include <QColorDialog>
#include <QFontDialog>
#include <QPalette>

#include "menubar.h"
#include "board.h"
#include "newgameform.h"

class Terrarium : public QMainWindow {
  Q_OBJECT

 public:
  Terrarium(const QSize screenSize, QWidget* parent = 0);

 protected:
  // Event handlers
  void closeEvent(QCloseEvent *close) override;

 private:
  Board board;
  QTextEdit* protocolParty;
  QSplitter* splitter;
  MenuBar* menuBar;

  NewGameForm* newGameForm;

  void createMenu();

 private slots:
  // menuGame
  void newGame();
  // void analisisMode(bool isChecked);

  // menuView
  void setFon(QAction* pFon);
  void setBoard(QAction* pBoard);
  void font();
  void colorTextEdit();

  // menuAbout
  void about();

  void startClicked(DataGameForm);
};

#endif  // TERRARIUM_H
