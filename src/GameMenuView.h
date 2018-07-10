#ifndef GAMEMENUVIEW_H
#define GAMEMENUVIEW_H

#include <QWidget>

namespace Ui
{
	class GameMenuView;
}

/**
	The game menu. It is shown in the MainWindow's central widget when the game is in game menu
	state, according to the state machine.
**/
class GameMenuView : public QWidget
{
	Q_OBJECT

  public:
	/// Constructor
	explicit GameMenuView(QWidget* parent = nullptr);
	/// Destructor
	~GameMenuView();

  private:
	/// A record that contains the user interface designed by QtDesigner
	Ui::GameMenuView *ui;
};

#endif // GAMEMENUVIEW_H
