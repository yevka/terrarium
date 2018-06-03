#include "graphicsview.h"

#include <QGraphicsSceneMouseEvent>

GraphicsView::GraphicsView(QGraphicsScene *scene) : QGraphicsView(scene), scene_(scene) {
  this->setAlignment(Qt::AlignCenter);
  this->setFrameStyle(QFrame::NoFrame);
  this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  this->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
}

void GraphicsView::resizeEvent(QResizeEvent *) {
  fitInView(scene_->sceneRect(), Qt::KeepAspectRatio);
}
