#include "scene.h"
#include <QGraphicsSceneMouseEvent>

Scene::Scene(QObject* parent) : QGraphicsScene(parent) {
  checkerBoard = new QGraphicsPixmapItem(QPixmap(":/Skin/board/board0.png"));
  fonBoard = new QGraphicsPixmapItem();
  this->addItem(fonBoard);
  this->addItem(checkerBoard);
  QVector<QPointF> coordinates = coordinatesCells(QPointF(52.0, 52.0), QSize(87, 87));
  for (int i = 0; i < 32; ++i) {
    cell[i].setPos(coordinates[i]);
    this->addCell(cell[i]);
  }
}

QVector<QPointF> Scene::coordinatesCells(const QPointF& startPoint,
                                         const QSize& cell) {
  QVector<QPointF> coordinates;
  coordinates.reserve(32);
  QPointF start(startPoint.x(), startPoint.y());
  for (int i = 1; i <= 8; ++i) {
    start.setX(startPoint.x());
    for (int j = 0; j < 4; ++j) {
      if (i % 2) {
        start += QPointF(cell.width(), 0.0);
        if (j > 0) {
          start += QPointF(cell.width(), 0.0);
        }
        coordinates.push_back(start);
      }
      if (!(i % 2)) {
        if (j > 0) {
          start += QPointF(cell.width() * 2.0, 0.0);
        }
        coordinates.push_back(start);
      }
    }
    start += QPointF(0.0, cell.width());
  }
  return coordinates;
}

void Scene::setPosition(const QString& pos) {
  position = pos;
  for (short i = 0; i < 32; ++i) {
    cell[i].setCell(pos.at(i).cell());
  }
}

void Scene::setBoard(QPixmap pix) {
  fonBoard->setPixmap(pix);
}

void Scene::addCell(Cell cell) {
  QVector<QGraphicsPixmapItem*> items = cell.getItems();
  for (int i = 0; i < items.size(); ++i) {
    this->addItem(items[i]);
  }
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent) {
  if (mouseEvent->button() == Qt::LeftButton) {
    for (int i = 0; i < 32; ++i) {
      QPointF point = cell[i].mapFromScene(mouseEvent->scenePos());
      bool contains = cell[i].contains(point);
      if (contains) {
        // move generator
      }
    }
  }
}
