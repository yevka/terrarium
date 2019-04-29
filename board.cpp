#include "board.h"

CheckersBoard::CheckersBoard() {
  scene = new Scene;
  view = new GraphicsView(scene);
  view->resize(scene->width(), scene->height());
}

void CheckersBoard::setPosition(const QString &pos) { scene->setPosition(pos); }

QString CheckersBoard::getPosition() const { return position; }

void CheckersBoard::setFon(QPixmap pix) { view->setBackgroundBrush(pix); }

void CheckersBoard::setBoard(QPixmap pix) { scene->setBoard(pix); }
