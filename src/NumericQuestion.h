#ifndef NUMERICQUESTION_H
#define NUMERICQUESTION_H

#include "Question.h"

/**
	A question that expects a numeric answer.
	Therefore it compares the answer as a number
*/
class NumericQuestion : public Question
{
  public:
	/// Constructor
	NumericQuestion();
	/// Return true if the player answer matches the expected answer for this question
	virtual bool isRightAnswer(const QString& playerAnswer) const override;
};

#endif // NUMERICQUESTION_H
