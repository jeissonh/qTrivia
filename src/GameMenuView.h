#ifndef GAMEMENUVIEW_H
#define GAMEMENUVIEW_H

#include <QWidget>

namespace Ui
{
	class GameMenuView;
}

class GameMenuView : public QWidget
{
	Q_OBJECT

  public:
	explicit GameMenuView(QWidget *parent = 0);
	~GameMenuView();

  private:
public: Ui::GameMenuView *ui;
};

#endif // GAMEMENUVIEW_H
