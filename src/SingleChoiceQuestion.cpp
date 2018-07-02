#include "SingleChoiceQuestion.h"

SingleChoiceQuestion::SingleChoiceQuestion()
{

}

bool SingleChoiceQuestion::loadFrom(const QDomElement& element)
{
	// Load the text and answer
	if ( ! Question::loadFrom(element) )
		return false;

	// The question's choices are inside a <choices> element
	const QDomElement& choicesElement = element.firstChildElement("options");
	if ( choicesElement.isNull() )
		return false;

	// Each choice is a child of the <choices> element
	for ( QDomElement choice = choicesElement.firstChildElement(); ! choice.isNull(); choice = choice.nextSiblingElement() )
	{
		if ( choice.tagName() == "option" )
			this->choices.append( choice.firstChild().nodeValue() );
		else
			return false;
	}

	return true;
}

bool SingleChoiceQuestion::isRightAnswer(const QString& playerAnswer) const
{
	return playerAnswer.toLongLong() == this->answer.toLongLong();
}

void SingleChoiceQuestion::print(std::ostream& out) const
{
	Question::print(out);
	for ( int index = 0; index < this->choices.size(); ++index )
		out << (index + 1) << ". " << qPrintable(this->choices[index]) << std::endl;
}
