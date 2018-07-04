#include "GameMenuView.h"
#include "ui_GameMenuView.h"

GameMenuView::GameMenuView(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::GameMenuView)
{
	ui->setupUi(this);
}

GameMenuView::~GameMenuView()
{
	delete ui;
}
