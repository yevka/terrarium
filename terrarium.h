#ifndef TERRARIUM_H
#define TERRARIUM_H

#include <QMainWindow>

#include "menubar.h"
#include "board.h"

QT_BEGIN_NAMESPACE
class QTextEdit;
class QSplitter;
class QAction;
QT_END_NAMESPACE

class Terrarium : public QMainWindow {
  Q_OBJECT

 public:
  Terrarium(const QSize screenSize, QWidget* parent = nullptr);

 protected:
  void closeEvent(QCloseEvent *) override;

 private:
  CheckersBoard board;
  QTextEdit* protocolParty;
  QSplitter* splitter;
  MenuBar* menuBar;

  void createMenu();

 private slots:
  void newGame();

  void setFon(QAction* pFon);
  void setBoard(QAction* pBoard);
  void font();
  void colorTextEdit();

  void about();
};

#endif  // TERRARIUM_H
