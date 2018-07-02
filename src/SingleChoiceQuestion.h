#ifndef SINGLECHOICEQUESTION_H
#define SINGLECHOICEQUESTION_H

#include <QtGlobal>
#include <QVector>

#include "Question.h"

/**
	Represents a question that contains numerated choices. Just one choice is the right answer.
*/
class SingleChoiceQuestion : public Question
{
	/// Avoid copies of objects of this class
	Q_DISABLE_COPY(SingleChoiceQuestion)

  protected:
	/// The list of choices. The indexes in the array are the numbers of each choice
	QVector<QString> choices;

  public:
	/// Constructor
	SingleChoiceQuestion();
	/// Return true if the player answer matches the expected answer for this question
	virtual bool isRightAnswer(const QString& playerAnswer) const override;
	/// Loads this question from a <question> XML element
	/// @return true on success, false if the XML is invalid
	virtual bool loadFrom(const QDomElement& element) override;
	/// Print the question to stdout or other file
	virtual void print(std::ostream& out) const override;
};

#endif // SINGLECHOICEQUESTION_H
