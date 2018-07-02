#ifndef QUESTION_H
#define QUESTION_H

#include <istream>
#include <limits>
#include <string>

#include <QDomElement>

class Question
{
  protected:
	QString text;
	QString answer;

  public:
	Question();
	virtual ~Question() { }
#if 0
	friend std::istream& operator>>(std::istream& in, Question& question)
	{
		return question.read(in, true);
	}

	virtual std::istream& read(std::istream& in, bool skipEmptyLine)
	{
		std::getline(in, this->text);
		std::getline(in, this->answer);

		if ( skipEmptyLine )
			in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//std::string dummy;
		//std::getline(in, dummy);
		return in;
	}
#endif
	virtual bool loadFrom(const QDomElement& element)
	{
		const QDomElement& textElement = element.firstChildElement("text");
		if ( textElement.isNull() )
			return false;
		this->text = textElement.toText().data();

		const QDomElement& answerElement = element.firstChildElement("answer");
		if ( answerElement.isNull() )
			return false;
		this->answer = answerElement.toText().data();

		return true;
	}

#if 0
	friend std::ostream& operator<<(std::ostream& out, const Question& question)
	{
		return out << '{' << question.text << "}[" << question.answer << ']';
	}

	virtual void (std::ostream& out) const;
#endif
	bool ask();
	virtual bool isRightAnswer(const std::string& playerAnswer) const = 0;
};

#endif // QUESTION_H
