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
}

void MainWindow::showGameMenu()
{
	GameMenuView* gameMenuView = new GameMenuView(this);
	this->setCentralWidget( gameMenuView );
	this->connect( gameMenuView->ui->pushButtonQuit, &QPushButton::clicked, this, &MainWindow::close );
}
