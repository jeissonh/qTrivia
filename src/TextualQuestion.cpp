#include "TextualQuestion.h"

#include <cctype>

TextualQuestion::TextualQuestion()
{

}

bool TextualQuestion::isRightAnswer(const std::string& playerAnswer) const
{
	// ToDo: trim both answers

	if ( playerAnswer.length() != this->answer.length() )
		return false;

	for ( size_t index = 0; index < playerAnswer.length(); ++index )
		if ( std::tolower(playerAnswer[index]) != std::tolower(this->answer[index]) )
			return false;

	return true;
}
