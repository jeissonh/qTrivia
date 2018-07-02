#include "NumericQuestion.h"

NumericQuestion::NumericQuestion()
{
}

bool NumericQuestion::isRightAnswer(const QString& playerAnswer) const
{
	return playerAnswer.toDouble() == this->answer.toDouble();
}
