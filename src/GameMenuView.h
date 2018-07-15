#ifndef GAMEMENUVIEW_H
#define GAMEMENUVIEW_H

#include <QWidget>

namespace Ui
{
	class GameMenuView;
}

/**
	The states of the game menu before a game starts
*/
enum class GameMenuState
{
	initial,
	waitingForClients,
	connectingToServer,
};

/**
	The game menu. It is shown in the MainWindow's central widget when the game is in game menu
	state, according to the state machine.
**/
class GameMenuView : public QWidget
{
	Q_OBJECT

  private:
	/// A record that contains the user interface designed by QtDesigner
	Ui::GameMenuView* ui = nullptr;
	/// The state of the game menu view
	GameMenuState state = GameMenuState::initial;

  public:
	/// Constructor
	explicit GameMenuView(QWidget* parent = nullptr);
	/// Destructor
	virtual ~GameMenuView();
	/// Returns true if the conditions to enable the Start button are met
	bool canEnableStartButton() const;

  private slots:
	/// Called each time the user changes the nickname text in order to enable the Start button
	void on_lineEditNickname_textChanged(const QString &text);
	/// If the conditions to enable the Start button are met, enables it
	void tryEnableStartButton();
};

#endif // GAMEMENUVIEW_H
