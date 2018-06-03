#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>

//class QResizeEvent;

class GraphicsView : public QGraphicsView {
 public:
  GraphicsView(QGraphicsScene *scene);

 private:
  QGraphicsScene *scene_;

 protected:
  virtual void resizeEvent(QResizeEvent *);
};

#endif  // GRAPHICSVIEW_H
