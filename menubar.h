#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>

class MenuBar : public QMenuBar {
  Q_OBJECT
 public:
  explicit MenuBar(QWidget* parent = nullptr);

 signals:
  void newGame();
  void font();
  void about();

 public slots:

 private:
  QAction* actionNewGame;
  QAction* actionFont;
  QAction* actionAbout;

  QMenu* menuFile;
  QMenu* menuView;
  QMenu* menuGame;
  QMenu* menuAbout;

  void createAction();
  void createMenu();
};

#endif  // MENUBAR_H
