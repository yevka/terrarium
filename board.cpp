#include "board.h"
#include <QColor>

CheckersBoard::CheckersBoard() {
  scene = new Scene;
  view = new GraphicsView(scene);
  QColor color; color.setRgb(75, 116, 155);
  view->setBackgroundBrush(color);
}

void CheckersBoard::setPosition(const QString &pos) { scene->setPosition(pos); }

QString CheckersBoard::getPosition() const { return position; }

void CheckersBoard::setBoard(QPixmap pix) { scene->setBoard(pix); }
