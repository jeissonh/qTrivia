#ifndef TEXTUALQUESTION_H
#define TEXTUALQUESTION_H

#include "Question.h"

class TextualQuestion : public /*virtual*/ Question
{
  public:
	TextualQuestion();
	virtual bool isRightAnswer(const std::string& playerAnswer) const override;
};

#endif // TEXTUALQUESTION_H
