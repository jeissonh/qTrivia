#include "TextualQuestion.h"

TextualQuestion::TextualQuestion()
{
}

bool TextualQuestion::isRightAnswer(const QString& playerAnswer) const
{
	return playerAnswer.trimmed().toLower() == this->answer.trimmed().toLower();
}
