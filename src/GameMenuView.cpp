#include "GameMenuView.h"
#include "ui_GameMenuView.h"

GameMenuView::GameMenuView(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::GameMenuView)
{
	// Create the user interface created with QtDesiner
	this->ui->setupUi(this);

	// Try to enable the Start button when a GUI control is activated
	this->connect( ui->radioButtonSinglePlayer, &QRadioButton::clicked, this, &GameMenuView::tryEnableStartButton );
	this->connect( ui->radioButtonMultiplayer, &QRadioButton::clicked, this, &GameMenuView::tryEnableStartButton );
	this->connect( ui->radioButtonStartMatch, &QRadioButton::clicked, this, &GameMenuView::tryEnableStartButton );
	this->connect( ui->radioButtonJoinMatch, &QRadioButton::clicked, this, &GameMenuView::tryEnableStartButton );
	this->connect( ui->lineEditHostname, &QLineEdit::textChanged, this, &GameMenuView::tryEnableStartButton );
	this->connect( ui->lineEditPort, &QLineEdit::textChanged, this, &GameMenuView::tryEnableStartButton );

	// When Quit button is pressed, close the MainWindow (parent)
	this->connect( ui->pushButtonQuit, &QPushButton::clicked, parent, &QWidget::close );
}

GameMenuView::~GameMenuView()
{
	delete this->ui;
}

bool GameMenuView::canEnableStartButton() const
{
	// When we are in the initial state
	if ( this->state == GameMenuState::initial )
	{
		// A player's nickname is mandatory
		if ( ui->lineEditNickname->text().trimmed().length() <= 0 ) return false;

		// The nickname is the only data required for a single player game
		if ( ui->radioButtonSinglePlayer->isChecked() ) return true;

		// The multiplayer option is selected
		// In both, client and server the port is required
		if ( ! ( ui->lineEditPort->text().toInt() > 1024 ) ) return false;

		// In client mode we also require the hostname
		if ( ui->radioButtonJoinMatch->isChecked() && ui->lineEditHostname->text().trimmed().length() <= 0 )
			return false;

		// We do not find any subjections to disable the Start button
	}

	// For a multiplayer game, the button will managed later
	return true;
}

void GameMenuView::on_lineEditNickname_textChanged(const QString& text)
{
	Q_UNUSED(text);
	this->tryEnableStartButton();
}

void GameMenuView::tryEnableStartButton()
{
	this->ui->pushButtonStart->setEnabled( canEnableStartButton() );
}
