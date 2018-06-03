#ifndef BOARD_H
#define BOARD_H

#include "scene.h"
#include "graphicsview.h"

class Board {
 public:
  Board();
  GraphicsView* boardView() const { return view; }

  void setPosition(const QString& pos);
  QString getPosition() const;
  void setFon(QPixmap pix);
  void setBoard(QPixmap pix);
  void setStartTimer(int min, int sec);

 private:
  Scene* scene;
  QString position;
  GraphicsView* view;
};

#endif  // BOARD_H
