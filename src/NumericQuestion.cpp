#include "NumericQuestion.h"

#include <cstdlib>

NumericQuestion::NumericQuestion()
{

}

bool NumericQuestion::isRightAnswer(const std::string& playerAnswer) const
{
	return std::strtod(playerAnswer.c_str(), nullptr)
		== std::strtod(this->answer.c_str(), nullptr);
}
