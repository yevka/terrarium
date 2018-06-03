#ifndef NEWGAMEFORM_H
#define NEWGAMEFORM_H

#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QDialog>

#include <QPushButton>
#include <QCheckBox>
#include <QComboBox>

#include <QGridLayout>
#include <QVBoxLayout>

#include <QRegExpValidator>

struct DataGameForm {
  bool checkRating;
  int enemy;
  int typeOfMatch;
  int timeControl;
  QString timeParty;
  int myColor;
  bool checkColorChangeParty;
  QString placement;

  DataGameForm()
      : checkRating(0),
        enemy(-1),
        typeOfMatch(-1),
        timeControl(-1),
        timeParty(""),
        myColor(-1),
        checkColorChangeParty(0),
        placement("") {}
};

class NewGameForm : public QDialog {
  Q_OBJECT
 public:
  explicit NewGameForm(QWidget* parent = 0);

  void showNewGameForm(QWidget* parent);

 signals:
  void startClicked(DataGameForm);

 public slots:
  void data();

 private:
  QLabel* rating;
  QCheckBox* checkRating;

  QLabel* enemy;
  QComboBox* comboEnemy;

  QLabel* typeOfMatch;
  QComboBox* comboTypeOfMatch;

  QLabel* timeControl;
  QComboBox* comboTimeControl;

  QLabel* timeParty;
  QLineEdit* inputTimeParty;

  QLabel* myColor;
  QComboBox* comboMyColor;

  QLabel* colorChangeParty;
  QCheckBox* checkColorChangeParty;

  QLabel* placement;
  QLineEdit* inputPlacement;

  QPushButton* start;

  QGridLayout* gridLayout;
  QVBoxLayout* vboxLayout;

  void setCentrForm(QWidget* parent);
};

#endif  // NEWGAMEFORM_H
