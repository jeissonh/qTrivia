#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>

#include <QDomElement>

class Question
{
	/// Avoid copies of objects of this class
	Q_DISABLE_COPY(Question)

  protected:
	/// The question statement
	QString text;
	/// The right answer for this question
	QString answer;

  public:
	/// Constructor
	Question();
	/// Destructor
	virtual ~Question();
	/// Loads this question from a <question> XML element
	/// @return true on success, false if the XML is invalid
	virtual bool loadFrom(const QDomElement& element);
	/// Print the question to stdout or other file
	virtual void print(std::ostream& out) const;
	/// Asks the question to the player
	bool ask();
	/// Return true if the player answer matches the expected answer for this question
	virtual bool isRightAnswer(const QString& playerAnswer) const = 0;
};

#endif // QUESTION_H
