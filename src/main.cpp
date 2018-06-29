#include "MainWindow.h"
#include "Trivia.h"

int main(int argc, char *argv[])
{
	Trivia trivia(argc, argv);

	MainWindow mainWindow;
	mainWindow.show();

	return trivia.run();
}
