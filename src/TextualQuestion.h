#ifndef TEXTUALQUESTION_H
#define TEXTUALQUESTION_H

#include "Question.h"

/**
	A question that expects a textual answer.
	Answers are compared ignoring case differences and leading/trailing whitespace.
*/
class TextualQuestion : public /*virtual*/ Question
{
	/// Avoid copies of objects of this class
	Q_DISABLE_COPY(TextualQuestion)

  public:
	/// Constructor
	TextualQuestion();
	/// Return true if the player answer matches the expected answer for this question
	virtual bool isRightAnswer(const QString& playerAnswer) const override;
};

#endif // TEXTUALQUESTION_H
