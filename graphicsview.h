#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>

class GraphicsView : public QGraphicsView {
 public:
  GraphicsView(QGraphicsScene *scene);

 private:
  QGraphicsScene *scene_;

 protected:
  virtual void resizeEvent(QResizeEvent *event);
};

#endif  // GRAPHICSVIEW_H
