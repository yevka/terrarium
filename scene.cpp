#include "scene.h"
#include <QGraphicsRectItem>
#include <QDebug>

Scene::Scene(QObject* parent) : QGraphicsScene(parent) {
  // android
  // QString dir = "assets:";

  fonBoard = new QGraphicsPixmapItem;
  // fonBoard->setPixmap(QPixmap(":/Skin/background board/lightwood.jpg"));

  this->addItem(fonBoard);

  this->addPixmap(QPixmap(":/Skin/board/board0.png"));
  QVector<QPointF> coordinates =
      coordinatesCells(QPointF(52.0, 52.0), QSize(87, 87));

  for (int i = 0; i < 32; ++i) {
    cell[i].setPos(coordinates[i]);
    this->addCell(cell[i]);
  }

  position = "";

  infoUp.nickname->setPos(790.0, 0.0);
  infoUp.nickname->setTextWidth(120.0);
  infoUp.nickname->setHtml("<p align=\"center\">User1");

  infoUp.avatar->setPixmap(QPixmap(":/Skin/default avatar/coat.png"));
  infoUp.avatar->setScale(1.30);
  infoUp.avatar->setPos(819.0, 28.0);

  infoUp.timer->setPos(805.0, 87.0);

  infoUp.score->setPlainText("1");
  infoUp.score->setPos(839.0, 122.0);

  infoUp.priority->setPixmap(QPixmap(":/Skin/priority/priorityUp.png"));
  infoUp.priority->setPos(839.0, 155.0);

  infoDown.nickname->setPos(790.0, 771.0);
  infoDown.nickname->setTextWidth(120.0);
  infoDown.nickname->setHtml("<p align=\"center\">User2");

  infoDown.avatar->setPixmap(QPixmap(":/Skin/default avatar/coat.png"));
  infoDown.avatar->setScale(1.30);
  infoDown.avatar->setPos(819.0, 710.0);

  infoDown.timer->setPos(805.0, 667.0);

  infoDown.score->setPlainText("2");
  infoDown.score->setPos(839.0, 647.0);

  infoDown.priority->setPixmap(QPixmap(":/Skin/priority/priorityDown.png"));
  infoDown.priority->setPos(839.0, 622.0);

  this->addItem(infoUp.nickname);
  this->addItem(infoUp.avatar);
  this->addItem(infoUp.timer);
  this->addItem(infoUp.score);
  this->addItem(infoUp.priority);

  this->addItem(infoDown.nickname);
  this->addItem(infoDown.avatar);
  this->addItem(infoDown.timer);
  this->addItem(infoDown.score);
  this->addItem(infoDown.priority);

  setPosition(position);
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
  if (pos.size() < 32 || pos.size() > 32) {
    return;
  }

  position = pos;

  for (short i = 0; i < 32; ++i) {
    if (pos[i].cell() == 'W') {
      cell[i].setCell("W");
    }

    if (pos[i].cell() == 'w') {
      cell[i].setCell("w");
    }

    if (pos[i].cell() == 'B') {
      cell[i].setCell("B");
    }

    if (pos[i].cell() == 'b') {
      cell[i].setCell("b");
    }

    if (pos[i].cell() == '.') {
      cell[i].setCell(".");
    }
  }
}

void Scene::setBoard(QPixmap pix) {
  fonBoard->setPixmap(pix);
}

void Scene::setStartTimer(int min, int sec) {
  QString m;
  if (min < 10)
    m = "0" + QString::number(min);
  else
    m = QString::number(min);

  QString s;
  if (sec < 10)
    s = "0" + QString::number(sec);
  else
    s = QString::number(sec);

  infoUp.timer->setPlainText(m + ":" + s);
  infoDown.timer->setPlainText(m + ":" + s);
}

void Scene::addCell(Cell cell) {
  QVector<QGraphicsPixmapItem*> items = cell.getItems();
  for (int i = 0; i < items.size(); ++i) {
    this->addItem(items[i]);
  }
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent) {
  /*
   00  01  02  03
     04  05  06  07
   08  09  10  11
     12  13  14  15
   16  17  18  19
     20  21  22  23
   24  25  26  27
     28  29  30  31
 */

  if (mouseEvent->button() == Qt::LeftButton) {
    //        QGraphicsPixmapItem *item = dynamic_cast <QGraphicsPixmapItem*> (
    //        this->itemAt(mouseEvent->scenePos(), QTransform()));
    //        if(item != 0) {
    //            qDebug() << "True";
    //            this->addRect(item->sceneBoundingRect().toRect(),
    //                          QPen(Qt::red, 5));
    //        } else {
    //            qDebug() << "False";
    //        }

    // RulesRussianDraughts rules;
    // rules.posToboard(position);

    for (int i = 0; i < 32; ++i) {
      QPointF point = cell[i].mapFromScene(mouseEvent->scenePos());
      bool contains = cell[i].contains(point);
      if (contains) {
        if (!cell[i].isYellowFrame())
          cell[i].setYellowFrame(true);
        break;
      }
    }
  }
}
