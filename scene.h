#ifndef SCENE_H
#define SCENE_H

#include <QCoreApplication>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>

#include "cell.h"
#include "info.h"

class Scene : public QGraphicsScene {
  Q_OBJECT
 public:
  explicit Scene(QObject* parent = 0);

  void setPosition(const QString& pos);
  void setBoard(QPixmap pix);
  void setStartTimer(int min, int sec);

  void addCell(Cell cell);

 protected:
  virtual void mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent);

 signals:

 public slots:

 private:
  QGraphicsPixmapItem* fonBoard;
  Cell cell[32];
  QString position;

  Info infoUp;
  Info infoDown;

  QVector<QPointF> coordinatesCells(const QPointF& startPoint,
                                    const QSize& cell);
};

#endif  // SCENE_H
