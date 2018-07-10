#include <QStatusBar>

#include "MainWindow.h"
#include "GameMenuView.h"
#include "ui_GameMenuView.h"

MainWindow::MainWindow(const QVector<Question*>& questions, QWidget* parent)
	: QMainWindow(parent)
	, questions{questions}
{
	this->buildInterface();
	this->showGameMenu();
}

MainWindow::~MainWindow()
{
}

void MainWindow::buildInterface()
{
	this->setWindowTitle("qTrivia");
	this->statusBar()->showMessage(tr("%1 questions loaded").arg( this->questions.count() ));

	// For desktop, resize the main window
  #if ! defined(Q_OS_ANDROID) && ! defined(Q_OS_IOS)
	this->resize(320, 480);
  #endif
}

void MainWindow::showGameMenu()
{
	// Show a dialog to ask for player's nickname and game mode
	GameMenuView* gameMenuView = new GameMenuView(this);
	this->setCentralWidget( gameMenuView );

	// Now the application is in game menu state
	this->state = GameState::gameMenu;
}
