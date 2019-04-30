#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>

class GraphicsView : public QGraphicsView {
 public:
  GraphicsView(QGraphicsScene *scene);

 private:
  QGraphicsScene *scene_;

 private:
  void resizeEvent(QResizeEvent *event) override;
};

#endif  // GRAPHICSVIEW_H
