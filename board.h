#ifndef BOARD_H
#define BOARD_H

#include "scene.h"
#include "graphicsview.h"

class CheckersBoard {
 public:
  CheckersBoard();
  GraphicsView* boardView() const { return view; }

  void setPosition(const QString& pos);
  QString getPosition() const;
  void setFon(QPixmap pix);
  void setBoard(QPixmap pix);

 private:
  Scene* scene;
  QString position;
  GraphicsView* view;
};

#endif  // BOARD_H
