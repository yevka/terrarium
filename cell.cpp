#include "cell.h"

Cell::Cell() {
  ws = new QGraphicsPixmapItem;
  ws->setShapeMode(QGraphicsPixmapItem::MaskShape);
  ws->setTransformationMode(Qt::SmoothTransformation);
  ws->setPixmap(QPixmap(":/Skin/draughts/ws.png"));
  ws->setVisible(false);

  wd = new QGraphicsPixmapItem;
  wd->setShapeMode(QGraphicsPixmapItem::MaskShape);
  wd->setTransformationMode(Qt::SmoothTransformation);
  wd->setPixmap(QPixmap(":/Skin/draughts/wd.png"));
  wd->setVisible(false);

  bs = new QGraphicsPixmapItem;
  bs->setShapeMode(QGraphicsPixmapItem::MaskShape);
  bs->setTransformationMode(Qt::SmoothTransformation);
  bs->setPixmap(QPixmap(":/Skin/draughts/bs.png"));
  bs->setVisible(false);

  bd = new QGraphicsPixmapItem;
  bd->setShapeMode(QGraphicsPixmapItem::MaskShape);
  bd->setTransformationMode(Qt::SmoothTransformation);
  bd->setPixmap(QPixmap(":/Skin/draughts/bd.png"));
  bd->setVisible(false);

  lastMove = new QGraphicsPixmapItem;
  lastMove->setShapeMode(QGraphicsPixmapItem::MaskShape);
  lastMove->setTransformationMode(Qt::SmoothTransformation);
  lastMove->setPixmap(QPixmap(":/Skin/draughts/lastMove.png"));
  lastMove->setVisible(false);

  yellowFrame = new QGraphicsPixmapItem;
  yellowFrame->setShapeMode(QGraphicsPixmapItem::MaskShape);
  yellowFrame->setTransformationMode(Qt::SmoothTransformation);
  yellowFrame->setPixmap(QPixmap(":/Skin/draughts/yellowFrame.png"));
  yellowFrame->setVisible(false);
}

void Cell::setPos(const QPointF &pos) {
  ws->setPos(pos);
  wd->setPos(pos);
  bs->setPos(pos);
  bd->setPos(pos);
  lastMove->setPos(pos);
  yellowFrame->setPos(pos);
}

void Cell::setCell(const uchar &cell) {
  if (cell == 'W') {
    ws->setVisible(false);
    wd->setVisible(true);
    bs->setVisible(false);
    bd->setVisible(false);
  }
  else if (cell == 'w') {
    ws->setVisible(true);
    wd->setVisible(false);
    bs->setVisible(false);
    bd->setVisible(false);
  }
  else if (cell == 'B') {
    ws->setVisible(false);
    wd->setVisible(false);
    bs->setVisible(false);
    bd->setVisible(true);
  }
  else if (cell == 'b') {
    ws->setVisible(false);
    wd->setVisible(false);
    bs->setVisible(true);
    bd->setVisible(false);
  }
  else if (cell == '.') {
    ws->setVisible(false);
    wd->setVisible(false);
    bs->setVisible(false);
    bd->setVisible(false);
  }
}

void Cell::setLastMove(bool val) {
  lastMove->setVisible(val);
}

void Cell::setYellowFrame(bool val) {
  yellowFrame->setVisible(val);
}

bool Cell::isLastMove() const { return lastMove->isVisible(); }

bool Cell::isYellowFrame() const { return yellowFrame->isVisible(); }

QPointF Cell::mapFromScene(const QPointF &point) const {
  return ws->mapFromScene(point);
}

bool Cell::contains(const QPointF &point) const { return ws->contains(point); }
