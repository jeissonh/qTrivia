#ifndef SINGLECHOICEQUESTION_H
#define SINGLECHOICEQUESTION_H

#include <vector>

#include "Question.h"

class SingleChoiceQuestion : public Question
{
  protected:
	std::vector<std::string> choices;

  public:
	SingleChoiceQuestion();
	virtual bool isRightAnswer(const std::string& playerAnswer) const override;
	virtual std::istream& read(std::istream& in, bool skipEmptyLine) override;
	virtual void print(std::ostream& out) const override;
};

#endif // SINGLECHOICEQUESTION_H
