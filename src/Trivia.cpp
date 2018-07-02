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
	// Open the question file as a Qt resource
	const char* const filename = ":/Trivia.xml";
	QFile file(filename);
	if ( ! file.open(QIODevice::ReadOnly) )
		return std::cerr << "qTrivia: could not open " << filename << std::endl, 2;

	// Parse the question file as an XML document
	QDomDocument document("trivia");
	if ( ! document.setContent( &file ) )
	{
		file.close();
		return std::cerr << "qTrivia: invalid questions files " << filename << std::endl, 3;
	}
	file.close();

	// Load each question from the document and fill the questions array
	return loadQuestions(document.documentElement());
}

int Trivia::loadQuestions(const QDomElement& rootElement)
{
	// Load each question from the document
	for ( QDomElement element = rootElement.firstChildElement(); ! element.isNull(); element = element.nextSiblingElement() )
	{
		// Only <question> elements are allowed to be children of the <trivia> root element
		if ( element.tagName() == "question" )
		{
			// Use the type attribute required to create a question object
			// <question type="single_choice">
			const QString& type = element.attribute("type");
			Question* question = createQuestion(type);

			// If the question type was valid, load the rest of the question from the element
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
		else
		{
			return std::cerr << "trivia: invalid element type " << qPrintable(element.tagName()) << std::endl, 4;
		}
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
	size_t index = std::rand() % this->questions.size();
	if ( (*this->questions[index]).ask() )
		++this->score;
	return std::cin.good();
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
