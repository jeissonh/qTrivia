#include <cstdlib>

#include "SingleChoiceQuestion.h"

SingleChoiceQuestion::SingleChoiceQuestion()
{

}

bool SingleChoiceQuestion::isRightAnswer(const std::string& playerAnswer) const
{
	return std::strtol(playerAnswer.c_str(), nullptr, 10)
			== std::strtol(this->answer.c_str(), nullptr, 10);
}

std::istream& SingleChoiceQuestion::read(std::istream& in, bool skipEmptyLine)
{
	(void)skipEmptyLine;
	Question::read(in, false);

	std::string choice;
	while ( std::getline(in, choice) && choice.length() > 0 )
		this->choices.push_back(choice);

	return in;
}

void SingleChoiceQuestion::print(std::ostream& out) const
{
	Question::print(out);
	for ( size_t index = 0; index < this->choices.size(); ++index )
		out << (index + 1) << ". " << this->choices[index] << std::endl;
}
