#include <QTextStream>

#include "Question.h"

Question::Question()
{
}

Question::~Question()
{
}

bool Question::loadFrom(const QDomElement& element)
{
	// The question's text is in a child element <text>
	const QDomElement& textElement = element.firstChildElement("text");
	if ( textElement.isNull() )
		return false;
	this->text = textElement.firstChild().nodeValue();

	// The question's answer is in a child element <answer>
	const QDomElement& answerElement = element.firstChildElement("answer");
	if ( answerElement.isNull() )
		return false;
	this->answer = answerElement.firstChild().nodeValue();

	return true;
}

void Question::print(std::ostream& out) const
{
	out << qPrintable(this->text) << std::endl;
}

bool Question::ask()
{
	this->print(std::cout);

	QTextStream input(stdin);
	QString playerAnswer = input.readLine();
	bool correct = this->isRightAnswer(playerAnswer);
	std::cout << (correct ? "Right!\n\n" : "Wrong!\n\n");
	return correct;
}
