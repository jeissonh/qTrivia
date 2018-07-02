#ifndef TRIVIA_H
#define TRIVIA_H

#include <QApplication>
#include <QVector>

#include "Common.h"

//#include "Question.h"

class Question; // Forward declaration

class Trivia : public QApplication
{
	DISABLE_COPY_CLASS(Trivia);

  private:
	QVector<Question*> questions;
	long score = 0;

  public:
	Trivia(int& argc, char *argv[]);
	~Trivia();
	int run();
	static Question* createQuestion(const QString& type);

  private:
	int loadQuestions();
	bool askQuestion();
	void printStatistics();
};

#endif // TRIVIA_H
