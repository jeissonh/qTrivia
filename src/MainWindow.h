#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

class Question;

enum class GameState
{
	unknown, // = 0
	gameMenu,
	askQuestion,
	answer,
	statistics
};

class MainWindow : public QMainWindow
{
	Q_OBJECT
	Q_DISABLE_COPY(MainWindow)

  private:
	GameState state = GameState::unknown;
	const QVector<Question*>& questions;

  public:
	explicit MainWindow(const QVector<Question*>& questions, QWidget* parent = nullptr);
	virtual ~MainWindow();

  protected:
	void buildInterface();
	void showGameMenu();
};

#endif // MAINWINDOW_H
