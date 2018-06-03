#include "info.h"

#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QFont>

Info::Info() {
  nickname = new QGraphicsTextItem;
  nickname->setDefaultTextColor(QColor(255, 255, 255));
  nickname->setFont(QFont("MS Shell Dlg 2", 14, QFont::DemiBold));

  avatar = new QGraphicsPixmapItem;
  avatar->setShapeMode(QGraphicsPixmapItem::MaskShape);
  avatar->setTransformationMode(Qt::SmoothTransformation);

  timer = new QGraphicsTextItem;
  timer->setDefaultTextColor(QColor(255, 255, 255));
  timer->setFont(QFont("MS Shell Dlg 2", 22, QFont::DemiBold));

  score = new QGraphicsTextItem;
  score->setDefaultTextColor(QColor(255, 255, 0));
  score->setFont(QFont("MS Shell Dlg 2", 16, QFont::DemiBold));
  score->setVisible(false);

  priority = new QGraphicsPixmapItem;
  priority->setShapeMode(QGraphicsPixmapItem::MaskShape);
  priority->setTransformationMode(Qt::SmoothTransformation);
  priority->setVisible(false);
}
