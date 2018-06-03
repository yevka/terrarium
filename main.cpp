#include "terrarium.h"

#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  QRect d = QApplication::desktop()->availableGeometry();
  int width = d.width();
  int height = d.height();

  Terrarium terrarium(QSize(width, height));
  terrarium.show();

  return a.exec();
}
