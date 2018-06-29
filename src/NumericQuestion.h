#ifndef NUMERICQUESTION_H
#define NUMERICQUESTION_H

#include "Question.h"

class NumericQuestion : public Question
{
  public:
	NumericQuestion();
	virtual bool isRightAnswer(const std::string& playerAnswer) const override;
};

#endif // NUMERICQUESTION_H
