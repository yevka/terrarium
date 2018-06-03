#include "board.h"

Board::Board() {
  // desktop :\

  // android
  // QString dir = "assets:";

  scene = new Scene;
  position = "bbbbbbbbbbbb........wwwwwwwwwwww";

  /*
 default board: bbbbbbbbbbbb........wwwwwwwwwwww

   b b b b
  b b b b
   b b b b
  . . . .
   . . . .
  w w w w
   w w w w
  w w w w
  */

  view = new GraphicsView(scene);
  view->resize(scene->width(), scene->height());
  view->setBackgroundBrush(QPixmap(":/Skin/fon/Dark blue.png"));
  setPosition(position);
}

void Board::setPosition(const QString &pos) { scene->setPosition(pos); }

QString Board::getPosition() const { return position; }

void Board::setFon(QPixmap pix) { view->setBackgroundBrush(pix); }

void Board::setBoard(QPixmap pix) { scene->setBoard(pix); }

void Board::setStartTimer(int min, int sec) { scene->setStartTimer(min, sec); }
