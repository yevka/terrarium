#ifndef CELL_H
#define CELL_H

#include <QGraphicsPixmapItem>
#include <QVector>

class Cell {
 public:
  Cell();

  void setPos(const QPointF& pos);
  void setCell(const uchar& cell);

  void setLastMove(bool val);
  void setYellowFrame(bool val);

  bool isLastMove() const;
  bool isYellowFrame() const;

  QPointF mapFromScene(const QPointF& point) const;
  bool contains(const QPointF& point) const;

  QVector<QGraphicsPixmapItem*> getItems() const {
    QVector<QGraphicsPixmapItem*> items;
    items.push_back(ws);
    items.push_back(wd);
    items.push_back(bs);
    items.push_back(bd);
    items.push_back(lastMove);
    items.push_back(yellowFrame);
    return items;
  }

 private:
  QGraphicsPixmapItem* ws;
  QGraphicsPixmapItem* wd;
  QGraphicsPixmapItem* bs;
  QGraphicsPixmapItem* bd;
  QGraphicsPixmapItem* lastMove;
  QGraphicsPixmapItem* yellowFrame;
};

#endif  // CELL_H
