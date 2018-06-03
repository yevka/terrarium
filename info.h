#ifndef INFO_H
#define INFO_H

class QGraphicsTextItem;
class QGraphicsPixmapItem;

class Info {
 public:
  Info();

  QGraphicsTextItem* nickname;
  QGraphicsPixmapItem* avatar;
  QGraphicsTextItem* timer;
  QGraphicsTextItem* score;
  QGraphicsPixmapItem* priority;
};

#endif  // INFO_H
