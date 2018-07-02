#include <QDomDocument>
#include <QFile>

#include <fstream>
#include <functional>
#include <iostream>
#include <random>
#include <ctime>

#include "Trivia.h"
#include "Question.h"

Trivia::Trivia(int& argc, char* argv[])
	: QApplication(argc, argv)
{
}

Trivia::~Trivia()
{
	for ( int index = 0; index < this->questions.size(); ++index )
		delete this->questions[index];
}

int Trivia::run()
{
	if ( int result = this->loadQuestions() )
		return result;

	std::srand( std::time(nullptr) + std::clock() );
	while ( this->askQuestion() )
		;

	this->printStatistics();

	return this->exec();
}

int Trivia::loadQuestions()
{
	const char* const filename = ":/Trivia.xml";
	QFile file(filename);
	if ( ! file.open(QIODevice::ReadOnly) )
		return std::cerr << "qTrivia: could not open " << filename << std::endl, 2;

	QDomDocument document("trivia");
	if ( ! document.setContent( &file ) )
	{
		file.close();
		return std::cerr << "qTrivia: invalid questions files " << filename << std::endl, 3;
	}
	file.close();

	// print out the element names of all elements that are direct children
	// of the outermost element.
	QDomElement rootElemement = document.documentElement();

	QDomNode node = rootElemement.firstChild();
	while ( ! node.isNull() )
	{
		// Try to convert the node to an element
		QDomElement element = node.toElement();
		if ( ! element.isNull() && element.tagName() == "question" )
		{
			const QString& type = element.attribute("type");
//			std::cout << qPrintable(element.tagName()) << std::endl; // the node really is an element.
			Question* question = createQuestion(type);
			if ( question )
			{
				if ( question->loadFrom(element) )
					this->questions.push_back( question );
				else
					std::cerr << "trivia: invalid question at line " << element.lineNumber() << std::endl;
			}
			else
				return std::cerr << "trivia: invalid question type " << qPrintable(type) << std::endl, 3;
		}
		node = node.nextSibling();
	}

	return 0;
}

#if 0
	for ( size_t index = 0; index < questions.size(); ++index )
		std::cout << questions[index] << std::endl;
	std::cerr << questions.size() << " questions loaded\n";

	long seed = std::time(nullptr) + std::clock();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<size_t> distribution( 0, this->questions.size() );
	auto dice = std::bind(distribution, generator);
	//size_t index = dice();
	for (int i = 0; i < 10; ++i)
		std::cout << dice() << std::endl;
	return false;
#endif

bool Trivia::askQuestion()
{
	return false;
/*
	size_t index = std::rand() % this->questions.size();
	if ( (*this->questions[index]).ask() )
		++this->score;
	return std::cin.good();
	*/
}

void Trivia::printStatistics()
{
	std::cout << "You won " << this->score << " points\n";
}

#include "NumericQuestion.h"
#include "TextualQuestion.h"
#include "SingleChoiceQuestion.h"

// Factory method
Question* Trivia::createQuestion(const QString& type)
{
	// new Question(); // abstract classes could not be instanced
	if ( type == "numeric" ) return new NumericQuestion();
	if ( type == "textual" ) return new TextualQuestion();
	if ( type == "single_choice" ) return new SingleChoiceQuestion();

	return nullptr;
}
