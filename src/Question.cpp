#include <iostream>

#include "Question.h"

Question::Question()
{

}

#if 0
void Question::print(std::ostream& out) const
{
	out << this->text << std::endl;
}
#endif

bool Question::ask()
{
	this->print(std::cout);
	std::string playerAnswer;
	std::getline(std::cin, playerAnswer);
	//bool correct = this->vtable[0](playerAnswer);
	bool correct = this->isRightAnswer(playerAnswer);
	std::cout << (correct ? "Right!\n\n" : "Wrong!\n\n");
	return correct;
}

