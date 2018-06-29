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
	QDomDocument document("mydocument");
	QFile file("Trivia.xml");
	if (!file.open(QIODevice::ReadOnly))
		return 10;
	if (!document.setContent(&file)) {
		file.close();
		return 20;
	}
	file.close();

	// print out the element names of all elements that are direct children
	// of the outermost element.
	QDomElement docElem = document.documentElement();

	QDomNode n = docElem.firstChild();
	while(!n.isNull()) {
		QDomElement e = n.toElement(); // try to convert the node to an element.
		if(!e.isNull()) {
			std::cout << qPrintable(e.tagName()) << std::endl; // the node really is an element.
		}
		n = n.nextSibling();
	}
/*
	// Here we append a new element to the end of the document
	QDomElement elem = document.createElement("img");
	elem.setAttribute("src", "myimage.png");
	docElem.appendChild(elem);



	const char* const filename = "Trivia.xml";
	std::ifstream input(filename);
	if ( ! input )
		return std::cerr << "trivia: could not open " << filename << std::endl, 2;

	std::string type;
	while ( std::getline( input, type ) )
	{
		Question* question = createQuestion(type);
		if ( question )
		{
			input >> *question;
			this->questions.push_back( question );
		}
		else
			return std::cerr << "trivia: invalid question type " << type << std::endl, 3;
	}
*/
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
Question* Trivia::createQuestion(const std::string& type)
{
	// new Question(); // abstract classes could not be instanced
	if ( type == "numeric" ) return new NumericQuestion();
	if ( type == "textual" ) return new TextualQuestion();
	if ( type == "single_choice" ) return new SingleChoiceQuestion();

	return nullptr;
}
