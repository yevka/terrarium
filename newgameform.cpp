#include "newgameform.h"

NewGameForm::NewGameForm(QWidget *parent) : QDialog(parent) {
  this->setWindowFilePath("Выбор конвенции");
  this->resize(257, 218);

  rating = new QLabel("На рейтинг");

  checkRating = new QCheckBox;
  checkRating->setCheckable(true);
  checkRating->setChecked(true);

  enemy = new QLabel("Противник");

  comboEnemy = new QComboBox;
  comboEnemy->addItem("Человек");
  comboEnemy->addItem("Любитель");
  comboEnemy->addItem("3 разряд");
  comboEnemy->addItem("2 разряд");
  comboEnemy->addItem("1 разряд");
  comboEnemy->addItem("КМС");
  comboEnemy->addItem("МС");
  comboEnemy->addItem("Гроссмейстер");
  comboEnemy->addItem("Водитель НЛО");

  typeOfMatch = new QLabel("Тип поединка");

  comboTypeOfMatch = new QComboBox;
  comboTypeOfMatch->addItem("1 партия");
  comboTypeOfMatch->addItem("Матч до 2");
  comboTypeOfMatch->addItem("Матч до 3");
  comboTypeOfMatch->addItem("Матч до 4");
  comboTypeOfMatch->addItem("Матч до 5");
  comboTypeOfMatch->addItem("Матч до 6");
  comboTypeOfMatch->addItem("Матч до 7");
  comboTypeOfMatch->addItem("Матч до 8");

  timeControl = new QLabel("Контроль времени");
  timeControl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  comboTimeControl = new QComboBox;
  comboTimeControl->addItem("На каждую партию");
  comboTimeControl->addItem("На весь матч");

  timeParty = new QLabel("Время");

  inputTimeParty = new QLineEdit("1+1");
  QRegExp rx("^[0-9]{1,3}[+]{1,1}[0-9]{1,3}$");
  QValidator *validator = new QRegExpValidator(rx);
  inputTimeParty->setValidator(validator);

  myColor = new QLabel("Мой цвет");

  comboMyColor = new QComboBox;
  comboMyColor->addItem("Белые");
  comboMyColor->addItem("Чёрные");

  colorChangeParty = new QLabel("Смена цвета партии");

  checkColorChangeParty = new QCheckBox;
  checkColorChangeParty->setCheckable(true);
  checkColorChangeParty->setChecked(true);

  placement = new QLabel("Расстановка");

  inputPlacement = new QLineEdit("");

  start = new QPushButton("Объявить");
  start->setCheckable(true);
  start->setChecked(false);
  connect(start, SIGNAL(pressed()), SLOT(data()));

  gridLayout = new QGridLayout;
  gridLayout->setMargin(1);
  gridLayout->setSpacing(5);

  gridLayout->addWidget(rating, 0, 0);
  gridLayout->addWidget(checkRating, 0, 1);

  gridLayout->addWidget(enemy, 1, 0);
  gridLayout->addWidget(comboEnemy, 1, 1);

  gridLayout->addWidget(typeOfMatch, 2, 0);
  gridLayout->addWidget(comboTypeOfMatch, 2, 1);

  gridLayout->addWidget(timeControl, 3, 0);
  gridLayout->addWidget(comboTimeControl, 3, 1);

  gridLayout->addWidget(timeParty, 4, 0);
  gridLayout->addWidget(inputTimeParty, 4, 1);

  gridLayout->addWidget(myColor, 5, 0);
  gridLayout->addWidget(comboMyColor, 5, 1);

  gridLayout->addWidget(colorChangeParty, 6, 0);
  gridLayout->addWidget(checkColorChangeParty, 6, 1);

  gridLayout->addWidget(placement, 7, 0);
  gridLayout->addWidget(inputPlacement, 7, 1);

  vboxLayout = new QVBoxLayout;
  vboxLayout->addLayout(gridLayout);
  vboxLayout->addWidget(start);

  this->setLayout(vboxLayout);
  setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
}

void NewGameForm::setCentrForm(QWidget *parent) {
  QSize parentSize = parent->size();
  QPoint central;
  int x = (parentSize.width() - this->width()) / 2;
  x += parent->pos().x();
  central.setX(x);

  int y = (parentSize.height() - this->height()) / 2;
  y += parent->pos().y();
  central.setY(y);

  this->move(central);
}

void NewGameForm::showNewGameForm(QWidget *parent) {
  setCentrForm(parent);
  this->show();
}

void NewGameForm::data() {
  DataGameForm data;
  data.checkRating = checkRating->isChecked();
  data.enemy = comboEnemy->count();
  data.typeOfMatch = comboTypeOfMatch->count();
  data.timeControl = comboTimeControl->count();
  data.timeParty = inputTimeParty->text();
  data.myColor = comboMyColor->count();
  data.checkColorChangeParty = checkColorChangeParty->isChecked();
  data.placement = inputPlacement->text();

  emit startClicked(data);
}
