#include "GameMenuView.h"
#include "ui_GameMenuView.h"

GameMenuView::GameMenuView(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::GameMenuView)
{
	// Create the user interface created with QtDesiner
	ui->setupUi(this);

	// When Quit button is pressed, close the MainWindow (parent)
	this->connect( ui->pushButtonQuit, &QPushButton::clicked, parent, &QWidget::close );
}

GameMenuView::~GameMenuView()
{
	delete ui;
}
