#include "graphicsview.h"

GraphicsView::GraphicsView(QGraphicsScene *scene) : QGraphicsView(scene), scene_(scene) {
  this->setAlignment(Qt::AlignCenter);
  this->setFrameStyle(QFrame::NoFrame);
  this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  this->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
  this->setMouseTracking(true);
}

void GraphicsView::resizeEvent(QResizeEvent *event) {
  QGraphicsView::resizeEvent(event);
  fitInView(scene_->sceneRect(), Qt::KeepAspectRatio);
}
