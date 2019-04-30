#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QGraphicsScene>
#include "cell.h"

class Scene : public QGraphicsScene {
 public:
  explicit Scene(QObject* parent = nullptr);

  void setPosition(const QString& pos);
  void setBoard(QPixmap pix);
  void addCell(const Cell cell);

 private:
  void mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent) override;
  void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

 private:
  QVector<QPointF> coordinatesCells(const QPointF& startPoint,
                                    const QSize& cell);

 private:
  QGraphicsPixmapItem* checkerBoard;
  QGraphicsPixmapItem* fonBoard;
  Cell cell[32];
  QString position;
};

#endif  // SCENE_H
